#include "Turtle.h"

#include "gmock/gmock.h"  // Brings in gMock.

class MockTurtle : public Turtle {
 public:
  
  // TODO: check if the
  MockTurtle() = default;
  ~MockTurtle() override = default;

  MOCK_METHOD(void, PenUp, (), (override));
  MOCK_METHOD(void, PenDown, (), (override));
  MOCK_METHOD(void, Forward, (int distance), (override));
  MOCK_METHOD(void, Turn, (int degrees), (override));
  MOCK_METHOD(void, GoTo, (int x, int y), (override));
  MOCK_METHOD(int, GetX, (), (const, override));
  MOCK_METHOD(int, GetY, (), (const, override));
};
