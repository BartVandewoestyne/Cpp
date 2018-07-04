/**
 * I think this program has undefined behavior.  Don't trust too much on it as
 * a typical example of virtual functions...
 *
 * References:
 *   [1] http://stackoverflow.com/questions/7743775/virtual-keyword-makes-inaccessible-a-method-from-the-derived-objects
 */
#include <iostream>

class Super{

  public:
    // Notice the difference in behavior with or without the virtual keyword!!!
    // TODO: why exactly is this???
    //virtual
    void showName();
};

class Special1 : public Super {
public:
    void showName();
    void sayHello();
};

class Special2 : public Super {
public:
    void showName();
    void sayGoodbye();
};

void Super::showName() {
    std::cout << "I'm Super!" << std::endl;
}

void Special1::showName() {
    std::cout << "I'm Special1" << std::endl;
}

void Special1::sayHello() {
    std::cout << "Hello" << std::endl;
}

void Special2::showName() {
    std::cout << "I'm Special2" << std::endl;
}

void Special2::sayGoodbye() {
    std::cout << "Goodbye" << std::endl;
}

int main () {

    Super *oSpec = new Super;

    Special1 *o1 = static_cast<Special1 *>(oSpec);
    Special2 *o2 = static_cast<Special2 *>(oSpec);

    oSpec->showName();
    o1->showName();
    o2->showName();

    o1->sayHello();
    o2->sayGoodbye();

    delete oSpec;

    return 0;
}
