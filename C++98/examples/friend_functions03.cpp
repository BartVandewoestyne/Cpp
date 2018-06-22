/**
 * Example illustrating how a function can be a friend of more than one class
 * at the same time.
 *
 * Reference:
 *
 * http://www.learncpp.com/cpp-tutorial/813-friend-functions-and-classes/
 */

#include <iostream>

class Humidity;
 

class Temperature
{

  private:
    int m_nTemp;

  public:
    Temperature(int nTemp) { m_nTemp = nTemp; }
    friend void PrintWeather(Temperature &cTemperature, Humidity &cHumidity);
};
 

class Humidity
{
  private:
    int m_nHumidity;

  public:
    Humidity(int nHumidity) { m_nHumidity = nHumidity; }
    friend void PrintWeather(Temperature &cTemperature, Humidity &cHumidity);
};
 

void PrintWeather(Temperature &cTemperature, Humidity &cHumidity)
{
  std::cout << "The temperature is " << cTemperature.m_nTemp <<
      " and the humidity is " << cHumidity.m_nHumidity << std::endl;
}
