#include <iostream>

void printIt(const char* months[], const int nbMonths)
{
  for (int i = 0; i < nbMonths; i++)
  {
    std::cout << months[i] << std::endl;
  }
}


int main()
{
  const int nbMonths = 2;
  const char* myArray[nbMonths] = {"January", "February"};

  for (int i = 0; i < nbMonths; i++)
  {
    std::cout << myArray[i] << std::endl;
  }

  printIt(myArray, nbMonths);
}
