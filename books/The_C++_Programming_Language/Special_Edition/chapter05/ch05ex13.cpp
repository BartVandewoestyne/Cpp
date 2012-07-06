#include <iostream>

using namespace std;

struct Date
{
  int day;
  int month;
  int year;
};


Date readDate()
{
  Date d;

  cin >> d.day;
  cin >> d.month;
  cin >> d.year;

  return d;
}


void printDate(Date* d)
{
  cout << "day = " << d->day << endl;;
  cout << "month = " << d->month << endl;
  cout << "year = " << d->year << endl;
}


Date initDate(int day, int month, int year)
{
  Date d;

  d.day = day;
  d.month = month;
  d.year = year;

  return d;
}


int main()
{
  Date d;

  d = readDate();
  printDate(&d);
}
