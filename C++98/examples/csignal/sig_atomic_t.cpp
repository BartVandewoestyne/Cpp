/*
 * Key ideas:
 *
 *   - std::sig_atomic_t is an integer type which can be accessed as an atomic
 *     entity even in the presence of asynchronous interrupts made by signals.
 *
 *   - Until C++11, which introduced std::atomic and std::atomic_signal_fence,
 *     about the only thing a strictly conforming program could do in a signal
 *     handler was to assign a value to a volatile static std::sig_atomic_t
 *     variable and promptly return.
 *
 * References:
 *
 *   [cppreference] std::sig_atomic_t
 *     https://en.cppreference.com/w/cpp/utility/program/sig_atomic_t
 *
 *   [javatpoint] C++ Signal Handling
 *     https://www.javatpoint.com/cpp-signal-handling
 *
 *   [singh20210620] C++ csignal Introduction
 *     https://cppsecrets.com/users/687811710010511657495264103109971051084699111109/C00-csignal-Introduction.php
 */

#include <csignal>  
#include <iostream>  
   
namespace  
{  
  volatile std::sig_atomic_t gSignalStatus;  
}  
   
void signal_handler(int signal)  
{  
  gSignalStatus = signal;  
}  
   
int main()  
{  
  // Install a signal handler  
  std::signal(SIGINT, signal_handler);  
   
  std::cout << "SignalValue: " << gSignalStatus << '\n';  
  std::cout << "Sending signal " << SIGINT << '\n';  
  std::raise(SIGINT);  
  std::cout << "SignalValue: " << gSignalStatus << '\n';  
}
