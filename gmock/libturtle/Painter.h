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
        mTurtle->PenDown();
        return true;
    }

    bool moveForward100()
    {
        mTurtle->Forward(100);
        //mTurtle->Forward(100);
        return true;
    }

    bool ThreeTimesWithSpecifiedReturn()
    {
        mTurtle->GetX();
        mTurtle->GetX();
        mTurtle->GetX();
        mTurtle->GetX();
        return true;
    }

    void DrawLineSegment()
    {
        mTurtle->PenDown();
        mTurtle->Forward(100);
        mTurtle->PenUp();
    }

    void demoNaggyBehavior()
    {
        mTurtle->GetX();
        mTurtle->GetY();
    }

private:
    Turtle* mTurtle;

};

#endif  // PAINTER_H