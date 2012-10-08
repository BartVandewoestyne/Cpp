class GenericStack {

public:
  GenericStack();
  ~GenericStack();
  void push(void *object);
  void * pop();
  bool empty() const;

private:
  struct StackNode {
    void *data;                    // data at this node
    StackNode *next;               // next node in list
    StackNode(void *newData, StackNode *nextNode)
      : data(newData), next(nextNode) {}
  };
 
  StackNode *top;                          // top of stack
 
  GenericStack(const GenericStack& rhs);   // prevent copying and
  GenericStack&                            // assignment (see
    operator=(const GenericStack& rhs);    // Item 27)
};


class IntStack {                  // interface class for ints

public:
  void push(int *intPtr) { s.push(intPtr); }
  int * pop() { return static_cast<int*>(s.pop()); }
  bool empty() const { return s.empty(); }

private:
  GenericStack s;                 // implementation
};
 

class CatStack {                  // interface class for cats

public:
  void push(Cat *catPtr) { s.push(catPtr); }
  Cat * pop() { return static_cast<Cat*>(s.pop()); }
  bool empty() const { return s.empty(); }

private:
  GenericStack s;                 // implementation

};
