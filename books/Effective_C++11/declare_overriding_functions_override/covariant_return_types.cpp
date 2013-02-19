class Base {
public:
  virtual Base& me();
};

class Derived: public Base {
public:
  virtual Derived& me() override;    // fine
};
