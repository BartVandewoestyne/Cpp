class ManyDataMbrs {
public:
  // default constructor
  ManyDataMbrs();

  // copy constructor
  ManyDataMbrs(const ManyDataMbrs& x);
 
private:
  int a, b, c, d, e, f, g, h;
  double i, j, k, l, m;

  void init();  // used to initialize data members
};


//// Method 1: using member initialization lists.
//ManyDataMbrs::ManyDataMbrs()
//  : a(1), b(1), c(1), d(1), e(1), f(1), g(1), h(1), i(0),
//    j(0), k(0), l(0), m(0)
//{}
//
//
//// Method 1: using member initialization lists.
//ManyDataMbrs::ManyDataMbrs(const ManyDataMbrs& x)
//  : a(1), b(1), c(1), d(1), e(1), f(1), g(1), h(1), i(0),
//    j(0), k(0), l(0), m(0)
//{}


// Method 2: using init() method.
void ManyDataMbrs::init()
{
    a = b = c = d = e = f = g = h = 1;
      i = j = k = l = m = 0;
}

 
// Method 2: using init() method.
ManyDataMbrs::ManyDataMbrs()
{
  init();
}

 
// Method 2: using init() method.
ManyDataMbrs::ManyDataMbrs(const ManyDataMbrs& x)
{
  init();
}
