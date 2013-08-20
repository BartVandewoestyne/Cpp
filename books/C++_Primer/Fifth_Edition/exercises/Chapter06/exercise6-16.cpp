#include <string>
using namespace std;

// FIXED by making string argument reference to const.
bool is_empty(const string& s) { return s.empty(); }
