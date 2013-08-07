#include <iostream>
using namespace std;

int get_response()
{
    return 1;
}

int main()
{

    // a) Read two numbers and add them as long as there's input.
    do {  // FIXED by adding brace here
        int v1, v2;
        cout << "Please enter two numbers to sum: ";
        if (cin >> v1 >> v2)
            cout << "Sum is: " << v1 + v2 << endl;
    } while (cin); // FIXED by adding brace here


    // b) Do something as long as get_response returns something non-zero.
    //
    //  INCORRECT VERSION
    //do {
    //    // ...
    //} while (int ival = get_response());  // ERROR: do while loop does not allow
    //                                      // variable definitions inside the condition.
    //  CORRECT VERSION
    int ival = 0;
    do {
        // ...
    } while (ival = get_response());  // ERROR: do while loop does not allow


    // c) Do something as long as get_response returns something non-zero.
    //  INCORRECT VERSION
    //do {
    //    int ival2 = get_response();
    //} while (ival2);  // ERROR: variables used in condition must be defined
    //                 // outside the body of the do while statement.
    //  CORRECT VERSION
    int ival2 = 0;
    do {
        ival2 = get_response();
    } while (ival2);

}
