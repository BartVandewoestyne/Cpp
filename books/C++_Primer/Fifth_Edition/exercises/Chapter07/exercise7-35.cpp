#include <string>
using std::string;

typedef string Type;
Type initVal();

class Exercise {
public:
    typedef double Type;
    Type setVal(Type);  // double used
    Type initVal();     // double used
private:
    int val;
};

//Type Exercise::setVal(Type parm) {  // ORIGINAL VERSION (string used)
Exercise::Type Exercise::setVal(Exercise::Type parm) {  // FIXED VERSION (double used)
    val = parm + initVal();
    return val;
}
