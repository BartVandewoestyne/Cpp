/**
 * References:
 *
 *   [1] C++ Primer, 5th edition.
 */

/**
 * Variables defined in an unnamed namespace have static lifetime: They are
 * created before their first use and destroyed when the program ends.
 * [...]
 * Unlike other namespaces, an unnamed namespace is local to a particular file
 * and never spans multiple files.
 * [...]
 * The use of file static declarations is deprecated by the C++ standard.
 * File statics should be avoided and unnamed namespaces used instead.
 */
namespace {
    int i;
}
