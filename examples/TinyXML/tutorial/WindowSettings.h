#ifndef WINDOW_SETTINGS_H
#define WINDOW_SETTINGS_H

#include <string>
using namespace std;

// a basic window abstraction - demo purposes only
class WindowSettings
{
public:
  int x,y,w,h;
  string name;

  WindowSettings()
    : x(0), y(0), w(100), h(100), name("Untitled")
  {
  }

  WindowSettings(int x, int y, int w, int h, const string& name)
  {
    this->x=x;
    this->y=y;
    this->w=w;
    this->h=h;
    this->name=name;
  }
};

#endif /* WINDOW_SETTINGS_H */
