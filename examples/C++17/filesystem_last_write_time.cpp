#include <experimental/filesystem>  // TODO: remove 'experimental'
#include <fstream>
#include <iostream>

namespace fs = std::experimental::filesystem;  // TODO: remove 'experimental'
using namespace std::chrono_literals;

int main()
{
    fs::path path = fs::current_path() / "rainer.txt";
    std::ofstream(path.c_str());
    auto ftime = fs::last_write_time(path); // (1)

    auto cftime = std::chrono::system_clock::to_time_t(ftime); // (2)

    std::cout << "Write time on server " // (3)
              << std::asctime(std::localtime(&cftime));

    std::cout << "Write time on server " // (4)
              << std::asctime(std::gmtime(&cftime)) << std::endl;

    fs::last_write_time(path, ftime + 2h); // (5)
    ftime = fs::last_write_time(path); // (6)

    cftime = std::chrono::system_clock::to_time_t(ftime);
    std::cout << "Local time on client "
              << std::asctime(std::localtime(&cftime)) << std::endl;
}
