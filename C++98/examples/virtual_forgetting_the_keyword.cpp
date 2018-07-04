/**
 * Example on why the virtual keyword is necessary and what happens if you
 * forget this keyword.
 *
 * References:
 *
 *   [lazar20120617] Overriding non-virtual methods
 *     https://stackoverflow.com/questions/11067975/overriding-non-virtual-methods
 *
 *   [vig20110828] Is the "virtual" keyword optional in base classes in C++?
 *     http://stackoverflow.com/questions/7218763/is-the-virtual-keyword-optional-in-base-classes-in-c
 */

#include <string>
#include <iostream>
using namespace std;

class Employee {

  string first_name;

  public:
    Employee(const string& name);

    // QUESTION: is the 'virtual' keyword necessary?  It seems to work
    // without...
    //virtual
    void print() const;

};


Employee::Employee(const string& name)
  : first_name(name)
{
}


void Employee::print() const
{
  cout << "Employee::print() called." << endl;
}


class Manager : public Employee {

  short level;

  public:
    Manager(const string& name, int lvl);
    void print() const;
};


Manager::Manager(const string& name, int lvl)
  : Employee(name), level(lvl)
{
}


void Manager::print() const
{
  cout << "Manager::print() called." << endl;
}


int main()
{
  Employee e("Bart");
  Manager m("Jan", 2);
  e.print();
  m.print();
}
