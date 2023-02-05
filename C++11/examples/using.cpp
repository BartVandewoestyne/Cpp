/*
 * Key ideas:
 *   - SF.7 don't write using namespace at global scope in a header file.
 *
 * References:
 *
 *   [dargo20220920] The 4 use of using in C++
 *     https://www.sandordargo.com/blog/2022/04/27/the-4-use-of-using-in-cpp
 */

// 1. type aliasing with using

using Horsepower = int;
using Iterator = std::vector<std::string>::iterator

template<typename T>
using MapT = std::map<int, T>  // OK (error with typedef)

// 2. introducing complete namespaces with using-directive

using mcs = mynamespace::component::subcomponent;

// 3. introducing members of another namespace with using-declaration

// 4. importing class members with using-declaration

class ClassUnterTest {
 public:
  virtual void testMe() {
  }

  virtual void testMeToo() {
  }
};

class MockClassUnderTest : public ClassUnderTest {
 public:
  using ClassUnderTest::testMe;
  using ClassUnderTest::testMeToo;
};
