class Month {
public:
  static const Month Jan() { return 1; }
  static const Month Feb() { return 2; }
  // ...
  static const Month Dec() { return 12; }
 
  int asInt() const           // for convenience, make
  { return monthNumber; }     // it possible to convert
                              // a Month to an int
private:
  Month(int number): monthNumber(number) {}
  const int monthNumber;
};


class Date {
public:
  Date(int day, const Month& month, int year);
};


int main()
{
  Month *pm;                 // define uninitialized ptr
  Date d(1, *pm, 1997);      // arghhh! use it!
}
