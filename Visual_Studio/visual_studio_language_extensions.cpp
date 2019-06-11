/*
 * When using the Language Extensions in Visual C++, binding a non-const
 * reference to something else than an lvalue is allowed.  This is however not
 * standard conforming.
 *
 * References:
 *
 *   [microsoft] Microsoft extensions to C and C++
 *     https://msdn.microsoft.com/en-us/library/34h23df8.aspx
 *
 *   [microsoft] /Za, /Ze (Disable Language Extensions)
 *     https://msdn.microsoft.com/en-us/library/0k0w269d.aspx
 *
 *   [stackoverflow20141213] Can't pass temporary object as reference
 *     http://stackoverflow.com/questions/27463785/cant-pass-temporary-object-as-reference
 *
 *   [sawicki20120131] Visual C++ is so Liberal
 *     http://www.asawicki.info/news_1482_visual_c_is_so_liberal.html
 */
class Base { };

void f(Base& b) {}

int main()
{
    f(Base());

    Base b;
    f(b);
}
