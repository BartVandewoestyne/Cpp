/*
 * Major design rule: keep data members private.
 *
 * Advantages:
 *
 *   * Providing the appropriate accessor and manipulator functions leaves you
 *     free to change the internal representation without forcing clients to
 *     rework their code.
 *
 *   * The values of data members in a class are rarely independent.  Direct
 *     (writable) access to data could easily leave an object in an
 *     inconsistent state.
 *
 *   * Providing manipulator and accessor functions affords developers the
 *     opportunity to insert temporary code (e.g. print statements for
 *     debugging, reference counts for performance tuning, and assert
 *     statements for reliability).
 *
 * References:
 *
 *   [lakos1996] Large-Scale C++ Software Design (section 2.2 page 65).
 *
 *   [meyers1992] Effective C++, Item 20, pp. 71-72.
 */
