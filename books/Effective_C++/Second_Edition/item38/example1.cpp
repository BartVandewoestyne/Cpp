enum ShapeColor { RED, GREEN, BLUE };

 // a class for geometric shapes
class Shape {
public:
  // all shapes must offer a function to draw themselves
  virtual void draw(ShapeColor color = RED) const = 0;
};


class Rectangle: public Shape {
public:
  // notice the different default parameter value - bad!
  virtual void draw(ShapeColor color = GREEN) const;
};


class Circle: public Shape {
public:
  virtual void draw(ShapeColor color) const;
};


int main()
{
  Shape *ps;                      // static type = Shape*
  Shape *pc = new Circle;         // static type = Shape*
  Shape *pr = new Rectangle;      // static type = Shape*

  ps = pc;                        // ps's dynamic type is
                                  // now Circle*
   
  ps = pr;                        // ps's dynamic type is
                                  // now Rectangle*

  pc->draw(RED);                  // calls Circle::draw(RED)

  pr->draw(RED);                  // calls Rectangle::draw(RED)

  pr->draw();                     // calls Rectangle::draw(RED)!
}
