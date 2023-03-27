#ifndef PAINTER_H
#define PAINTER_H

#include "Turtle.h"

#include <iostream>

class Painter
{
public:
    Painter(Turtle* turtle) : mTurtle(turtle) { std::cout << "Painter() called" << std::endl; }

    bool DrawCircle(int x, int y, int radius)
    {
        std::cout << "Painter::DrawCircle called" << std::endl;
        // TODO: implement DrawCircle
        mTurtle->PenDown();
        return true;
    }

private:
    Turtle* mTurtle;

};

#endif  // PAINTER_H