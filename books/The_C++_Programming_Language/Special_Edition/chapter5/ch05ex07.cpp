#include <iostream>

struct Month {
  const char* name;
  int nbDays;
};

int main ()
{

  const char* months[] = {
    "January",   "February", "March",    "April",
    "May",       "June",     "July",     "August",
    "September", "October",  "November", "December"};

  const int nbDays[] = {
    31, 28, 31, 30,
    31, 30, 31, 31,
    30, 31, 30, 31
  };

  Month months2[] = {
    {"January",   31},
    {"February",  28},
    {"March",     31},
    {"April",     30},
    {"May",       31},
    {"June",      30},
    {"July",      31},
    {"August",    31},
    {"September", 30},
    {"October",   31},
    {"November",  30},
    {"December",  31}};

  int N = 0;

  std::cout << "Method 1:" << std::endl;
  N = sizeof(nbDays)/sizeof(31);
  for (int i = 0; i < N; i++)
  {
    std::cout << months[i] << " has " << nbDays[i] << " days." << std::endl;
  }

  std::cout << "Method 2:" << std::endl;
  N = sizeof(months2)/sizeof(Month);
  for (int i = 0; i < N; i++)
  {
    std::cout << months2[i].name << " has " << months2[i].nbDays << " days." << std::endl;
  }

}
