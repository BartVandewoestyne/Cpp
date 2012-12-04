#include <list>

class Person {
private:
    int id;
public: 
    Person(int i) : id(i) { };
    virtual ~Person() { };
    int getId() const { return id; }
};

struct Comparator {
    bool operator()(const Person* o1, const Person* o2) const {
        return o1->getId() < o2->getId();
    }
};

int main()
{
  std::list<Person*> mylist;
  mylist.push_back(new Person(1));
  mylist.push_back(new Person(2));
  mylist.sort(Comparator()); 
}
