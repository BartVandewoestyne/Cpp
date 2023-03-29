#include "Painter.h"

#include "mock-turtle.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"

// Import the gMock names from the testing namespace such that you can use
// them unqualified (you only have to do it once per file).  Remember that
// namespaces are a good idea.
using ::testing::AtLeast;                         // #1

TEST(PainterTest, CanDrawSomething) {

  // Create some mock objects.
  MockTurtle turtle;                              // #2

  // Specify your expectations on them (How many times will a method be called?
  // With what arguments?  What should it do? etc.)
  // IMPORTANT: expectations must be set *before* the mock functions are called,
  // otherwise the behavior is undefined!  Do not alternate between calls to
  // EXPECT_CALL() and calls to the mock functions, and do not set any
  // expectations on a mock aftere passing the mock to an API.
  // -> Here, we test that PenDown() is called at least once.
  EXPECT_CALL(turtle, PenDown())                  // #3
      .Times(AtLeast(1));

  // Exercise some code that uses the mocks; *optionally*, check the result
  // using googletest assertions.  if a mock method is calledmore than expected
  // or with wrong arguments, you'll get an error immediately.
  Painter painter(&turtle);                       // #4
  EXPECT_TRUE(painter.DrawCircle(0, 0, 10));      // #5

}  // When a mock is destructed, gMock will automatically check whether all
   // expectations on it have been satisfied.

TEST(PainterTest, MoveForward100)
{
  MockTurtle turtle;

  EXPECT_CALL(turtle, Forward(100));

  Painter painter(&turtle);
  EXPECT_TRUE(painter.moveForward100());
}

TEST(PainterTest, SpecifyActions)
{
  using ::testing::Return;

  MockTurtle turtle;

  // Specify that GetX will be called at least 3 times, the first times returning 100, 200 and 300 and if called more returning 400.
  EXPECT_CALL(turtle, GetX())
    .WillOnce(Return(100))
    .WillOnce(Return(200))
    .WillOnce(Return(300))
    .WillRepeatedly(Return(400));

  Painter painter(&turtle);
  EXPECT_TRUE(painter.ThreeTimesWithSpecifiedReturn());
}

TEST(PainterTest, DrawLineSegment)
{
  using ::testing::InSequence;

  MockTurtle turtle;

  {
    InSequence seq;

    EXPECT_CALL(turtle, PenDown());
    EXPECT_CALL(turtle, Forward(100));
    EXPECT_CALL(turtle, PenUp());
  }

  Painter painter(&turtle);
  painter.DrawLineSegment();  
}

TEST(PainterTest, DemoNaggyBehavior)
{
  //using ::testing::NiceMock;
  using ::testing::StrictMock;

  MockTurtle turtle;              // warn on uninteresting calls
  //NiceMock<MockTurtle> turtle;    // suppress warnings for uninteresting calls
  //StrictMock<MockTurtle> turtle;  // give error on uninteresting calls

  // If turtle has other methods than GetX, then for the other methods, you
  // will get the warning:
  //
  //   GMOCK WARNING:
  //   Uninteresting mock function call - returning default value.
  //       Function call: GetY()
  //             Returns: 0
  //   NOTE: You can safely ignore the above warning unless this call should not happen.  Do not suppress it by blindly adding an EXPECT_CALL() if you don't mean to enforce the call.  See https://github.com/google/googletest/blob/main/docs/gmock_cook_book.md#knowing-when-to-expect for details.
  //
  // With StrictMock, you get this error:
  //
  //   unknown file: Failure
  //   Uninteresting mock function call - returning default value.
  //       Function call: GetY()
  //             Returns: 0
  //
  EXPECT_CALL(turtle, GetX())
    .Times(AtLeast(1));

  Painter painter(&turtle);
  painter.demoNaggyBehavior();
}

// TODO: difference between ON_CALL and EXPECT_CALL
// See http://google.github.io/googletest/gmock_cook_book.html#UseOnCall
