#if defined(_MSC_VER) && !defined(__MWERKS__) && !defined(__ICL) && !defined(__COMO__) && !defined(__BORLANDC__) 
#define MSVC 
#endif 
 
#include <string> 
#include <cstdlib> 
#include <iostream> 
#include <climits> 
#include <list> 
 
  template <class T> 
  class SpecialAllocator { 
  public: 
    // type definitions 
    typedef T        value_type; 
    typedef T*       pointer; 
    typedef const T* const_pointer; 
    typedef T&       reference; 
    typedef const T& const_reference; 
#ifndef MSVC 
    typedef std::size_t    size_type; 
    typedef std::ptrdiff_t difference_type; 
#else 
    typedef size_t    size_type; 
    typedef ptrdiff_t difference_type; 
#endif 
    // rebind allocator to type U 
    template <class U> 
    struct rebind { 
      typedef SpecialAllocator<U> other; 
    }; 
 
    // return address of values 
    pointer address (reference value) const { 
      return &value; 
    } 
    const_pointer address (const_reference value) const { 
      return &value; 
    } 
 
    /* constructors and destructor 
     * - nothing to do because the allocator has no state 
     */ 
    SpecialAllocator() throw() { 
      myMagicValue = -999; 
    } 
    
    explicit SpecialAllocator(int x) { 
      myMagicValue = x; 
    } 
 
    SpecialAllocator(const SpecialAllocator& rhs) throw() { 
      myMagicValue = rhs.myMagicValue; 
    } 
#ifndef MSVC 
    template <class U> 
    SpecialAllocator (const SpecialAllocator<U>& rhs) throw() { 
      myMagicValue = rhs.myMagicValue; 
    } 
#endif 
    ~SpecialAllocator() throw() { 
    } 
 
    // return maximum number of elements that can be allocated 
    size_type max_size () const throw() { 
#if defined (MSVC) 
      return std::numeric_limits<size_t>::max() / sizeof(T); 
#else 
      return std::numeric_limits<std::size_t>::max() / sizeof(T); 
#endif 
    } 
 
    // allocate but don't initialize num elements of type T 
    pointer allocate (size_type num, const void* = 0) { 
      using namespace std; 
      // print message and allocate memory with global new 
      cerr << "Allocator: allocating " << num << " element(s)" 
                << " of size " << sizeof(T); 
      pointer ret = (pointer)(::malloc(num*sizeof(T))); 
      cerr << " at " << (void*)ret << endl; 
      cerr << "Magic Value is " << myMagicValue << endl; 
      return ret; 
    } 
 
    // initialize elements of allocated storage p with value value 
    void construct (pointer p, const T& value) { 
      // initialize memory with placement new 
      new((void*)p)T(value); 
    } 
 
    // destroy elements of initialized storage p 
    void destroy (pointer p) { 
      // destroy objects by calling their destructor 
      p->~T(); 
    } 
 
    // deallocate storage p of deleted elements 
    void deallocate (pointer p, size_type num) { 
      ::free((void*)p); 
    } 
 
    int myMagicValue; 
  }; 
 
  // return that all specializations of this allocator are interchangeable 
  template <class T1, class T2> 
  bool operator== (const SpecialAllocator<T1>&, 
                   const SpecialAllocator<T2>&) throw() { 
    return true; 
  } 
  template <class T1, class T2> 
  bool operator!= (const SpecialAllocator<T1>&, 
                   const SpecialAllocator<T2>&) throw() { 
    return false; 
  } 
 
 
#if defined(__SGI_STL_PORT) && defined(MSVC) 
// Workaround for insufficient MSVC support for member templates; 
// necessary to make the above allocator work with STLPort and MSVC 
namespace std { 
 
  template <class _Tp1, class _Tp2> 
  inline MyLib::SpecialAllocator<_Tp2>& __STL_CALL 
  __stl_alloc_rebind(MyLib::SpecialAllocator<_Tp1>& __a, const _Tp2*)  
  { return (MyLib::SpecialAllocator<_Tp2>&)(__a); } 
 
  template <class _Tp1, class _Tp2> 
  inline MyLib::SpecialAllocator<_Tp2> __STL_CALL 
  __stl_alloc_create(const MyLib::SpecialAllocator<_Tp1>&, const _Tp2*) 
  { return MyLib::SpecialAllocator<_Tp2>(); } 
 
} 
#endif 
 
/* 
int main() 
{ 
  using namespace std; 
  using namespace MyLib; 
 
  SpecialAllocator<int> allocator(44); 
  list<int, SpecialAllocator<int> > L(allocator); 
  L.resize(1); 
  return 0; 
} 
*/ 
