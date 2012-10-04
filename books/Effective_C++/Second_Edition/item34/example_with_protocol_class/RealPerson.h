class RealPerson: public Person {
public:
  RealPerson(const string& name, const Date& birthday,
             const Address& addr, const Country& country)
  :  name_(name), birthday_(birthday),
     address_(addr), country_(country)
  {}

  virtual ~RealPerson() {}
 
  string name() const;          // implementations of
  string birthDate() const;     // these functions are not
  string address() const;       // shown, but they are
  string nationality() const;   // easy to imagine

 private:
  string name_;
  Date birthday_;
  Address address_;
  Country country_;
};
