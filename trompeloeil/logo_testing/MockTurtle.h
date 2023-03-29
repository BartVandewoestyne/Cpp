#include <catch2/catch_all.hpp>
#include <catch2/trompeloeil.hpp>

#include "Turtle.h"

class MockTurtle : public Turtle
{
public:
    ~MockTurtle() override = default;

    MAKE_MOCK0(penUp, void(), override);
    MAKE_MOCK0(penDown, void(), override);
    MAKE_MOCK1(forward, void(int), override);
    MAKE_MOCK1(turn, void(int), override);
    MAKE_MOCK2(goTo, void(int, int), override);
    MAKE_MOCK0(getX, int(), const override);
    MAKE_MOCK0(getY, int(), const override);
};