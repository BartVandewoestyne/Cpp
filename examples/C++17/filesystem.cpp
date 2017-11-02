/*
 * References:
 *
 *   [grimm2017cpplibrary] The C++ Standard Library, Second Edition, Rainer Grimm.
 *
 *   [grimm2017byte_and_filesystem] C++17: std::byte und std::filesystem
 *     http://www.grimm-jaud.de/index.php/blog/c-17-std-byte-und-std-filesystem
 */

#include <experimental/filesystem>  // TODO: change this, once support is there.
#include <fstream>
#include <iostream>
#include <string>

int main()
{
    namespace fs = std::experimental::filesystem;  // TODO: change this, once support is there.

    std::cout << "Current path: " << fs::current_path() << std::endl; // (1)

    std::string dir = "sandbox/a/b";
    fs::create_directories(dir); // (2)

    std::ofstream("sandbox/file1.txt");
    fs::path symPath = fs::current_path() /= "sandbox"; // (3)
    symPath /= "syma";
    fs::create_symlink("a", "symPath"); // (4)

    std::cout << "fs::is_directory(dir): " << fs::is_directory(dir) << std::endl;
    std::cout << "fs::exists(symPath): " << fs::exists(symPath) << std::endl;
    std::cout << "fs::symlink(symPath): " << fs::is_symlink(symPath) << std::endl;

    for (auto& p: fs::recursive_directory_iterator("sandbox"))  // (5)
    {
        std::cout << p << std::endl;
    }
    fs::remove_all("sandbox");
}
