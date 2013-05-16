// TODO: check if this is correct.  Since this exercise is in the section on
//       constexpr, I would expect the solution to have something to do with
//       constexpr.

// error: invalid conversion from ‘int’ to ‘int*’
//int null = 0, *p = null;

// Legal version:
int null = 0, *p = &null;
