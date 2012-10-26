/**
 * References:
 *   [1] http://blog.knatten.org/2012/10/26/a-bad-excuse-for-private-inheritance/
 */

#include <string>
using namespace std;

// dummy implementation of to_string from myself...
string to_string(double d)
{
  return "1.234";
}


class CppInfo
{
public:
    string info()
    {
        return "Language: C++\nCreator : Bjarne Stroustrup\nQuality : ??";
    }
};


class LanguageQuality
{
public:
    virtual ~LanguageQuality() {}

    double quality() const
    {
        return 100.0 / charsForHelloWorld();
    }
protected:
    virtual int charsForHelloWorld() const = 0;
};


class CppInfo_UsingInheritance : private LanguageQuality
{
public:
    string info()
    {
        return "Language: C++\nCreator : Bjarne Stroustrup\nQuality : " + to_string(quality());
    }
private:
    int charsForHelloWorld() const
    {
        return string("#include <iostream>\nint main() { std::cout << \"Hello World\"; }").size();
    }
};


class CppQuality : public LanguageQuality
{
protected:
    int charsForHelloWorld() const {
        return string("#include <iostream>\nint main() { std::cout << \"Hello World\"; }").size();
    }
};


class CppInfoMember 
{
public:
    string info()
    {
        return "Language: C++\nCreator : Bjarne Stroustrup\nQuality : " + to_string(cppQuality.quality());
    }
private:
    CppQuality cppQuality;
};
