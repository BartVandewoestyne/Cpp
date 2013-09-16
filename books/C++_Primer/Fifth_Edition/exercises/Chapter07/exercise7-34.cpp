#include <string>

// note: this code is for illustration purposes only and reflects bad practice
// it is generally a bad idea to use the same name for a parameter and a member

int height;  // defines a name subsequently used inside Screen

class Screen {
public:
    void dummy_fcn(pos height) {
        cursor = width * height; // which height? the parameter
    }
private:
    pos cursor = 0;
    pos height = 0, width = 0;
//private:
public:
    typedef std::string::size_type pos;  // error: ‘pos’ has not been declared
};
