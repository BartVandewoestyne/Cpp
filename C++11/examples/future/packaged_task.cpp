/*
 * Key ideas:
 *
 *   - Differences between std::packaged_task and std::async:
 *
 *       std::packaged_task:
 *
 *         1. Execute the task as asynchronously (create separate thread) always.
 *         2. Process the outcome of task using future object.
 *         3. Object creation of std::packaged_task will NOT start the thread (Unlike class thread), we need to trigger a separate call to start the thread.
 *         4. Move operation can be done on task.
 *
 *       std::async:
 *
 *         1. We have both options, we can execute either asynchronously (create separate thread) or synchronously (normal call to function)
 *         2. Also process the outcome of task using future object.
 *         3. Thread will be started as we trigger the call to async with std::launch::async.
 *         4. Cannot move the task
 *
 * References:
 *
 *   [stackoverflow20130809] What is the difference between packaged_task and async
 *     https://stackoverflow.com/questions/18143661/what-is-the-difference-between-packaged-task-and-async
 *
 *   [digtestcpp] std::packaged_task c++11
 *     https://digestcpp.com/cpp11/packagedtask/
 *
 *   [brotcruncher20170928] Multithreading in C++ [027] - std::packaged_task
 *     https://youtu.be/Y1xak1NzfRI
 */

// Code example from cppreference

#include <iostream>
#include <cmath>
#include <thread>
#include <future>
#include <functional>
 
// unique function to avoid disambiguating the std::pow overload set
int f(int x, int y) { return std::pow(x,y); }
 
void task_lambda()
{
    std::packaged_task<int(int,int)> task([](int a, int b) {
        return std::pow(a, b); 
    });
    std::future<int> result = task.get_future();
 
    task(2, 9);
 
    std::cout << "task_lambda:\t" << result.get() << '\n';
}
 
void task_bind()
{
    std::packaged_task<int()> task(std::bind(f, 2, 11));
    std::future<int> result = task.get_future();
 
    task();
 
    std::cout << "task_bind:\t" << result.get() << '\n';
}
 
void task_thread()
{
    std::packaged_task<int(int,int)> task(f);
    std::future<int> result = task.get_future();
 
    std::thread task_td(std::move(task), 2, 10);
    task_td.join();
 
    std::cout << "task_thread:\t" << result.get() << '\n';
}
 
int main()
{
    task_lambda();
    task_bind();
    task_thread();
}
