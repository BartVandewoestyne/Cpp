#include <catch2/catch_all.hpp>
#include <catch2/trompeloeil.hpp>

#include "Painter.h"

#include "MockTurtle.h"

TEST_CASE("PainterTest")
{
    MockTurtle turtle;

    SECTION("CanDrawSomething")
    {
        REQUIRE_CALL(turtle, penDown()).TIMES(AT_LEAST(1));

        Painter painter(&turtle);
        CHECK(painter.DrawCircle(0, 0, 10));
    }
}

TEST_CASE("SettingExpectations")
{
    MockTurtle turtle;

    SECTION("IsGetXCalledFiveTimes")
    {
        REQUIRE_CALL(turtle, getX()).RETURN(100);
        REQUIRE_CALL(turtle, getX()).RETURN(150);
        REQUIRE_CALL(turtle, getX()).TIMES(3).RETURN(200);

        Painter painter(&turtle);
        painter.fiveTimesGetX();
    }
}

TEST_CASE("Matchers")
{
    MockTurtle turtle;

    SECTION("DidWeMoveForward100")
    {
        // Expects the turtle to move forward by 100 units.
        REQUIRE_CALL(turtle, forward(100));

        Painter painter(&turtle);
        painter.moveForward100();
    }

    SECTION("DidWeMoveToX50")
    {
        using trompeloeil::_;

        // Expects that the turtle jumps to somewhere on the x=50 line.
        REQUIRE_CALL(turtle, goTo(50, _));

        Painter painter(&turtle);
        painter.moveToX50();
    }

    SECTION("DidWeMoveForwardByAtLeast100")
    {
        using trompeloeil::ge;

        // Expects the turtle moves forward by at least 100.
        REQUIRE_CALL(turtle, forward(ge(100)));

        Painter painter(&turtle);
        painter.moveForwardByAtLeast100();
    }

    SECTION("ArgumentsDoNotMatter")
    {
        using trompeloeil::_;

        // Expects the turtle to move forward.
        REQUIRE_CALL(turtle, forward(_));
        // Expects the turtle to jump somewhere.
        // REQUIRE_CALL(turtle, goTo(ANY(int), ANY(int)));  // if type is ambiguous
        REQUIRE_CALL(turtle, goTo(_, _));

        Painter painter(&turtle);
        painter.moveForwardAndGoto();
    }
}

TEST_CASE("PainterTest", "[sequence]")
{
    MockTurtle turtle;

    SECTION("drawLineSegment")
    {
        trompeloeil::sequence seq;

        REQUIRE_CALL(turtle, penDown()).IN_SEQUENCE(seq);
        REQUIRE_CALL(turtle, forward(100)).IN_SEQUENCE(seq);
        REQUIRE_CALL(turtle, penUp()).IN_SEQUENCE(seq);

        Painter painter(&turtle);
        painter.drawLineSegment();
    }
}

TEST_CASE("PainterTest", "[naggy_behavior]")
{
    MockTurtle turtle;

    SECTION("DemoNaggyBehavior")
    {
        trompeloeil::sequence seq;

        REQUIRE_CALL(turtle, getX()).TIMES(AT_LEAST(1)).RETURN(123);
        REQUIRE_CALL(turtle, getY()).TIMES(AT_LEAST(1)).RETURN(123);

        Painter painter(&turtle);
        painter.demoNaggyBehavior();
    }
}