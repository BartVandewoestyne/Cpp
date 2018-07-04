#include <cstdio>
#include "AppSettings.h"

int main(void)
{
  // block: customise and save settings
  {
    AppSettings settings;
    settings.m_name="HitchHikerApp";
    settings.m_messages["Welcome"]="Don't Panic";
    settings.m_messages["Farewell"]="Thanks for all the fish";
    settings.m_windows.push_back(WindowSettings(15,25,300,250,"BookFrame"));
    settings.m_connection.ip="192.168.0.77";
    settings.m_connection.timeout=42.0;

    settings.save("appsettings2.xml");
  }
  
  // block: load settings
  {
    AppSettings settings;
    settings.load("appsettings2.xml");
    printf("%s: %s\n", settings.m_name.c_str(), 
      settings.m_messages["Welcome"].c_str());
    WindowSettings & w=settings.m_windows.front();
    printf("%s: Show window '%s' at %d,%d (%d x %d)\n", 
      settings.m_name.c_str(), w.name.c_str(), w.x, w.y, w.w, w.h);
    printf("%s: %s\n", settings.m_name.c_str(), settings.m_messages["Farewell"].c_str());
  }
  return 0;
}
