/**
 * References:
 *
 *   [1] https://www.ibm.com/developerworks/community/blogs/5894415f-be62-4bc0-81c5-3956e82276f3/entry/defaulted_functions_in_c_11?lang=en
 */

/*
 * This class has no user-defined default constructor.
 */
class X1 {
private:
    int a;
};


/*
 * This class has defined any constructors but a default constructor.  The
 * compiler will not implicitly declare a default constructor when one is
 * needed.
 */
class X2 {
public:
    X2(int i) {
        a = i;
    }
private:
    int a;
};


/*
 * This class has a manually defined default constructor next to the other ones.
 * Drawbacks:
 *   1. You have to manually define the default constructor, which requires
 *      more coding effort.
 *   2. The user-defined default constructor is less efficient than the
 *      compiler implicitly defined default constructor.
 */
class X3 {
public:
    X3() {};  // manually defined default constructor

    X3(int i) {
        a = i;
    }
private:
    int a;
};


/*
 * This class has an explicitly defaulted constructor, which is more efficient
 * than a manually programmed default constructor.
 */
class X4 {
public:
    X4() = default;  // defaulted constructor

    X4(int i) {
        a = i;
    }
private:
    int a;
};


int main()
{
    X1 x1;  // Fine, compiler implicitly defined default constructor is called.

    //X2 x2;  // Error, default constructor X::X() doesn't exist.

    X3 x3;  // fine

    X4 x4;  // fine
}
