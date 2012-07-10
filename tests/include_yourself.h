/**
 * File demonstrating one use of include_guards.  Should a header file
 * accidentily include itself, then include guards seem to protect against
 * this.
 *
 * If we leave out the include guards, we get recursive inclusion resulting
 * in the error:
 *
 *   error: #include nested too deeply
 */

//#ifndef INCLUDE_YOURSELF_H
//#define INCLUDE_YOURSELF_H

#include "include_yourself.h"

//#endif
