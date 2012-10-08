class Cat {
public:
  virtual ~Cat();                     // see Item 14
 
  virtual void eat() = 0;             // all cats eat
  virtual void sleep() = 0;           // all cats sleep
};


class Siamese: public Cat {
public:
  void eat();
  void sleep();
};


class BritishShortHairedTabby: public Cat {
public:
  void eat();
  void sleep();
};
