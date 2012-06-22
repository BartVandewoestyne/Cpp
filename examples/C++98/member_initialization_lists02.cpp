/**
 * Illustrates the use of member initialization lists.
 *
 * Reference:
 *
 *   http://www.informit.com/guides/content.aspx?g=cplusplus&seqNum=172
 */

#include <string>
using namespace std;

class Person {

  private:

    int age;
    string name;

  public:

    // Here, we use a member initialization list.
    Person(int a, const string & n) : age (a), name (n)
    {}

};
