/**
 * References:
 *
 *   [1] http://solarianprogrammer.com/2012/10/14/cpp-11-timing-code-performance/
 * TODO:
 *   This doesn't seem to compile with g++ 4.6.2...
 */

#include <iostream>
#include <chrono>

using namespace std;

int main(){
    cout << "system_clock" << endl;
    cout << chrono::system_clock::period::num << endl;
    cout << chrono::system_clock::period::den << endl;
    cout << "steady = " << boolalpha
                        << chrono::system_clock::is_steady << endl
                                                           << endl;

    cout << "high_resolution_clock" << endl;
    cout << chrono::high_resolution_clock::period::num << endl;
    cout << chrono::high_resolution_clock::period::den << endl;
    cout << "steady = " << boolalpha
                        << chrono::high_resolution_clock::is_steady << endl
                                                                    << endl;

    cout << "steady_clock" << endl;
    cout << chrono::steady_clock::period::num << endl;
    cout << chrono::steady_clock::period::den << endl;
    cout << "steady = " << boolalpha
                        << chrono::steady_clock::is_steady << endl << endl;


    auto start = chrono::steady_clock::now();
    //  Insert the code that will be timed
    auto end = chrono::steady_clock::now();

    // Store the time difference between start and end
    auto diff = end - start;


    // Print the time difference between start and end.
    cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;
    cout << chrono::duration <double, nano> (diff).count() << " ns" << endl;
    const auto diff_sec = chrono::duration_cast<chrono::nanoseconds>(diff);
    cout << diff_sec.count() << endl;

    return 0;    
}
