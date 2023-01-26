/*
 * Key ideas:
 *
 * Type aliases can be useful in the following situations:
 *   - For platform independent coding.
 *   - To make complex types easier to read.
 *   - For legibility.
 *   - For easier code maintenance.
 *     (But watch out!  If type changes, behavior of program may change!)
 *
 * Type aliases should be used primarily in cases where there is a clear
 * benefit to code readability or code maintenance. This is as much of an art
 * as a science. Type aliases are most useful when they can be used in many
 * places throughout your code, rather than in fewer places.
 *
 * Cons:
 *
 *   - While type aliases offer some benefits, they also introduce yet another
 *     identifier into your code that needs to be understood. If this isn’t
 *     offset by some benefit to readability or comprehension, then the type
 *     alias is doing more harm than good.
 *
 *   - A poorly utilized type alias can take a familiar type (such as
 *     std::string) and hide it behind a custom name that needs to be looked up.
 *     In some cases (such as with smart pointers, which we’ll cover in a future
 *     chapter), obscuring the type information can also be harmful to
 *     understanding how the type should be expected to work.
 *
 *   - Type aliases are not distinct types
 *
 * Best practice:
 *
 *   Use type aliases judiciously, when they provide a clear benefit to code
 *   readability or code maintenance.
 *
 * References:
 *
 *   [learncpp20221031] Typedefs and type aliases
 *     https://www.learncpp.com/cpp-tutorial/typedefs-and-type-aliases/
 */
