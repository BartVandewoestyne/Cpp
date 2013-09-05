/*
 * a) What, if any, are the constraints on where and how often an access
 *    specifier may appear inside a class definition?
 *
 *    -> A class may contain zero or more access specifiers, and there are no
 *    restrictions on how often an access specifier may appear.  Each access
 *    specifier specifies the access level of the succeeding members.  The
 *    specified access level remains in effect until the next access specifier
 *    or the end of the class body.
 *
 * b) What kinds of members should be defined after a public specifier?
 *
 *    -> The constructors and member functions that are pare of the interface.
 *
 * c) What kinds should be private?
 *
 *    -> The data members and the functions that are part of the implementation.
 */
