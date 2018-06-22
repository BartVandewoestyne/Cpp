/*
 * Program that illustrates how to calculate the mean of a std::deque.
 *
 * TODO:
 *   - check if we dan do it even more elegantly, i only quickly googled this
 *   - check if there exists a mean function that we can use???
 */

#include <numeric>
#include <iostream>
#include <deque>

int main()
{
    std::deque<double> d;
    d.push_back(1.0);
    d.push_back(2.0);
    d.push_back(3.0);

    double mean = std::accumulate(d.begin(), d.end(), 0.0) / d.size();

    std::cout << "mean = " << mean << std::endl;
}
