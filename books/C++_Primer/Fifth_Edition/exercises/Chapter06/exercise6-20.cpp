/*
 * Use reference to const for parameters that a function does not change.
 *
 * When you make it a plain reference:
 *
 *   - you give the function's caller the misleading impression that the
 *     function might change its argument's value.
 *
 *   - you also limit the type of arguments that can be used with the function.
 *     You cannot pass a const object, or a literal, or an object that requires
 *     conversion to a plain reference parameter.
 */
