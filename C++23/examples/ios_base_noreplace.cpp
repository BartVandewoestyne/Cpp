/*
 * References:
 *
 *   [cppreference] std::ios_base::openmode
 *     https://en.cppreference.com/w/cpp/io/ios_base/openmode
 *
 *   [lavavej20230602] MSVC C++23 Update
 *     https://youtu.be/Dk_C_E8AtRs?t=2574
 */

#include <exception>
#include <filesystem>
#include <fstream>
#include <iostream>

using namespace std;

const auto filename = "noreplace_example.txt";

void test() {
    ofstream f{filename, ios_base::noreplace};
    if (f) {
        f << "Cats!\n";
        cout << "Created output file!\n";
    } else {
        cout << "Output file already exists!\n";
    }
}

int main() {
    try {
        filesystem::remove(filename);
        test();
        test();
        filesystem::remove(filename);
    } catch (const exception& e) {
        cout << e.what() << "\n";
    }
}
