class Base {
public:
  virtual void f(long) const;
};

class Derived: public Base {
public:
  virtual void f(int) const;  // wrong param type;
};                            // doesn't override;
                              // declares new virtual function
