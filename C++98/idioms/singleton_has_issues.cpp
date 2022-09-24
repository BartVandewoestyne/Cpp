/*
 * Issues with Singleton:
 *
 *   * If multiple DLLs are linked against a static library that defines the
 *     singleton, they will each get their own copy of that singleton.
 *     If your application is a single EXE with no custom DLLs, this may not
 *     be a problem.
 *
 *   -> Unit testing is harder?
 *
 *   -> Thread safety?
 *
 * References:
 *
 *   [stackoverflow20080926] When to use dynamic vs. static libraries
 *     https://stackoverflow.com/questions/140061/when-to-use-dynamic-vs-static-libraries
 *
 *   [stackoverflow20110804] C++ a singleton class with dll
 *     https://stackoverflow.com/questions/6935541/c-a-singleton-class-with-dll/
 */
