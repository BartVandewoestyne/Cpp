#include <string>
using namespace std;

int main()
{

    //////////////////////////////// EXAMPLE 1 ////////////////////////////////

    string *stringArray = new string[100];

    // Undefined behavior: 99 of the 100 string objects pointed to by
    // stringArray are unlikely to be properly destroyed, because their
    // destructors will probably never be called.
    delete stringArray;


    //////////////////////////////// EXAMPLE 2 ////////////////////////////////

    string *stringPtr1 = new string;
    string *stringPtr2 = new string[100];
    delete stringPtr1;           // delete an object 
    delete [] stringPtr2;        // delete an array of objects


    //////////////////////////////// EXAMPLE 3 ////////////////////////////////

    // Note: a better solution would be to let AddressLines be of
    //       type vector<string>...
    typedef string AddressLines[4];      // a person's address
                                         // has 4 lines, each of
                                         // which is a string

    string *pal = new AddressLines;      // note that "new
                                         // AddressLines" returns
                                         // a string*, just like
                                         // "new string[4]" would

    //delete pal;                          // undefined!
    delete [] pal;                       // fine


}
