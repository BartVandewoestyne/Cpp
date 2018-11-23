#include <iostream>
#include <string>
#include <map>

class Foo {

public:

    void f() { std::cout << "f()" << std::endl; }
    void g() { std::cout << "g()" << std::endl; }

    Foo() {
        fmap.insert(std::make_pair("f", &Foo::f));
        fmap.insert(std::make_pair("g", &Foo::g));
    }

    void doit(const std::string& s)
    {
        //MFP fp = fmap[s];
        //(this->*fp)();
        (this->*(fmap[s]))();
    }

private:

    typedef void (Foo::*MFP)();

    std::map<std::string, MFP> fmap;
};


int main()
{
    Foo f;
    f.doit("f");
}
