/**
 * If an exception occurs in the body of a target constructor, it can be caught
 * by the try block of the delegating constructor.  This example demonstrates
 * this rule.
 *
 * References:
 *
 *   [1] https://www.ibm.com/developerworks/community/blogs/5894415f-be62-4bc0-81c5-3956e82276f3/entry/introduction_to_the_c_11_feature_delegating_constructors?lang=en
 */

#include <iostream>
using namespace std;

class A {

public:

   A();
   A(int i);
   A(int i, int j);

private:

   int num1;
   int num2;
   int average;

};   

A:: A() try : A(0) {
   cout << "A() body" << endl;
}
catch(...) {
   cout << "A() catch" << endl;
}

A::A(int i) try : A(i, 0) {
   cout << "A(int i) body" << endl;
}
catch(...) {
   cout << "A(int i) catch" << endl;
}

A::A(int i, int j) try {
   num1 = i;
   num2 = j;
   average = (num1+num2)/2;
   cout << "A(int i, int j) body" << endl;
   throw 1;
}
catch(...) {
   cout << "A(int i, int j) catch" << endl;
}

int main() {

   try {
      class A a;
      cout << "main body" << endl;
   }
   catch(...) {
      cout << "main catch" << endl;
   }
   return 0;

}
