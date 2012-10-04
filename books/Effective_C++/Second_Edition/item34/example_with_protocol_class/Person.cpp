Person * Person::makePerson(const string& name,
                            const Date& birthday,
                            const Address& addr,
                            const Country& country)
{
  return new RealPerson(name, birthday, addr, country);
}
