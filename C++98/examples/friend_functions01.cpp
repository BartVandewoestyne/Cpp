/**
 * Example to demonstrate friend functions.
 *
 * A friend function is a function that can access the private members of a
 * class as though it were a member of that class.  In all other regards, the
 * friend function is just like a normal function.  A friend function may or may
 * not be a member of another class.  To declare a friend function, simply use
 * the friend keyword in front of the prototype of the function you wish to be
 * a friend of the class.  It does not matter whether you declare the friend
 * function in the private or public section of the class.
 *
 * References:
 *
 *   http://www.learncpp.com/cpp-tutorial/813-friend-functions-and-classes/
 */

class Accumulator
{
  private:

    int m_nValue;

  public:

    Accumulator() { m_nValue = 0; }
    void add(int nValue) { m_nValue += nValue; }
   
    // Make the Reset() function a friend of this class.
    friend void reset(Accumulator &cAccumulator);
};
 
// Reset() is now a friend of the Accumulator class...
void reset(Accumulator &cAccumulator)
{
    // ... and can access the private data of Accumulator objects.
    cAccumulator.m_nValue = 0;
}
