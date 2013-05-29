/**
 * References:
 *
 *   [1] http://musingstudio.com/2013/05/28/how-to-choose-whether-to-pass-by-const-reference-or-by-value/
 */

#include <string>
#include <iostream>
 
class A
{
public:
    A( const std::string& s )
        : str_( s )
    {
        std::cout << "A: s='" << s << "', str_='" << str_ << "'\n";
    }
private:
    std::string str_;
};
 

class B
{
public:
    B( std::string s )
        : str_( s )
    {
        std::cout << "B: s='" << s << "', str_='" << str_ << "'\n";
    }
private:
    std::string str_;
};
 

class C
{
public:
    C( std::string s )
        : str_( std::move(s) )
    {
        std::cout << "C: s='" << s << "', str_='" << str_ << "'\n";
    }
private:
    std::string str_;
};
 
 
int main(int argc, char* argv[])
{
    A a( "ConstReference" );      // Constructor(char*) then CopyConstructor
    B b( "PassByValue" );         // Constructor(char*) then CopyConstructor
    C c( "PassByValueAndMove" );  // Constructor(char*) then MoveConstructor
 
    return 0;
}
