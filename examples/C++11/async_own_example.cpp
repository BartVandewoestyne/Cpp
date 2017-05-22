/*
 * My own example on std::async in combination with std::futures.
 * Code needs to be reviewed by others to check if I don't do anything stupid.
 *
 * References:
 *
 *   [1] http://sc13.supercomputing.org/sites/default/files/prog105/prog105.pdf
 */

#include <chrono>
#include <future>
#include <iostream>
#include <string>
#include <vector>

std::mutex g_mutex;

std::string f(const int n)
{
    std::string n_string = std::to_string(n);

    g_mutex.lock();
    std::cout << "at start of thread " << std::this_thread::get_id()
              << " that takes " << n_string << " seconds." << std::endl;
    g_mutex.unlock();

    std::this_thread::sleep_for(std::chrono::seconds(n));

    g_mutex.lock();
    std::cout << "at end of thread " << std::this_thread::get_id()
              << " that took " << n_string << " seconds." << std::endl;
    g_mutex.unlock();

    return "Hello from " + n_string + ".";
}

int main()
{
    std::vector<std::future<std::string>> futures;

    for (const auto& s : {1, 5})
    {
        futures.push_back(std::async(std::launch::async, f, s));
    }

    for (auto& f: futures)
    {
        const auto s = f.get();
        std::cout << s << std::endl;
    }
}
