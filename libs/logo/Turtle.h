#ifndef TURTLE_H
#define TURTLE_H

class Turtle
{
public:
  // ...
  virtual ~Turtle() = default;
  virtual void penUp() = 0;
  virtual void penDown() = 0;
  virtual void forward(int distance) = 0;
  virtual void turn(int degrees) = 0;
  virtual void goTo(int x, int y) = 0;
  virtual int getX() const = 0;
  virtual int getY() const = 0;
};

#endif // TURTLE_H
