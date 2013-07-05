/**
 * When we nest an if inside another if, it is possible that there will be more
 * if branches than else branches.  The question arises: How do we know to which
 * if a given else belongs?
 *
 * In C++ the ambiguity is resolved by specifying that each else is matched with
 * the closest preceding unmatched if.
 */
