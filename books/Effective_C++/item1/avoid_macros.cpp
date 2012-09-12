// This macro has many drawbacks!
//#define max(a,b) ((a) > (b) ? (a) : (b))

// Better use an inline function (which isn't quite the same as the macro,
// because this version of max can only be called with ints)
//inline int max(int a, int b) { return a > b ? a : b; }

// But a template fixes that problem quite nicely:
template<class T>
inline const T& max(const T& a, const T& b)
{ return a > b ? a : b; }

int main()
{
  int a = 5, b = 0;
  max(++a, b);     // a is incremented twice
  max(++a, b+10);  // a is incremented once
}
