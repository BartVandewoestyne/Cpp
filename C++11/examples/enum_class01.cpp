/**
 * References:
 *
 *   [kumar20200604] Scoped (class) enums: fundamentals and examples
 *     https://www.nextptr.com/tutorial/ta1423015134/scoped-class-enums-fundamentals-and-examples
 *
 *   [grimm20171127] C++ Core Guidelines: Rules for Enumerations
 *     http://www.modernescpp.com/index.php/c-core-guidelines-rules-for-enumerations
 *
 *   [gregory20170927] 10 Core Guidelines You Need to Start Using Now
 *     https://youtu.be/XkDEzfpdcSg?t=37m38s
 *
 *   [macias20151228] ENUM CLASS. WHY SHOULD YOU CARE?
 *     https://katecpp.wordpress.com/2015/12/28/enum-class/
 *
 *   [oleksiy20130820] Why is enum class preferred over plain enum?
 *     https://stackoverflow.com/questions/18335861/why-is-enum-class-preferred-over-plain-enum
 *
 *   [allain] Better types in C++11 - nullptr, enum classes (strongly typed enumerations) and cstdint
 *     http://www.cprogramming.com/c++11/c++11-nullptr-strongly-typed-enum-class.html
 */

// this code won't compile!
//enum Color {RED, GREEN, BLUE};
//enum Feelings {EXCITED, MOODY, BLUE};

// this code will compile (if your compiler supports C++11 strongly typed enums)
enum class Color {RED, GREEN, BLUE};
enum class Feelings {EXCITED, MOODY, BLUE};

enum class Mood;

void assessMood(Mood m);

enum class Mood { EXCITED, MOODY, BLUE };

// we only have three colors, so no need for ints!
//enum class Colors : char { RED = 1, GREEN = 2, BLUE = 3 };
#include <cstdint>
enum class Colors : std::int8_t { RED = 1, GREEN = 2, BLUE = 3 };

int main()
{
    Color color = Color::GREEN;
    if ( Color::RED == color )
    {
      // the color is red
    }
}
