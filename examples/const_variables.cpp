int main() {

  int  x = 4;        // A normal variable that can be modified.
  x = 10;            // Legal

  const int y = 2;   // A const var can be initialized, not modified thereafter.
  y = 10;            // error - cannot modify const variable

  return 0;
}
