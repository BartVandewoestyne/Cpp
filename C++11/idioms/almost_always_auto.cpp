/**
 * Key ideas:
 *   - Using auto is not primarily about saving typing, but the main reasons
 *     to declare variables using auto are for correctness, performance,
 *     maintainability and robustness and only lastly about typing convenience.
 *
 *   - You can still commit to a certain type by writing declarations of the
 *     form
 *
 *       auto x = type{init};
 *
 *     instead of
 *
 *       type x{init};
 *
 *     Advantages:
 *       - It is self-documenting that the code is explicitly requesting a
 *         conversion.
 *       - It guarantees that the variable will be initialized.
 *       - It won't allow an accidental implicit narrowing conversion.  Only
 *         when you do want explicit narrowing, use () instead of {}.
 *
 * Some examples on Herb Sutter's 'AAA Style (Almost Always Auto)'.
 *
 * References:
 *
 *   [reddit20190516] Almost Always Auto?
 *     https://www.reddit.com/r/cpp/comments/bpdxvf/almost_always_auto/
 *
 *   [sutter2013aaa] GotW #94 Solution: AAA Style (Almost Always Auto)
 *     http://herbsutter.com/2013/08/12/gotw-94-solution-aaa-style-almost-always-auto/
 *
 * TODO:
 *
 *   - add examples from this GotW article.
 */
