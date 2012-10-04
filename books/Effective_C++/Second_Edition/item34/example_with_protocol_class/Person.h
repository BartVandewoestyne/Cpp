class Person {
public:
  virtual ~Person();
   virtual string name() const = 0;
  virtual string birthDate() const = 0;
  virtual string address() const = 0;
  virtual string nationality() const = 0;

  // makePerson is now a member of the class
  static Person * makePerson(const string& name,
                             const Date& birthday,
                             const Address& addr,
                             const Country& country);

};
