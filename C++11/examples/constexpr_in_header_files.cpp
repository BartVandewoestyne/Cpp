/*
 * Key idea:
 *
 *   constexpr implies const and const on global/namespace scope implies static
 *   (internal linkage), which means that every translation unit including this
 *   header gets its own copy of PI. The memory for that static is only going
 *   to be allocated if an address or reference to it is taken, and the address
 *   is going to be different in each translation unit.
 *
 * References:
 *
 *   [stackoverflow20180523] use of constexpr in header file
 *     https://stackoverflow.com/questions/50488831/use-of-constexpr-in-header-file
 */
