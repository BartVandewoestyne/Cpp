#include <assert.h>

class Rectangle {
public:
  virtual void setHeight(int newHeight);
  virtual void setWidth(int newWidth);
 
  virtual int height() const;          // return current
  virtual int width() const;           // values
 };

class Square: public Rectangle { };
 
void makeBigger(Rectangle& r)          // function to
{                                      // increase r's area
  int oldHeight = r.height();
 
  r.setWidth(r.width() + 10);          // add 10 to r's width
 
  assert(r.height() == oldHeight);     // assert that r's
}                                      // height is unchanged

int main()
{
  Square s;
  
  assert(s.width() == s.height());      // this must be true
                                        // for all squares
   
  makeBigger(s);                        // by inheritance, s
                                        // isa Rectangle, so
                                        // we can increase its
                                        // area
  
  assert(s.width() == s.height());      // this must still be
                                        // true for all squares
}
