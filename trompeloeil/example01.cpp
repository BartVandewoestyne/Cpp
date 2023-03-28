#include <catch2/catch_all.hpp>
#include <catch2/trompeloeil.hpp>

class Mock
{
public:
  MAKE_MOCK1(func, void(const char*));
};

void func(Mock* m)
{
  m->func("begin foo end");
}

TEST_CASE("FooBar")
{
  Mock m;
  REQUIRE_CALL(m, func(trompeloeil::re("^begin.*end$")));
  func(&m);
  // expectation must be met before end of scope
}
