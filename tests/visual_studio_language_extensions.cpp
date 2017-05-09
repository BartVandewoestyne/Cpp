/*
 * When using the Language Extensions in Visual C++, binding a non-const
 * reference to something else than an lvalue is allowed.  This is however not
 * standard conforming.
 *
 * References:
 * [1] http://stackoverflow.com/questions/27463785/cant-pass-temporary-object-as-reference
 * [2] https://msdn.microsoft.com/en-us/library/0k0w269d.aspx
 */
class Base { };

void f(Base& b) {}

int main()
{
    f(Base());

    Base b;
    f(b);
}
