#ifndef PAINTER_H
#define PAINTER_H

#include "Turtle.h"

#include <iostream>

class Painter
{
public:
    Painter(Turtle* turtle) : mTurtle(turtle) {}

    bool DrawCircle(int x, int y, int radius)
    {
        // TODO: implement DrawCircle
        mTurtle->penDown();
        return true;
    }

    bool moveForward100()
    {
        mTurtle->forward(100);
        //mTurtle->forward(100);
        return true;
    }

    bool ThreeTimesWithSpecifiedReturn()
    {
        mTurtle->getX();
        mTurtle->getX();
        mTurtle->getX();
        mTurtle->getX();
        return true;
    }

    void DrawLineSegment()
    {
        mTurtle->penDown();
        mTurtle->forward(100);
        mTurtle->penUp();
    }

    void demoNaggyBehavior()
    {
        mTurtle->getX();
        mTurtle->getY();
    }

private:
    Turtle* mTurtle;

};

#endif  // PAINTER_H