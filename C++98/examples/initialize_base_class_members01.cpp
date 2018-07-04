/**
 * http://www.learncpp.com/cpp-tutorial/114-constructors-and-initialization-of-derived-classes/
 */

class Base
{
  public:

    int m_nValue;
   
    Base(int nValue=0)
      : m_nValue(nValue)
    {}

};


class Derived: public Base
{
  public:

    double m_dValue;
   
    Derived(double dValue=0.0, int nValue=0)
      : Base(nValue), // Call Base(int) constructor with value nValue!
          m_dValue(dValue)
    {}

};


int main()
{
  Derived cDerived(1.3, 5); // use Derived(double) constructor
 
  return 0;
}
