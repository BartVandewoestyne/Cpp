/**
 * (*1) Find the error in Date::add_year() in §10.2.2.  Then find two
 * additional errors in the version in §10.2.7.
 */

class Date {

  int d, m, y;

public:

  void init(int dd, int mm, int yy);    // initialize

  void add_year(int n);                 // add n years
  void add_month(int n);                // add n months
  void add_day(int n);                  // add n days
};


/**
 * Problem: if the date before the operation is February 29 (so we're in a
 * leap year), then the year after the operation is not a leap year and
 * February 29 does not exist in that year.
 */
inline void Date::add_year(int n)
{
  y += n;
}


inline void Date::add_month(int n)
{
  m += n;
}


inline void Date::add_day(int n)
{
  d += n;
}
