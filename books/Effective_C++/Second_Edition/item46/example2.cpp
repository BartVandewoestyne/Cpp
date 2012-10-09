enum Month { Jan = 1, Feb = 2, Mar = 3, Apr = 4, May = 5, Jun = 6,
             Jul = 7, Aug = 8, Sep = 9, Oct = 10, Nov = 11, Dec = 12 };

class Date {
public:
  Date(int day, Month month, int year);
};


int main()
{
  Month m;
  Date d(22, m, 1857);      // m is undefined
}
