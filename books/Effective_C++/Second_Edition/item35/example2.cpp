class Bird {
public:
  virtual void fly();               // birds can fly
};

 
class Penguin:public Bird {      // penguins are birds
};
