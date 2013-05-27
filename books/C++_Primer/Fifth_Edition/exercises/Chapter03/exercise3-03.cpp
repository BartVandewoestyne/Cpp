/**
 * Handling of whitespace
 * ----------------------
 *
 * string input operator:
 *
 *   - Reads and discards any leading whitespace (e.g., spaces, newlines, tabs).
 *     Then reads characters until the next whitespace character is encountered.
 *     So, "   Hello World!   " becomes "Hello".
 *
 * getline:
 *
 *   - Does not ignore the whitespace in our input.
 *   - Reads the given stream up to and including the first newline and stores
 *     what it read, NOT including the newline, in its string argument.
 *     After getline sees a newline, even if it is the first character in the
 *     input, it stops reading and returns.  If the first character in the input
 *     is a newline, then the resulting string is the empty string.
 */
