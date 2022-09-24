/*
 * By convention, deleted functions are declared public, not private.
 *
 * Motivation:
 *
 *   * C++ checks accessibility before deleted status.  When code tries to use
 *     a deleted private function, some compilers complain only about the
 *     function being private, even though the function's accessibility doesn't
 *     really affect whether it can be used.  So making the deleted functions
 *     public will generally result in better error messages.
 *
 * References:
 *
 *   [stackoverflow20190317] Deletion of copy-ctor & copy-assignment - public, private or protected?

 *     https://stackoverflow.com/questions/55205874/deletion-of-copy-ctor-copy-assignment-public-private-or-protected
 *
 *   [meyers201411XX] Effective Modern C++, Item 10
 */
