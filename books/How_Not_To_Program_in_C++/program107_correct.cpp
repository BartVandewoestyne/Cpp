/***********************************************
 * clear port -- Clear the input port.         *
 ***********************************************/
// Input register
volatile char *const in_port_ptr =
        (char *)0xFFFFFFE0;

// Output register
volatile char *const out_port_ptr =
        (char *)0xFFFFFFE1;

/***********************************************
 * clear_input -- Clear the input device by    *
 *      reading enough characters to empty the *
 *      buffer. (It doesn't matter if we read  *
 *      extra, just so long as we read enough.)*
 ***********************************************/
void clear_input(void)
{
    char ch;    // Dummy character

    ch = *in_port_ptr;  // Grab data
    ch = *in_port_ptr;  // Grab data
    ch = *in_port_ptr;  // Grab data
}
