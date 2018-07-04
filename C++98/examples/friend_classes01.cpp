/**
 * Example demonstrating how it is also possible to make an entire class a
 * friend of another class.  This gives all the members of the friend class
 * access to the private members of the other class.
 *
 * Reference:
 *
 *   http://www.learncpp.com/cpp-tutorial/813-friend-functions-and-classes/
 */

#include <iostream>

class Storage
{

  private:
    int m_nValue;
    double m_dValue;

  public:
    Storage(int nValue, double dValue)
    {
      m_nValue = nValue;
      m_dValue = dValue;
    }
   
    // Make the Display class a friend of Storage
    friend class Display;
};
 

// Because the Display class is a friend of Storage, any of Display’s members
// that use a Storage class object can access the private members of Storage
// directly.
class Display
{

  private:
    bool m_bDisplayIntFirst;
   
  public:
    Display(bool bDisplayIntFirst) { m_bDisplayIntFirst = bDisplayIntFirst; }
  
    void DisplayItem(Storage &cStorage)
    {
      if (m_bDisplayIntFirst)
        std::cout << cStorage.m_nValue << " " << cStorage.m_dValue << std::endl;
      else // display double first
        std::cout << cStorage.m_dValue << " " << cStorage.m_nValue << std::endl;
    }
};


int main()
{
  Storage cStorage(5, 6.7);
  Display cDisplay(false);
 
  cDisplay.DisplayItem(cStorage);

  return 0;
}
