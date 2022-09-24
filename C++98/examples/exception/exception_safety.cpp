/*
 * Key ideas:
 *
 * The following four levels of exception guarantee are generally recognized,
 * which are strict supersets of each other:
 *
 *   1. Nothrow (or nofail) exception guarantee
 *      => The function never throws exceptions.
 *         Examples: swap(), pop_back(), destructors.
 *
 *   2. Strong exception guarantee
 *      => If the function throws an exception, the state of the program is
 *         rolled back to the state just before the function call.  So either
 *         the operation succeeds, or has no effect.
 *         Examples: push_back(), single-element insert() on a list, and
 *                   uninitialized_copy().
 *
 *   3. Basic exception guarantee
 *      => If the function throws an exception, the program is in a valid
 *         state.  No resources are leaked, and all objects' inveriants are
 *         intact.
 *
 *   4. No exception guarantee
 *      => If the function throws an exception, the program may not be in a
 *         valid state: resource leaks, memory corruption, or other invariant-
 *         destroying errors may have occurred.
 *
 *   (5.) Exception-neutral guarantee
 *     => Generic components may, in addition, offer this guarantee: if an
 *        exception is thrown from a template parameter (e.g. from the Compare
 *        function object of std::sort or fromthe constructor of T in
 *        std::make_shared), it is propagated, unchanged, to the caller.
 *
 * References:
 *
 * [cppreference] Exceptions
 *   https://en.cppreference.com/w/cpp/language/exceptions
 *
 * [abrahams2001] Exception Safety in Generic Components
 *   https://link.springer.com/chapter/10.1007/3-540-39953-4_6
 *   https://www.boost.org/community/exception_safety.html
 *
 * [sutter2000] Exceptional C++ (page 38)
 *   http://www.gotw.ca/publications/xc++.htm
 *
 * [stroustrup2000] The C++ Programming Language - Appendix E
 *   http://stroustrup.com/3rd_safe.pdf
 */
