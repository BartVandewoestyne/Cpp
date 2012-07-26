/**
 * Compile with:
 *
 *   g++ -std=c++0x async01.cpp -lpthread
 *
 * References:
 *
 *   [1] http://www.reddit.com/r/cpp/comments/wvd1g/problem_with_stdasync_under_ubuntu/
 *   [2] http://www.justsoftwaresolutions.co.uk/threading/multithreading-in-c++0x-part-8-futures-and-promises.html
 */
#include <future>
#include <iostream>

int calculate_the_answer_to_LtUaE()
{
    return 42;
}

void do_stuff()
{
    std::cout << "doing stuff" << std::endl;
}

int main()
{
    //std::future<int> the_answer = std::async(calculate_the_answer_to_LtUaE);
    auto the_answer = std::async(calculate_the_answer_to_LtUaE);

    do_stuff();

    //the_answer.wait(); // Don't bother waiting, get already blocks waiting for
                         // the result!

    std::cout<<"The answer to life, the universe and everything is "
             << the_answer.get() << std::endl;
}
