/**
 * (*1) How do you access set_default from class Date from namespace
 * Chrono (§10.3.2)? Give at least three different ways.
 */

namespace Chrono { // facilities for dealing with time

  class Date {
  
  public:
    enum Month { jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };
  
    class Bad_date{}; // exception class
  
    Date(int dd=0, Month mm=Month(0), int yy=0); // 0 means ''pick a default''
  
    // functions for examining the Date:
    int day() const;
    Month month() const;
    int year() const;
    //string string_rep() const;
    //void char_rep(char s[]) const;
    static void set_default(int, Month, int);
  
    //// functions for changing the Date
    //Date& add_year(int n);   // add n years
    Date& add_month(int n);  // add n months
    //Date& add_day(int n);    // add n days
  
  private:
    int d, m, y;  // representation
    static Date default_date;
  
  };
  
  bool leapyear(int y);
  
  Date Date::default_date(1, Date::feb, 1970);
  
  bool leapyear(int y)
  {
    // Any year divisible by 4 except centenary years not divisible by 400.
    if (y%4) return false;
    if (y%100==0 && y%400) return false;
    return true;
  }
  
  
  Date::Date(int dd, Month mm, int yy)
  {
    if (yy == 0) yy = default_date.year();
    if (mm == 0) mm = default_date.month();
    if (dd == 0) dd = default_date.day();
  
    int max;
  
    switch (mm) {
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
        throw Bad_date(); // someone cheated
    }
  
    if (dd < 1 || max < dd) throw Bad_date();
  
    y = yy;
    m = mm;
    d = dd;
  }
  
  
  inline int Date::day() const
  {
    return d;
  }
  
  
  inline Date::Month Date::month() const
  {
    return Month(m);
  }
  
  
  inline int Date::year() const
  {
    return y;
  }
  
  
  void Date::set_default(int dd, Month mm, int yy)
  {
    //default_date.d = dd;
    default_date.add_month(mm);
    //default_date.y = yy;
  }
  
  
  Date& Date::add_month(int n)
  {
    if (n==0) return *this ;
  
    if (n > 0) {
      int delta_y = n/12;
      int mm = m + n%12;
      if (12 < mm) { // note: int(dec)==12
        delta_y++;
        mm -= 12;
      }
  
      // handle the cases where Month(mm) doesn't have day d
  
      y += delta_y;
      m = Month(mm);
      return *this;
    }
  
    // handle negative n
  
    return *this;
  
  }


} // namespace Chrono


int main()
{

  {
    // Method 1: use fully qualified names everywhere.
    Chrono::Date::set_default(1, Chrono::Date::jan, 3);
  }

  {
    // Method 2: exploit a using declaration.
    using Chrono::Date;
    Date::set_default(3, Date::feb, 1970);
  }

  {
    // Method 3: using a typedef.
    typedef Chrono::Date MyDate;
    MyDate::set_default(3, MyDate::mar, 1970);
  }

  {
    // Method 4: using the usual member access.
    Chrono::Date d;
    d.set_default(3, Chrono::Date::apr, 1970);
  }

  {
    using namespace Chrono;
    Date::set_default(2, Date::apr, 1970);
  }

  return 0;

}
