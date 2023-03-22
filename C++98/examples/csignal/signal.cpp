/*
 * References:
 *
 *   [tutorialspoint] C++ Signal Handling
 *     https://www.tutorialspoint.com/cplusplus/cpp_signal_handling.htm
 */

#include <iostream>
#include <csignal>
#include <cstdlib>


void signalHandler(int signum)
{
   std::cout << "Interrupt signal (" << signum << ") received.\n";

   // cleanup and close up stuff here  
   // terminate program  

   std::exit(signum);  
}

int main ()
{
    // register signal SIGINT and signal handler  
    std::signal(SIGINT, signalHandler);  

    while (true)
    {
       std::cout << "Going to sleep..." << std::endl;
    }

    return 0;
}
