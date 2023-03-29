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

    void fiveTimesGetX() const
    {
        std::cout << "Turtle::getX() called and it returned " << mTurtle->getX() << std::endl;
        std::cout << "Turtle::getX() called and it returned " << mTurtle->getX() << std::endl;
        std::cout << "Turtle::getX() called and it returned " << mTurtle->getX() << std::endl;
        std::cout << "Turtle::getX() called and it returned " << mTurtle->getX() << std::endl;
        std::cout << "Turtle::getX() called and it returned " << mTurtle->getX() << std::endl;
    }

    void moveForward100()
    {
        mTurtle->forward(100);
    }

    void moveToX50()
    {
        mTurtle->goTo(50, 123);
    }

    void moveForwardByAtLeast100()
    {
        mTurtle->forward(123);
    }

    void moveForwardAndGoto()
    {
        mTurtle->forward(123);
        mTurtle->goTo(123, 456);
    }

    void threeTimesWithSpecifiedReturn()
    {
        std::cout << "Turtle::getX() called and it returned " << mTurtle->getX() << std::endl;
        std::cout << "Turtle::getX() called and it returned " << mTurtle->getX() << std::endl;
        std::cout << "Turtle::getX() called and it returned " << mTurtle->getX() << std::endl;
    }

    void atLeastsTwoTimesWithSpecifiedReturn()
    {
        std::cout << "Turtle::getY() called and it returned " << mTurtle->getY() << std::endl;
        std::cout << "Turtle::getY() called and it returned " << mTurtle->getY() << std::endl;
        std::cout << "Turtle::getY() called and it returned " << mTurtle->getY() << std::endl;
        std::cout << "Turtle::getY() called and it returned " << mTurtle->getY() << std::endl;
    }

    void threeTimesForward()
    {
        mTurtle->forward(10);
        mTurtle->forward(10);
        mTurtle->forward(20);
    }

    void drawLineSegment()
    {
        mTurtle->penDown();
        mTurtle->forward(100);
        mTurtle->penUp();
    }

    void goToOriginThreeTimes()
    {
        mTurtle->goTo(0, 0);
        mTurtle->goTo(0, 0);
        mTurtle->goTo(0, 0);
    }

    void threeTimesGetXDecreasing()
    {
        std::cout << "Turtle::getX() called and it returned " << mTurtle->getX() << std::endl;
        std::cout << "Turtle::getX() called and it returned " << mTurtle->getX() << std::endl;
        std::cout << "Turtle::getX() called and it returned " << mTurtle->getX() << std::endl;
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