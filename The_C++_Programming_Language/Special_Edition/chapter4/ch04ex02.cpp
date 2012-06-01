/*
 * Declaration: associate a type with a name.
 * Definition: also define an entity for the name to which it refers.
 *
 * Note: Any declaration that specifies a value is a definition.
 *
 * TODO: finish this...
 */

// declaration and definition (that does not specify a value).
char ch;

// declaration and definition (that does not specify a value).
string s;
int count = 1;

// declaration and definition (that specifies a value for the entity it defines)
const double pi = 3.1415926535897932385;

// only declaration (because the memory for the int variable error_number must
// be allocated by some other declaration of error_number).
extern int error_number;

// declaration and definition.
int error_number = 1;

const char* name = "Njal";
const char* season[] = { "spring", "summer", "fall", "winter" };

// declaration and definition
struct Date { int d, m, y; };

// declaration and definition (that specifies a ``value'' for the entity it
// defines).
int day(Date* p) { return p->d; }

// only declaration (because the code (body) for the function sqrt) must be
// specified by some other declaration).
double sqrt(double);

// declaration and definition.
double sqrt(double) { /* ... */ }

template<class T> T abs(T a) { return a<0 ? -a : a; }

// declaration and definition (that specifies a ``value'' for the entity it
// defines).
typedef complex<short> Point;

// only declaration (because some other declaration of the type User must define
// what that type looks like).
struct User;

// declaration and definition.
struct User { /* ... */ }


enum Beer { Carlsberg, Tuborg, Thor };
namespace NS { int a; }
