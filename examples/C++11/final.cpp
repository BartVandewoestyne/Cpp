/**
 * References:
 *
 *   [barnett2017] Is the final function specifier redundant when using the final class specifier?
 *     https://stackoverflow.com/questions/43704769/is-the-final-function-specifier-redundant-when-using-the-final-class-specifier
 *
 *   [krzemienski2012] Why make your classes final?
 *     http://akrzemi1.wordpress.com/2012/09/30/why-make-your-classes-final/
 */

struct B final {
  int i;
};

struct D : B { // ERROR
  int j;
};
