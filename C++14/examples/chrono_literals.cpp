/**
 * References:
 *
 *   [boccara20211008] A Recap on User Defined Literals
 *     https://www.fluentcpp.com/2021/10/08/a-recap-on-user-defined-literals/
 *
 *   [grimm2016] Die Zeitdauer.
 *     http://www.grimm-jaud.de/index.php/blog/die-zeitdauer
 */

#include <iostream>
#include <chrono>

using namespace std::literals::chrono_literals;

int main()
{
  std::cout << std::endl;

  constexpr auto schoolHour= 45min;

  constexpr auto shortBreak= 300s;
  constexpr auto longBreak= 0.25h;

  constexpr auto schoolWay= 15min;
  constexpr auto homework= 2h;

  constexpr auto schoolDayInSeconds= 2*schoolWay + 6 * schoolHour + 4 * shortBreak + longBreak + homework;

  std::cout << "School day in seconds: " << schoolDayInSeconds.count() << std::endl;

  std::chrono::duration<double,std::ratio<3600>> schoolDayInHours = schoolDayInSeconds;
  std::chrono::duration<double,std::ratio<60>> schoolDayInMinutes = schoolDayInSeconds;
  std::chrono::duration<double,std::ratio<1,1000>> schoolDayInMilliseconds= schoolDayInSeconds;

  std::cout << "School day in hours: " << schoolDayInHours.count() << std::endl;
  std::cout << "School day in minutes: " << schoolDayInMinutes.count() << std::endl;
  std::cout << "School day in milliseconds: " << schoolDayInMilliseconds.count() << std::endl;

  std::cout << std::endl;
}
