/**
 * References:
 *
 *   [1] http://www.stroustrup.com/C++11FAQ.html#suffix-return
 */

// ERROR: SCOPE PROBLEM:
//template<class T, class U>
//decltype(x*y) mul(T x, U y) // scope problem!
//{
//    return x*y;
//}


// UGLY CODE
template<class T, class U>
decltype(*(T*)(0)**(U*)(0)) mul1(T x, U y) // ugly! and error prone
{
    return x*y;
}

template<class T, class U>
auto mul2(T x, U y) -> decltype(x*y) // ugly! and error prone
{
    return x*y;
}
