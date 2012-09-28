#ifndef POINT_H
#define POINT_H

// class for representing 2D points
class Point {
public:
  Point(short int xCoord, short int yCoord);
  ~Point();

 
private:
  short int x, y;
};

#endif /* POINT_H */
