template<class T> class Stack {

public:
  Stack();
  ~Stack();
  void push(const T& object);
  T pop();
 
  bool empty() const;             // is stack empty?

private:
  struct StackNode {              // linked list node
    T data;                       // data at this node
    StackNode *next;              // next node in list
    // StackNode constructor initializes both fields
    StackNode(const T& newData, StackNode *nextNode)
      : data(newData), next(nextNode) {}
  };
 
  StackNode *top;                 // top of stack
 
  Stack(const Stack& rhs);               // prevent copying and
  Stack& operator=(const Stack& rhs);    // assignment (see Item 27)
};


template<class T>
Stack<T>::Stack(): top(0) {}      // initialize top to null

template<class T>
void Stack<T>::push(const T& object)
{
  top = new StackNode(object, top);    // put new node at
}                                      // front of list

template<class T>
T Stack<T>::pop()
{
  StackNode *topOfStack = top;    // remember top node
  top = top->next;
 
  T data = topOfStack->data;      // remember node data
  delete topOfStack;
  return data;
}
 
template<class T>
Stack<T>::~Stack()                   // delete all in stack
{
  while (top) {
    StackNode *toDie = top;       // get ptr to top node
    top = top->next;              // move to next node
    delete toDie;                 // delete former top node
  }
}

template<class T>
bool Stack<T>::empty() const
{
  return top == 0;
}
