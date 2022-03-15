/*
 * Key idea:
 *
 *   - Expression templates are typically used in Linear Algebra code and
 *     avoid temporary objects.
 *
 * References:
 *
 *   [grimm20220314] Temporäre Objekte vermeiden mit Expression Templates
 *     https://www.heise.de/developer/artikel/Temporaere-Objekte-vermeiden-mit-Expression-Templates-6546908.html
 *
 *   [grimm20220308] Avoiding Temporaries with Expression Templates
 *     http://www.modernescpp.com/index.php/avoiding-temporaries-with-expression-templates
 *
 *   [vandevoorde2017] C++ Templates: The Complete Guide von David Vandervoorde, Nicolai M. Josuttis, und Douglas Gregor
 *     http://www.tmplbook.com/
 *
 *   [boost] Boost Basic Linear Algebra Library
 *     https://www.boost.org/doc/libs/1_59_0/libs/numeric/ublas/doc/index.html
 *
 *   [iglberger2014] Expression Templates Revisited - Meeting C++ 2014
 *     https://youtu.be/hfn0BVOegac
 */

#include <cassert>
#include <iostream>
#include <vector>

template<typename T, typename Cont= std::vector<T> >
class MyVector{
  Cont cont;   

public:
  // MyVector with initial size
  MyVector(const std::size_t n) : cont(n){}

  // MyVector with initial size and value
  MyVector(const std::size_t n, const double initialValue) : 
    cont(n, initialValue){}

  // Constructor for underlying container
  MyVector(const Cont& other) : cont(other){}

  // assignment operator for MyVector of different type
  template<typename T2, typename R2>                           // (3)
  MyVector& operator=(const MyVector<T2, R2>& other){
    assert(size() == other.size());
    for (std::size_t i = 0; i < cont.size(); ++i) 
      cont[i] = other[i];
    return *this;
  }

  // size of underlying container
  std::size_t size() const{ 
    return cont.size(); 
  }

  // index operators
  T operator[](const std::size_t i) const{ 
    return cont[i]; 
  }

  T& operator[](const std::size_t i){ 
    return cont[i]; 
  }

  // returns the underlying data
  const Cont& data() const{ 
    return cont; 
  }

  Cont& data(){ 
    return cont; 
  }
};

// MyVector + MyVector
template<typename T, typename Op1 , typename Op2>
class MyVectorAdd{
  const Op1& op1;
  const Op2& op2;

public:
  MyVectorAdd(const Op1& a, const Op2& b): op1(a), op2(b){}

  T operator[](const std::size_t i) const{ 
    return op1[i] + op2[i]; 
  }

  std::size_t size() const{ 
    return op1.size(); 
  }
};

// elementwise MyVector * MyVector
template< typename T, typename Op1 , typename Op2 >
class MyVectorMul {
  const Op1& op1;
  const Op2& op2;

public:
  MyVectorMul(const Op1& a, const Op2& b ): op1(a), op2(b){}

  T operator[](const std::size_t i) const{ 
    return op1[i] * op2[i]; 
  }

  std::size_t size() const{ 
    return op1.size(); 
  }
};

// function template for the + operator
template<typename T, typename R1, typename R2>
MyVector<T, MyVectorAdd<T, R1, R2> >
operator+ (const MyVector<T, R1>& a, 
           const MyVector<T, R2>& b){
  return MyVector<T, MyVectorAdd<T, R1, R2> >
    (MyVectorAdd<T, R1, R2 >(a.data(), b.data()));       // (1)
}

// function template for the * operator
template<typename T, typename R1, typename R2>
MyVector<T, MyVectorMul< T, R1, R2> >
operator* (const MyVector<T, R1>& a, 
           const MyVector<T, R2>& b)
  {
   return MyVector<T, MyVectorMul<T, R1, R2> >
     (MyVectorMul<T, R1, R2 >(a.data(), b.data()));      // (2)
}

// function template for < operator
template<typename T>
std::ostream& operator<<(std::ostream& os, 
                         const MyVector<T>& cont){  
  std::cout << '\n';
  for (int i = 0; i < cont.size(); ++i) {
    os << cont[i] << ' ';
  }
  os << '\n';
  return os;
} 

int main(){

  MyVector<double> x(10,5.4);
  MyVector<double> y(10,10.3);

  MyVector<double> result(10);
  
  result= x + x + y * y;                                                        
  
  std::cout << result << '\n';
  
}
