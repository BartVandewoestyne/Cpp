/*
 * Key ideas:
 *
 *   - You are solely responsible of the accuracy of the noexcept specification.
 *
 *   - Tread lightly when using noexcept.
 * 
 *   - When you are saying "I am certain this code will never throw
 *     exceptions", once you offer that guarantee, removing it can break a lot of
 *     code... so when using noexcept you must not only be *certain* that your
 *     code does not throw, but that it will very likely never throw in future
 *     implementations.  When in doubt, abstain.
 *
 *   - When the compiler encounters the noexcept keyword, it will assume your
 *     code *never* throws and it can replace code by simpler code.
 *
 *   - The noexcept not only conveys information to the compiler, it also conveys information to the developer.
 *
 *   - noexcept gives *real* optimization opportunities to the compiler and may thus be worth the effort.
 *
 *   - The following expressions are noexcept by default:
 *       - destructor
 *       - deallocation functions
 *
 *   - Examples of code that *might* throw:
 *       - allocating memory -> can throw std::bad_alloc
 *       - every function you call
 *       - every object you instantiate
 *       - ...
 *
 *   - Good noexcept candidates are expressions that *recursively* meet the following criteria:
 *
 *       - Doesn't explicitly throw an exception.
 *       - Only constructs trivial types or types with noexcept constructors.
 *       - Calls only noexcept or C functions (careful with operators!).
 *       - Will likely stay as such in the future.
 *
 *   - When creating an object, it's worth looking at it to see if its constructors and assignment
 *     operators can be specified as noexcept:
 *       1. By induction, you make it possible to spread exception safety information throughout your code.
 *       2. You give real optimization opportunities to the compiler when your objects are used in containers.
 *
 *   - When you write
 *
 *       void f() noexcept { // ... }
 *
 *     you are implicitly writing
 *
 *       void f() noexcept(true) { // ... }
 *
 *   - Next to the noexcept *specifier*, there is a noexcept *operator* which
 *     returns true when an expression is declared to not throw an exception.
 *     => Whenever possible, infer if an expression is noexcept with the noexcept operator.
 *
 * References:
 *
 *   [cppreference] noexcept specifier (since C++11)
 *     https://en.cppreference.com/w/cpp/language/noexcept_spec
 *
 *   [cppreference] noexcept operator (since C++11)
 *     https://en.cppreference.com/w/cpp/language/noexcept
 *
 *   [fertig20211215] C++ Insights - Episode 21: How noexcept works
 *     https://youtu.be/2xHfTLbEkko
 *
 *   [20191119microsoft] noexcept (C++)
 *     https://docs.microsoft.com/en-us/cpp/cpp/noexcept-cpp?view=msvc-160
 *
 *   [grimm20180802] C++ Core Guidelines: The noexcept Specifier and Operator
 *     https://www.modernescpp.com/index.php/c-core-guidelines-the-noexcept-specifier-and-operator
 *
 *   [20161212quasardb] When noexcept?
 *     https://blog.quasardb.net/when-noexcept-2/
 *
 *   [201411XX] Effective Modern C++ - Item 14: Declare functions noexcept if they won't emit exceptions.
 *
 *   [20131231] When to Use noexcept And When to Not
 *     https://xinhuang.github.io/posts/2013-12-31-when-to-use-noexcept-and-when-to-not.html
 *
 *   [20120528stackoverflow] When should I really use noexcept?
 *     https://stackoverflow.com/questions/10787766/when-should-i-really-use-noexcept
 */

// This may be surprising, but this code will compile without error.
void my_function() noexcept
{
    throw std::runtime_error("lolilol");
}

// In this example, we express the idea "if my constructor is noexcept, then I
// would like my awesome_factory to be noexcept".  This can be done by
// combining the noexcept *specifier* with the noexcept *operator* as follows:
template <typename T, typename Params...>
T awesome_factory(Params... params) noexcept(noexcept(T{params...}))
{
   return T{params...};
}
