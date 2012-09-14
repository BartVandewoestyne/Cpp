#include <iostream>
#include <string>
using namespace std;

class Window {
public:
  string name() const {
    return "WindowName";
  }
  virtual void display() const {
    cout << "Window::display()" << endl;
  }
};

class WindowWithScrollBars: public Window {
public:
  virtual void display() const {
    cout << "WindowWithScrollBars::display()" << endl;
  }
};

//void printNameAndDisplay(Window w) // suffers from slicing problem
void printNameAndDisplay(const Window& w) // correct version
{
  cout << w.name() << endl;
  w.display();
}

int main()
{
  WindowWithScrollBars wwsb;
  printNameAndDisplay(wwsb);
}
