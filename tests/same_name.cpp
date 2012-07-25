/**
 * Example that illustrates that a member variable cannot have the same name
 * as a member function.
 *
 * References:
 *
 *   [1] http://stackoverflow.com/questions/467815/class-method-and-variable-with-same-name-compile-error-in-c-not-in-java
 */
class Test {

  private:
      //int length;    // doesn't work
      int m_length;  // does work

  public:
      int length() const {
          //return length;    // doesn't work
          return m_length;  // does work
      }

};

