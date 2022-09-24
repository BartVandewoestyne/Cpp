/**
 * Key ideas:
 *
 *   - Typically, decltype(auto) is used to allow auto declarations to use the
 *     decltype rules on the given expression.
 *
 *   - decltype(auto) is used for:
 *
 *     -> Return type forwarding in generic code
 *
 *     -> Delaying return type deduction in recursive templates
 *
 * References:
 *
 *   [stackoverflow20140608] What are some uses of decltype(auto)?
 *     http://stackoverflow.com/questions/24109737/what-are-some-uses-of-decltypeauto
 *
 *   [meyers20130707] When decltype meets auto
 *     http://scottmeyers.blogspot.com/2013/07/when-decltype-meets-auto.html
 *
 *   [becker201305XX] C++ auto and decltype Explained
 *     http://thbecker.net/articles/auto_and_decltype/section_01.html
 */
