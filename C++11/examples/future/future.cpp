/*
 * References:
 *
 *   [williams2012] C++ Concurrency in Action
 *     https://www.manning.com/books/c-plus-plus-concurrency-in-action
 *
 *   [petriconi2018] There Is A Better Future - Felix Petriconi [ACCU 2018]
 *     https://youtu.be/L63XGqiNuhI
 *
 *   [parent2017] Future Ruminations
 *     http://sean-parent.stlab.cc/2017/07/10/future-ruminations.html
 *
 *   [grimm2017] std::future Erweiterungen
 *     http://www.grimm-jaud.de/index.php/blog/std-future-erweiterungen
 *
 *   [varun2015] C++11 Multithreading – Part 8: std::future , std::promise and Returning values from Thread
 *     http://thispointer.com/c11-multithreading-part-8-stdfuture-stdpromise-and-returning-values-from-thread/
 */

// Example code based on Listing 4.6 and 4.7 in williams2012.

#include <future>
#include <iostream>

struct X
{
    void foo(int, std::string const&) {}
    std::string bar(std::string const&) { return std::string(); }
};

X baz(X&) { return X(); }

struct Y
{
    double operator()(double) { return 1.0; }
};

class move_only
{
public:
    move_only() {}
    move_only(move_only&&) {}
    move_only(move_only const&) = delete;
    move_only& operator=(move_only&&) { return *this; }
    move_only& operator=(move_only const&) = delete;

    void operator()() {}
};

int find_the_answer_to_ltuae()
{
  return 42;
}

void do_other_stuff()
{
}

int main()
{
    std::future<int> the_answer = std::async(find_the_answer_to_ltuae);
    do_other_stuff();
    std::cout << "The answer is " << the_answer.get() << std::endl;

    X x;
    auto f1 = std::async(&X::foo, &x, 42, "hello");  // Calls p->foo(42, "hello" where p is &x.
    auto f2 = std::async(&X::bar, x, "goodbye");  // Calls tmpx.bar("goodbye") where tmpx is a copy of x.

    Y y;
    auto f3 = std::async(Y(), 3.141);  // Calls tmpy(3.141) where tmpy is move-constructed from Y().
    auto f4 = std::async(std::ref(y), 2.718);  // Calls y(2.718)

    std::async(baz, std::ref(x));  // Calls baz(x)
    
    auto f5 = std::async(move_only());  // Calls tmp() where tmp is constructed from std::move(move_only()).

    auto f6 = std::async(std::launch::async, Y(), 1.2);  // Run in new thread
    auto f7 = std::async(std::launch::deferred, baz, std::ref(x));  // Run in wait() or get().
    auto f8 = std::async(std::launch::deferred | std::launch::async, baz, std::ref(x)); // Implementation chooses
    auto f9 = std::async(baz, std::ref(x)); // Implementation chooses
    f7.wait();  // Invoke deferred function
}
