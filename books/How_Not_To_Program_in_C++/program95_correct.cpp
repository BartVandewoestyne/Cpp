/************************************************
 * hello -- write hello using our message system*
 *       to the log file and the screen.        *
 ************************************************/
#include <iostream>
#include <fstream>

// The log file
std::ofstream log_file("prog.log");

/************************************************
 * print_msg_one -- Write a message to the      *
 *      given file.                             *
 ************************************************/
void print_msg_one(
    // File to write the message to
    std::ostream& out_file,

    // Where to send it
    const char msg[]
) {
    out_file << msg << std::endl;
}
/************************************************
 * print_msg -- send a message to the console   *
 *      and to the log file.                    *
 ************************************************/
void print_msg(
    const char msg[]     // Message to log
) {
    print_msg_one(std::cout, msg);
    print_msg_one(log_file, msg);
}
int main()
{
    print_msg("Hello World!");
    return (0);
}
