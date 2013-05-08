/**
 * Notes:
 *
 *  - One thing we need to keep in mind is that delegating constructors cannot
 *    have initializations of class members in their initializer lists; that is,
 *    a constructor cannot delegate and intialize at the same time. 
 *
 * References:
 *
 *   [1] https://www.ibm.com/developerworks/community/blogs/5894415f-be62-4bc0-81c5-3956e82276f3/entry/introduction_to_the_c_11_feature_delegating_constructors?lang=en
 */

#include <iostream>
using namespace std;

class A {

public:    

   A() : A(0) { cout << "In A()" << endl; }

   A(int i) : A(i, 0) { cout << "In A(int i)" << endl; }

   A(int i, int j) {
      num1 = i;
      num2 = j;
      average = (num1+num2)/2;
      cout << "In A(int i, int j)" << endl;
    }

private:

   int num1;
   int num2;
   int average;

};

int main()
{
   class A a;
   return 0;
}
