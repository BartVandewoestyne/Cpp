/**
 * Attempt to override non-virtual function.
 */

class Base {
public:
  void f() const;
};

class Derived: public Base {
public:
  void f() const override;     // error!
};
