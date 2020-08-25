/**
 * Illustrates '(Named) Return Value Optimization'.
 *
 * Return Value Optimization (RVO) is also sometimes called 'elision' or 'copy
 * elision'.  The C++98/03 standard doesn't require the compiler to provide RVO
 * optimization, but most popular C++ compilers contain this optimization
 * technique: IBM XL C++, GCC and Clang.  GCC seems to have it by default, but
 * Visual Studio C++ does not seem to have it as a default.  It depends on the
 * optimization level used.
 *
 * The technique is included in the C++11 standard due to its prevalence.  See
 * section 12.8 in the C++11 standard.  The name of the technique is 'copy
 * elision'.
 *
 * The conclusion is this:
 *
 * "RVO is a compiler optimization technique, while std::move is just an rvalue
 *  cast, which also instructs the compiler that it's eligible to move the
 *  object. The price of moving is lower than copying but higher than RVO, so
 *  never apply std::move to local objects if they would otherwise be eligible
 *  for the RVO."
 *
 *
 * References:
 *
 *   [cppstandard] C++ 11 standard, section 12.8/31.
 *   
 *   [raghav20200816] But I was helping the compiler!
 *     https://pankajraghav.com/2020/08/16/RVO.html
 *
 *   [meyers] Effective Modern C++, Item 25, pages 174-176.
 *
 *   [ibm?????]
 *     https://www.ibm.com/developerworks/community/blogs/5894415f-be62-4bc0-81c5-3956e82276f3/entry/RVO_V_S_std_move
 *
 *   [shahar20170818] Return Value Optimization
 *     http://shaharmike.com/cpp/rvo/
 *
 *   [shahar20170817] Need to demonstrate RVO performance with Clang and modern C++
 *     https://www.reddit.com/r/cpp/comments/6u78dp/need_to_demonstrate_rvo_performance_with_clang/
 *
 *   [boccara20161128] Return value optimizations
 *     https://www.fluentcpp.com/2016/11/28/return-value-optimizations/
 */

#include <iostream>

#if __cplusplus == 201103L
  #include <utility>
#endif

using namespace std;

class BigObject {

public:

    BigObject() {
        cout << "  constructing " << this << endl;
    }

    ~BigObject() {
        cout << "  destructing " << this << endl;
    }

    BigObject(const BigObject&) {
        cout << "  copy constructing " << this << endl;
    }

#if __cplusplus == 201103L
    BigObject(BigObject&&) {
        cout << "  move constructing " << this << endl;
    }
#endif

};


/**
 * Note that no copy constructor is being called here.  When the price of
 * copying is high, RVO enables us to run the program much faster.
 */
BigObject foo1()
{
    BigObject localObj;
    return localObj;
}


/**
 * Here, in C++98, the copy constructor *is* called, so no Return Value Optimization.
 * In C++11, the move constructor is called if it is available.
 */
BigObject foo2(int n)
{
    BigObject localObj, anotherLocalObj;

    if (n > 2)
    {
        return localObj;
    }
    else
    {
        return anotherLocalObj;
    }
}


#if __cplusplus == 201103L
BigObject foo3()
{
    BigObject localObj;
    return std::move(localObj);
}


/**
 * Do not do this in real development, because you are returning a reference
 * to a local object here!
 */
BigObject&& foo4()
{
    BigObject localObj;
    return std::move(localObj);
}


BigObject foo5(int n)
{
    BigObject localObj, anotherLocalObj;

    if (n > 2) {

       return std::move(localObj);

    } else {

       return std::move(anotherLocalObj);

    }
}
#endif


int main()
{

    cout << "__cplusplus = " << __cplusplus << endl;
#if __cplusplus == 201103L
    cout << "Compiled as C++11 code." << endl;
#else
    cout << "Compiled as non-C++11 code." << endl;
#endif
    cout << std::endl;

    {
        cout << "1 local object, no std::move applied:" << endl;
        BigObject obj = foo1();
    }
    cout << std::endl;
    {
        cout << "2 local objects, no std::move applied:" << endl;
        BigObject obj = foo2(1);
    }

#if __cplusplus == 201103L
    cout << std::endl;
    {
        cout << "1 local object, std::move applied:" << endl;
        BigObject obj = foo3();
    }
    cout << std::endl;
    {
        cout << "1 local object, std::move applied, r-value return type:" << endl;
        auto obj = foo4();
    }
    cout << std::endl;
    {
        cout << "2 local objects, std::move applied" << endl;
        BigObject obj = foo5(1);
    }
#endif

}
