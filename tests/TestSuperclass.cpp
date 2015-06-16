/*
 * Using this test, I wanted to check how a protected variable from the base
 * class gets initialized.
 */ 

#include <iostream>

class Base
{
public:

  // Situation 1
  virtual void doStuff() = 0;

  // Situation 2
  //void doStuff()
  //{
  //  std::cout << "Base's doStuff()" << std::endl;
  //}

  void print()
  {
    std::cout << "uc: [" << uc << "]" << std::endl;
  }

protected:
  unsigned char uc;
};


class Sub1 : public Base
{
public:

  Sub1() : Base()
  {
    uc = '1';
  }

  void doStuff()
  {
    std::cout << "Sub1's doStuff()" << std::endl;
  }

};


class Sub2 : public Base
{
public:

  Sub2() : Base()
  {
    uc = '2';
  }

  void doStuff()
  {
    std::cout << "Sub2's doStuff()" << std::endl;
  }

};

int main()
{
  // Gives error in situation 1
  //Base b;
  //b.print();
  //b.doStuff();

  Sub1 s1;
  s1.print();
  s1.doStuff();

  Sub2 s2;
  s2.print();
  s2.doStuff();
}
