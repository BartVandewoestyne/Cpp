/*
 * References:
 *
 *   [googletest] gMock for Dummies
 *     https://google.github.io/googletest/gmock_for_dummies.html
 */

#include "Painter.h"

#include "MockTurtle.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"

// Import the gMock names from the testing namespace such that you can use
// them unqualified (you only have to do it once per file).  Remember that
// namespaces are a good idea.
using ::testing::AtLeast;

TEST(PainterTest, CanDrawSomething)
{
    // Create some mock objects.
    MockTurtle turtle;

    // Specify your expectations on them (How many times will a method be called?
    // With what arguments?  What should it do? etc.)
    //
    // IMPORTANT: expectations must be set *before* the mock functions are called,
    // otherwise the behavior is undefined!  Do not alternate between calls to
    // EXPECT_CALL() and calls to the mock functions, and do not set any
    // expectations on a mock aftere passing the mock to an API.
    //
    // -> Here, we test that penDown() is called at least once.
    EXPECT_CALL(turtle, penDown()).Times(AtLeast(1));

    // Exercise some code that uses the mocks (and *optionally*, check the result
    // using googletest assertions).  If a mock method is called more than expected
    // or with wrong arguments, you'll get an error immediately.
    Painter painter(&turtle);
    EXPECT_TRUE(painter.DrawCircle(0, 0, 10));

} // When a mock is destructed, gMock will automatically check whether all
  // expectations on it have been satisfied.

TEST(SettingExpectations, IsGetXCalledFiveTimes)
{
    using ::testing::Return;

    MockTurtle turtle;

    EXPECT_CALL(turtle, getX())
            .Times(5)
            .WillOnce(Return(100))
            .WillOnce(Return(150))
            .WillRepeatedly(Return(200));

    Painter painter(&turtle);
    painter.fiveTimesGetX();
}

TEST(Matchers, DidWeMoveForward100)
{
    MockTurtle turtle;

    // Expects the turtle to move forward by 100 units.
    EXPECT_CALL(turtle, forward(100));

    Painter painter(&turtle);
    painter.moveForward100();
}

TEST(Matchers, DidWeMoveToX50)
{
    using ::testing::_;

    MockTurtle turtle;

    // Expects that the turtle jumps to somewhere on the x=50 line.
    EXPECT_CALL(turtle, goTo(50, _));

    Painter painter(&turtle);
    painter.moveToX50();
}

TEST(PainterTest, DidWeMoveForwardByAtLeast100)
{
    using ::testing::Ge;

    MockTurtle turtle;

    // Expects the turtle moves forward by at least 100.
    EXPECT_CALL(turtle, forward(Ge(100)));

    Painter painter(&turtle);
    painter.moveForwardByAtLeast100();
}

TEST(PainterTest, ArgumentsDoNotMatter)
{
    MockTurtle turtle;

    // Expects the turtle to move forward.
    EXPECT_CALL(turtle, forward);
    // Expects the turtle to jump somewhere.
    EXPECT_CALL(turtle, goTo);

    Painter painter(&turtle);
    painter.moveForwardAndGoto();
}

TEST(PainterTest, CardinalityZero)
{
    MockTurtle turtle;

    EXPECT_CALL(turtle, forward).Times(0);

    Painter painter(&turtle);
    painter.fiveTimesGetX();
}

TEST(PainterTest, ActionExactNumberOfTimes)
{
    using ::testing::Return;

    MockTurtle turtle;

    // Specify that getX will be called at least 3 times, the first times returning 100, 200 and 300
    // and if called more returning 400.
    EXPECT_CALL(turtle, getX()).WillOnce(Return(100)).WillOnce(Return(200)).WillOnce(Return(300));

    Painter painter(&turtle);
    painter.threeTimesWithSpecifiedReturn();
}

TEST(PainterTest, ActionMinimumNumberOfTimes)
{
    using ::testing::Return;

    MockTurtle turtle;

    EXPECT_CALL(turtle, getY())
            .WillOnce(Return(100))
            .WillOnce(Return(200))
            .WillRepeatedly(Return(300));

    Painter painter(&turtle);
    painter.atLeastsTwoTimesWithSpecifiedReturn();
}

TEST(PainterTest, ActionClauseIsEvaluatedOnlyOnce)
{
    using ::testing::Return;

    MockTurtle turtle;

    int n = 100;
    EXPECT_CALL(turtle, getX())
            .Times(5)
            .WillRepeatedly(Return(n++)); // The n++ is evaluated only once, so this
                                          // mock function wil always return 100.

    Painter painter(&turtle);
    painter.fiveTimesGetX();
}

TEST(PainterTest, MultipleExpectations)
{
    using ::testing::_;

    MockTurtle turtle;

    EXPECT_CALL(turtle, forward(_));
    EXPECT_CALL(turtle, forward(10)).Times(2);

    Painter painter(&turtle);
    painter.threeTimesForward();
}

TEST(PainterTest, drawLineSegment)
{
    using ::testing::InSequence;

    MockTurtle turtle;

    {
        InSequence seq;

        EXPECT_CALL(turtle, penDown());
        EXPECT_CALL(turtle, forward(100));
        EXPECT_CALL(turtle, penUp());
    }

    Painter painter(&turtle);
    painter.drawLineSegment();
}

TEST(PainterTest, StickyExpecations1)
{
    using ::testing::_;
    using ::testing::AnyNumber;

    MockTurtle turtle;

    EXPECT_CALL(turtle, goTo(_, _)).Times(AnyNumber());
    EXPECT_CALL(
            turtle,
            goTo(0, 0)) // This is a sticky expectation: the *third* time that goTo(0,0) is called
            .Times(3); // gMock will see that the arguments match this expecation and will report
                       // an error since we only expected goTo(0,0) to be called twice.

    Painter painter(&turtle);
    painter.goToOriginThreeTimes();
}

TEST(PainterTest, StickyExpecations2)
{
    using ::testing::InSequence;
    using ::testing::Return;

    MockTurtle turtle;

    {
        InSequence s;  // Note how the order is not correct if you remove this!

        int n = 3;
        for (int i = 1; i <= n; i++)
        {
            EXPECT_CALL(turtle, getX()).WillOnce(Return(10 * i)).RetiresOnSaturation();
        }
    }

    Painter painter(&turtle);
    painter.threeTimesGetXDecreasing();
}

TEST(PainterTest, DemoNaggyBehavior)
{
    // using ::testing::NiceMock;
    using ::testing::StrictMock;

    MockTurtle turtle; // warn on uninteresting calls
    // NiceMock<MockTurtle> turtle;    // suppress warnings for uninteresting calls
    // StrictMock<MockTurtle> turtle;  // give error on uninteresting calls

    // If turtle has other methods than getX, then for the other methods, you
    // will get the warning:
    //
    //   GMOCK WARNING:
    //   Uninteresting mock function call - returning default value.
    //       Function call: getY()
    //             Returns: 0
    //   NOTE: You can safely ignore the above warning unless this call should not happen.  Do not
    //   suppress it by blindly adding an EXPECT_CALL() if you don't mean to enforce the call.  See
    //   https://github.com/google/googletest/blob/main/docs/gmock_cook_book.md#knowing-when-to-expect
    //   for details.
    //
    // With StrictMock, you get this error:
    //
    //   unknown file: Failure
    //   Uninteresting mock function call - returning default value.
    //       Function call: getY()
    //             Returns: 0
    //
    EXPECT_CALL(turtle, getX()).Times(AtLeast(1));

    Painter painter(&turtle);
    painter.demoNaggyBehavior();
}

// TODO: difference between ON_CALL and EXPECT_CALL
// See http://google.github.io/googletest/gmock_cook_book.html#UseOnCall
