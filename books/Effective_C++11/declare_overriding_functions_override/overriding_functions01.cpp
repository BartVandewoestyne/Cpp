class Base {
public:
  virtual
    void f() const;
};

class Derived: public Base {
public:
  virtual           // overriding
    void f() const; // function
};
