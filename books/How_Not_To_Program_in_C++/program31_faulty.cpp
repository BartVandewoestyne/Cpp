/************************************************
 * printer status -- Print the status of the    *
 *     printer.                                 *
 ************************************************/
#include <iostream>

/*
 * Printer status information.
 */
struct status {
    // True if the printer is on-line
    int on_line:1;

    // Is the printer ready
    int ready:1;

    // Got paper
    int paper_out:1;

    // Waiting for manual feed paper
    int manual_feed:1;
};

int main()
{
    // Current printer status
    status printer_status;

    // Tell the world we're on-line
    printer_status.on_line = 1;

    // Are we on-line?
    if (printer_status.on_line == 1)
        std::cout << "Printer is on-line\n";
    else
        std::cout << "Printer down\n";
    return (0);
}
