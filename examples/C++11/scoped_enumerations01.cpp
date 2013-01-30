/**
 * References:
 *
 *   [1] C++ Primer, 5th Edition, Chapter 19.3.
 *
 */

// Scoped enumeration
enum class open_modes {input, output, append};

// Named, unscoped enumeration (with enumeration name)
enum color {red, yellow, green};

// Unnamed, unscoped enumeration (without enumeration name)
enum {floatPrec = 6, doublePrec = 10, double_doublePrec = 10};



// ERROR: redefines enumerators
//enum stoplight {red, yellow, green};

// OK: enumerators are hidden
enum class peppers {red, yellow, green};

// OK: enumerators are in scope for an unscoped enumeration
color eyes = green;

// ERROR: enumerators from peppers are not in scope.
//        color::green is in scope but has the wrong type.
//peppers p = green;

// OK: we can explicitly access the enumerators
color hair = color::red;

// OK: using red from peppers
peppers p2 = peppers::red;
