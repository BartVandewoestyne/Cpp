class Airport { };      // represents airports

class Airplane {

public:
  virtual void fly(const Airport& destination) = 0;

protected:
  void defaultFly(const Airport& destination);

};

void Airplane::defaultFly(const Airport& destination)
{
  // default code for flying an airplane to
  // the given destination
}


class ModelA: public Airplane {

public:
  virtual void fly(const Airport& destination)
  { defaultFly(destination); }

};


class ModelB: public Airplane {

public:
  virtual void fly(const Airport& destination)
  { defaultFly(destination); }

};


class ModelC: public Airplane {

public:
  virtual void fly(const Airport& destination);

};

void ModelC::fly(const Airport& destination)
{
  // code for flying a ModelC airplane to the given destination
}


