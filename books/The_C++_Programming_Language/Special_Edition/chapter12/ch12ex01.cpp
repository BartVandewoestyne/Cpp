/**
 * (*1) Define
 *
 *        class Base {
 *        public:
 *          virtual void iam() { cout < < "Base\n"; }
 *        };
 *
 * Derive two classes from Base, and for each define iam() to write out the
 * name of the class.  Create objects of these classes and call iam() for
 * them.  Assign pointers to objects of the derived classes to Base* pointers
 * and call iam() through those pointers.
 */

#include <iostream>
using namespace std;

class Base {
  public:
    virtual // we really need this virtual!  Comment it out to see why!
    void iam() { cout << "Base\n"; }
};

class Sub1 : public Base {
  public:
    //virtual // not really necessary, but cleaner to use virtual here.
    void iam() { cout << "Sub1\n"; }
};

class Sub2 : public Base {
  public:
    //virtual // not really necessary, but cleaner to use virtual here.
    void iam() { cout << "Sub2\n"; }
};


int main()
{
  Base base;
  Sub1 sub1;
  Sub2 sub2;

  base.iam();
  sub1.iam();
  sub2.iam();

  Base *bp1, *bp2;
  Sub1 *sp1 = new Sub1();
  Sub2 *sp2 = new Sub2();
  bp1 = sp1;
  bp2 = sp2;
  bp1->iam(); // See what happens if Base::iam() is not virtual...
  bp2->iam(); // See what happens if Base::iam() is not virtual...
}
