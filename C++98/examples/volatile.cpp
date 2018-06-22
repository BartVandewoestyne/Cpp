/**
 * References:
 *
 * TODO:
 *   There are nice examples for the volatile keyword in [grimm2017,meyers2014emc++].
 */

// A volatile specifier is a hint to a compiler that an object may change its
// value in ways not specified by the language so that aggressive optimizations
// must be avoided.  For example, a real time clock might be declared:

extern const volatile clock;

// Two successive reads of clock might give different results.
