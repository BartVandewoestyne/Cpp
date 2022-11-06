/*
 * Key idea:
 *
 *   When needed, thread local data will be created for each thread.
 *   thread-local data exclusively belongs to the thread and behaves like
 *   static data. That means it will be created at its first usage and its
 *   lifetime is bound to the lifetime of the thread.
 *
 * References:
 *
 *   [stackoverflow] What does the thread_local mean in C++11?
 *     https://stackoverflow.com/questions/11983875/what-does-the-thread-local-mean-in-c11
 *
 *   [grimm20160520] Thread-Local Data
 *     https://www.modernescpp.com/index.php/thread-local-data
 */

#include <iostream>
#include <string>
#include <mutex>
#include <thread>

std::mutex coutMutex;

thread_local std::string s("hello from ");

void addThreadLocal(std::string const& s2)
{
  s += s2;

  std::lock_guard<std::mutex> guard(coutMutex);
  std::cout << s << std::endl;
  std::cout << "&s: " << &s << std::endl;
  std::cout << std::endl;
}

int main()
{
  std::thread t1(addThreadLocal,"t1"); 
  std::thread t2(addThreadLocal,"t2"); 
  std::thread t3(addThreadLocal,"t3"); 
  std::thread t4(addThreadLocal,"t4"); 

  t1.join();
  t2.join();
  t3.join();
  t4.join();
}
