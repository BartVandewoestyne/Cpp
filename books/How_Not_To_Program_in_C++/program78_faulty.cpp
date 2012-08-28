/************************************************
 * paper_size -- Find the usable width on       *
 *      a page.                                 *
 ************************************************/
#define PAPER_WIDTH 8.5; // Width of the page
#define MARGIN      1.0; // Total margins
// Usable space on the page
#define USABLE      PAPER_WIDTH -MARGIN;

#include <iostream>

int main()
{
    // The usable width
    double text_width = USABLE;

    std::cout << "Text width is " <<
        text_width << '\n';
    return (0);
}
