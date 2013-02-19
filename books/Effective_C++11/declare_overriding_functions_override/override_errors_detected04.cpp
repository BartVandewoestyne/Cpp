/**
 * Mismatched const/volatile declarations in base and derived classes.
 */

class Base {
public:
  virtual void f(int) const;
};

class Derived: public Base {
public:
  virtual void f(int) override;     // error!
};
