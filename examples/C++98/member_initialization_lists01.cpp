/**
 * Illustrates the use of member initialization lists.
 *
 * In this example, we don't use member initialization lists!!!  We use
 * assignment.  When dealing with built-in types, the performance difference
 * between such assignments and proper initialization is negligible.  However,
 * when it comes to objects, the difference can be rather noticeable.  This is
 * so because the object in question is first constructed and only then it is
 * assigned.
 *
 * References:
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

    // The members age and name are *assigned*.
    Person(int a, const string & n) {
      age = a; 
      name = n; 
    }

};
