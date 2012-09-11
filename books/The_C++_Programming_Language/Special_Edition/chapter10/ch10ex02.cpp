/**
 * (*2.5) Complete and test Date.  Reimplement it with "number of days
 * after 1/1/1970" representation.
 *
 * TODO:
 *   1. Improve and test the functionality of this class.
 *   2. Reimplement with "number of days after 1/1/1970" representation.
 *   3. Implement next_weekday (Date d) and next_saturday (Date d).

 */

#include <iostream>
#include <string>
using namespace std;

class Date {

public:

  enum Month { jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };

  class Bad_date{}; // exception class

  Date(int dd=0, Month mm=Month(0), int yy=0); // 0 means ''pick a default''

  int day() const;
  Month month() const;
  int year() const;

  string string_rep() const;      // string representation
  void char_rep( char s[]) const; // C-style string representation

  static void set_default(int, Month, int);

  // functions for changing the Date:
  Date& add_year(int n);               // add n years
  Date& add_month(int n);              // add n months
  Date& add_day(int n);                // add n days

private:

  int d;
  Month m;
  int y;

  static Date default_date;

};


bool leapyear(int y)
{

  // Any year not divisible by 4 is NOT a leap year.
  if (y%4) {
    return false;
  }

  // Any year divisible by 100 and not divisible by 400 is NOT a leap year.
  if (y%100==0 && y%400) {
    return false;
  }

  // All the rest are leap years.
  return true;

}


int days_in_month(int y, Date::Month m)
{
  switch (m) {
    case Date::feb:
      return (leapyear(y)) ? 29 : 28;
    case Date::apr: case Date::jun: case Date::sep: case Date::nov:
      return 30;
    default:
      return 31;
  }
}


Date Date::default_date(22, jan, 1901);

Date::Date(int dd, Month mm, int yy)
{
  if (yy == 0) yy = default_date.year();
  if (mm == 0) mm = default_date.month();
  if (dd == 0) dd = default_date.day();

  int max;

  switch(mm) {
    case feb:
      max = 28 + leapyear(yy);
      break;
    case apr: case jun: case sep: case nov:
      max = 30;
      break;
    case jan: case mar: case may: case jul: case aug: case oct: case dec:
      max = 31;
      break;
    default:
      throw Bad_date();
  }
  
  if (dd < 1 || max < dd) throw Bad_date();

  y = yy;
  m = mm;
  d = dd;

}


int Date::day() const
{
  return d;
}


Date::Month Date::month() const
{
  return m;
}


int Date::year() const
{
  return y;
}


void Date::set_default(int d, Month m, int y)
{
  default_date = Date(d, m, y);
}


Date& Date::add_year(int n)
{
  if ( d==29 && m==feb && !leapyear(y+n) ) { // beware of February 29
    d = 1;
    m = mar;
  }
  y += n;
  return *this;
}


Date& Date::add_month(int n)
{
  if (n == 0) {
    return *this;
  }

  // the number of years to add
  int delta_y = n/12;

  // the new number of months (can be > 12 now!!!)
  int mm = m + n%12;

  // Handle positive number of months to add.
  if (n > 0) {
    if (12 < mm) { // note: int(dec)==12
      delta_y++;
      mm -= 12;
    }
  }

  // Handle negative number of months to add.
  if (n < 0) {
    if (mm < 1) {
      delta_y--;
      mm += 12;
    }
  }

  m = Month(mm);

  // If the day in this date does not exist in the new
  // month, then set it to the last day of the new month.
  if (d > days_in_month(y + delta_y, m)) {
      d = days_in_month(y + delta_y, m);
  }

  add_year(delta_y);

  return *this;

}


Date& Date::add_day(int n) {

  for (int i = 0; i < n; i++) {
    d++;
    if (d > days_in_month(y, m)) {
      d = 1;
      add_month(1);
    }
  }

  for (int i = 0; i > n; i--) {
    d--;
    if (d < 1) {
      add_month(-1);
      d = days_in_month(y, m);
    }
  }

  return *this;

}


bool operator==(Date a, Date b)
{
  return a.day()==b.day() && a.month()==b.month() && a.year()==b.year();
}


bool operator!=(Date a, Date b)
{
  return !(a==b);
}


bool operator<(Date a, Date b)
{
  if ( a.year() < b.year() ) return true;
  if ( a.year() > b.year() ) return false;

  // From here on, the year is the same.
  if ( a.month() < b.month() ) return true;
  if ( a.month() > b.month() ) return false;

  // From here on, the year and the month are
  // the same.
  return a.day() < b.day();
}


bool operator>(Date a, Date b)
{
  return ( !(a<b) && !(a==b) );
}


Date& operator++(Date& d)
{
  d.add_day(1);
  return d;
}


Date& operator--(Date& d)
{
  d.add_day(-1);
  return d;
}


Date& operator+=(Date& d, int n)
{
  d.add_day(n);
  return d;
}


Date& operator-=(Date& d, int n)
{
  d.add_day(-n);
  return d;
}


Date operator+(Date& d, int n)
{
  d.add_day(n);
  return d;
}


Date operator-(Date& d, int n)
{
  d.add_day(-n);
  return d;
}


ostream& operator<<(ostream& os, Date& d)
{
  return os << d.day()
            << '/' << d.month()
            << '/' << d.year();
}


istream& operator>>(istream& is, Date& dd)
{
  int y, m, d;
  char ch1, ch2, ch3, ch4;
  is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;
  if (!is) return is;
  if (ch1!='(' || ch2!=',' || ch3!=',' || ch4!=')') { // oops: format error
    is.clear(ios_base::failbit);                      // set the fail bit
    return is;
  }
  dd = Date(y, Date::Month(m), d);     // update dd
  return is;
}


int main(int argc, char** argv) {

  try {
    Date d(32, Date::jan, 1970);
  } catch (Date::Bad_date b) {
    std::cout << "Bad date\n";
  }

  Date::set_default(28, Date::feb, 1972); // 1972 is a leap year
  Date d(0, Date::Month(0), 0); // default
  std::cout << "Actual date (dd/mm/yyyy): " << d << "\n";
  d.add_day(366);
  std::cout << "Actual date (dd/mm/yyyy): " << d << "\n";
  d.add_day(366);
  std::cout << "Actual date (dd/mm/yyyy): " << d << "\n";
  d.add_day(-2 * 366);
  std::cout << "Actual date (dd/mm/yyyy): " << d << "\n";


  Date my_birthday(21, Date::mar, 1978);
  std::cout << "My birthday: " << my_birthday << "\n";
  ++my_birthday;
  std::cout << "Day after my birthday: " << my_birthday << "\n";
  for (unsigned int i = 1; i <= 12; i++)
  {
    my_birthday.add_month(1);
    std::cout << "After adding one month: " << my_birthday << "\n";
  }

  Date lastDayOfMarch2012(31, Date::mar, 2012);
  std::cout << "Last day of March 2012: " << lastDayOfMarch2012 << "\n";
  lastDayOfMarch2012.add_month(1);
  std::cout << "Last day of March 2012 after adding one month: " << lastDayOfMarch2012 << "\n";

  return 0;
}
