/************************************************
 * sheep -- Count sheep by counting the         *
 *            number of legs and dividing by 4. *
 ************************************************/
#include <iostream>

/*
 * The number of legs in some different
 * size herds.
 */
const int small_herd  =   100;
const int medium_herd =  1000;
const int large_herd  = 10000;

/************************************************
 * report_sheep -- Given the number of legs,    *
 *      tell us how many sheep we have.         *
 ************************************************/
static void report_sheep(
    const int legs        // Number of legs
)
{
    std::cout <<
        "The number of sheep is: " <<
                (legs/4) << std::endl;
}

int main() {
    report_sheep(small_herd*4); // Expect 100
    report_sheep(medium_herd*4);// Expect 1000
    report_sheep(large_herd*4); // Expect 10000
    return (0);
}
