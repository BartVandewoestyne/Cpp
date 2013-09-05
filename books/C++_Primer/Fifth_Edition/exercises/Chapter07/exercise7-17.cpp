/*
 * What, if any, are the differences between using class or struct?
 *
 * -> The only difference between struct and class is the default access level.
 *    A class ma define members before the first access specifier.  Access to
 *    such members depends on how the class is defined.  If we use the struct
 *    keyword, the members defined before the first access specifier are public;
 *    if we use class, then the members are private.
 */
