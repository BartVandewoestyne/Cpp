class Cat {};

class GenericStack {

protected:
  GenericStack();
  ~GenericStack();
  void push(void *object);
  void * pop();
  bool empty() const;

private:

};
 

class IntStack: private GenericStack {

public:
  void push(int *intPtr) { GenericStack::push(intPtr); }
  int * pop() { return static_cast<int*>(GenericStack::pop()); }
  bool empty() const { return GenericStack::empty(); }
};


class CatStack: private GenericStack {

public:
  void push(Cat *catPtr) { GenericStack::push(catPtr); }
  Cat * pop() { return static_cast<Cat*>(GenericStack::pop()); }
  bool empty() const { return GenericStack::empty(); }
};


template<class T>
class Stack: private GenericStack {
public:
  void push(T *objectPtr) { GenericStack::push(objectPtr); }
  T * pop() { return static_cast<T*>(GenericStack::pop()); }
  bool empty() const { return GenericStack::empty(); }
};
 

int main()
{
  //GenericStack s;                   // error! constructor is protected
   
  IntStack is;                     // fine
   
  CatStack cs;                     // also fine
}
