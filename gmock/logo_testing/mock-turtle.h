#include "Turtle.h"

#include "gmock/gmock.h"  // Brings in gMock.

class MockTurtle : public Turtle {
 public:
  
  // TODO: check if the
  MockTurtle() = default;
  ~MockTurtle() override = default;

  MOCK_METHOD(void, penUp, (), (override));
  MOCK_METHOD(void, penDown, (), (override));
  MOCK_METHOD(void, forward, (int distance), (override));
  MOCK_METHOD(void, turn, (int degrees), (override));
  MOCK_METHOD(void, goTo, (int x, int y), (override));
  MOCK_METHOD(int, getX, (), (const, override));
  MOCK_METHOD(int, getY, (), (const, override));
};
