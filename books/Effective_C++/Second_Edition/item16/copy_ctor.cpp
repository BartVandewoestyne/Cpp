class Base {
public:
  Base(int initialValue = 0): x(initialValue) {}
  Base(const Base& rhs): x(rhs.x) {}
 
private:
  int x;
};

 
class Derived: public Base {
public:
  Derived(int initialValue)
  : Base(initialValue), y(initialValue) {}
 
  //Derived(const Derived& rhs)      // erroneous copy
  //: y(rhs.y) {}                    // constructor

  Derived(const Derived& rhs)        // correct copy
  : Base(rhs), y(rhs.y) {}           // constructor
 
private:
  int y;
};
