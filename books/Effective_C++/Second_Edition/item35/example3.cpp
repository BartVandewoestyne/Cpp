class Bird {
                        // no fly function is
};                      // declared

class FlyingBird: public Bird {
public:
  virtual void fly();
};

class NonFlyingBird: public Bird {
                       // no fly function is
                       // declared
};

class Penguin: public NonFlyingBird {
                       // no fly function is
                       // declared
};

int main()
{
  Penguin p;
  //p.fly();   // error!
}
