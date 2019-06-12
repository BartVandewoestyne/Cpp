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
 *   [reddit20150713] Why does C++ not adopt MSVC extension allowing temp objects to be assigned to non-const references (lvalues)?
 *     https://www.reddit.com/r/cpp/comments/3d3p85/why_does_c_not_adopt_msvc_extension_allowing_temp/
 *
 *   [stackoverflow20141213] Can't pass temporary object as reference
 *     http://stackoverflow.com/questions/27463785/cant-pass-temporary-object-as-reference
 *
 *   [sawicki20120131] Visual C++ is so Liberal
 *     http://www.asawicki.info/news_1482_visual_c_is_so_liberal.html
 *
 *   [sutter20080101] GotW #88: A Candidate For the ``Most Important const''
 *     https://herbsutter.com/2008/01/01/gotw-88-a-candidate-for-the-most-important-const/
 */
class Base { };

void f(Base& b) {}

int main()
{
    f(Base());

    Base b;
    f(b);
}
