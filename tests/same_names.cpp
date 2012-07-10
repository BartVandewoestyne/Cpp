/**
 * This example demonstrates how a private member variable and a function
 * cannot have the same name.
 *
 * Compiling this gives the error:
 *
 *   error: declaration of ‘int Test::number’
 *   error: conflicts with previous declaration ‘int Test::number() const’
 */

class Test {

  public:
    int number() const {
      return 1;
    }

  private:
    // Change this to number2 to make it work.
    int number;

};
