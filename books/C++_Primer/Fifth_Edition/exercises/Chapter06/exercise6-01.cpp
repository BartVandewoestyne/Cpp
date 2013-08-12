/*
 * Arguments are the initializers for a function's parameters.  The first
 * argument initializes the first parameter, the second argument initializes the
 * second parameter, and so on.  Although we know which argument initializes
 * which parameter, we have no guarantees about the order in which arguments are
 * evaluated.  The compiler is free to evaluate the arguments in whatever order
 * it prefers.
 *
 * The type of each argument must match the corresponding parameter in the same
 * way that the type of any initializer must match the type of the object it
 * initializes.  We must pass exactly the same number of arguments as the
 * function has parameters.  Because every call is guaranteed to pass as many
 * arguments as the function has parameters, parameters are always initialized.
 */
