class Base {
public:
  void f() const;                // missing virtual
};

class Derived: public Base {
public:
  void f() const;                // doesn't override;
};                               // declares new nonvirtual
                                 // function
