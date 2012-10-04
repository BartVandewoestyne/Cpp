#include <iostream>
using namespace std;

class Airport { };      // represents airports

class Airplane {
public:
  virtual void fly(const Airport& destination);
};

void Airplane::fly(const Airport& destination)
{
  cout << "Airplane::fly" << endl;
  // default code for flying an airplane to
  // the given destination
}

class ModelA: public Airplane { };

class ModelB: public Airplane { };

class ModelC: public Airplane {
                               // no fly function is
                               // declared
};


int main()
{
  //Airport JFK();                 // JFK is an airport in
  Airport JFK;                   // JFK is an airport in
                                 // New York City
  Airplane *pa = new ModelC;

  pa->fly(JFK);                  // calls Airplane::fly!
}
