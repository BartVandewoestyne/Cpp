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
