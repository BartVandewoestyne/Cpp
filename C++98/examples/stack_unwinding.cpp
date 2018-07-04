/*
 * Demonstrate stack unwinding.
 *
 * References:
 *
 *   [1] https://msdn.microsoft.com/en-us/library/hh254939.aspx
 */

#include <string>
#include <typeinfo>
#include <iostream>

using namespace std;

class MyException {};

class Dummy
{
public:

    Dummy(string s) : MyName(s) { PrintMsg("Created Dummy: "); }

    Dummy(const Dummy& other) : MyName(other.MyName) { PrintMsg("Copy created Dummy: "); }

    ~Dummy() { PrintMsg("Destroyed Dummy: "); }

    void PrintMsg(string s) { cout << s << MyName << endl; }

    string MyName; 
    int level;
};


void C(Dummy d, int i)
{ 
    cout << "Entering FunctionC" << endl;
    d.MyName = "C";
    throw MyException();   

    cout << "Exiting FunctionC" << endl;
}

void B(Dummy d, int i)
{
    cout << "Entering FunctionB" << endl;
    d.MyName = "B";
    C(d, i + 1);   
    cout << "Exiting FunctionB" << endl; 
}

void A(Dummy d, int i)
{ 
    cout << "Entering FunctionA" << endl;
    d.MyName = "A" ;
    //Dummy* pd = new Dummy("new Dummy"); // Not exception safe!!!
    B(d, i + 1);
    //delete pd; 
    cout << "Exiting FunctionA" << endl;   
}


int main()
{
    cout << "Entering main" << endl;
    try
    {
        Dummy d("M");
        A(d, 1);
    }
    catch (MyException& e)
    {
        cout << "Caught an exception of type: " << typeid(e).name() << endl;
    }

    cout << "Exiting main." << endl;
}
