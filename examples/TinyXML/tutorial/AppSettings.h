#ifndef APP_SETTINGS_H
#define APP_SETTINGS_H

#include <string>
#include <list>
#include "MessageMap.h"
#include "WindowSettings.h"
#include "ConnectionSettings.h"
using namespace std;

class AppSettings
{
public:
  string m_name;
  MessageMap m_messages;
  list<WindowSettings> m_windows;
  ConnectionSettings m_connection;

  AppSettings() {}

  void save(const char* pFilename);
  void load(const char* pFilename);
  
  // just to show how to do it
  void setDemoValues()
  {
    m_name="MyApp";
    m_messages.clear();
    m_messages["Welcome"]="Welcome to "+m_name;
    m_messages["Farewell"]="Thank you for using "+m_name;
    m_windows.clear();
    m_windows.push_back(WindowSettings(15,15,400,250,"Main"));
    m_connection.ip="Unknown";
    m_connection.timeout=123.456;
  }
};

#endif /* APP_SETTINGS_H */
