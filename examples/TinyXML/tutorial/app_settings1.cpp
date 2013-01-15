#include "AppSettings.h"

int main(void)
{
  AppSettings settings;
  
  settings.save("appsettings2.xml");
  settings.load("appsettings2.xml");
  return 0;
}
