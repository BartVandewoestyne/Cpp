/************************************************
 * check -- Very simple checkbook program.      *
 *                                              *
 * Allows you to add entries to your checkbook  *
 * and displays the total each time.            *
 *                                              *
 * Restrictions: Will never replace Quicken.    *
 ************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <cstdlib>

/************************************************
 * check_info -- Information about a single     *
 *      check                                   *
 ************************************************/
class check_info {
    public:
        // Date the check was written
        std::string date;

        // What the entry is about
        std::string what;

        // Amount of check or deposit
        float amount;
    public:
        check_info():
            date(""),
            what(""),
            amount(0.00)
        {};
        // Destructor defaults
        // Copy constructor defaults
        // Assignment operator defaults
    public:
        void read(std::istream &in_file);
        void print(std::ostream &out_file);
};

// The STL vector to hold the check data
typedef std::vector<check_info> check_vector;

/************************************************
 * check_info::read -- Read the check           *
 *      information from a file.                *
 *                                              *
 * Warning: Minimal error checking              *
 ************************************************/
void check_info::read(
    std::istream &in_file       // File for input
) {
    std::getline(in_file, date);
    std::getline(in_file, what);
    in_file >> amount;
    in_file.ignore(); // Finish the line
}
/************************************************
 * check_info::print -- Print the check         *
 *      information to a report.                *
 ************************************************/
void check_info::print(
    std::ostream &out_file      // File for output
) {
    out_file <<
        std::setiosflags(std::ios::left) <<
        std::setw(10) << date <<
        std::setw(50) << what <<
        std::resetiosflags(std::ios::left) <<
        std::setw(8) << std::setprecision(2) <<
        std::setiosflags(std::ios::fixed) <<
        amount << std::endl;
}

int main()
{
    // Checkbook to test
    check_vector checkbook;

    // File to read the check data from
    std::ifstream in_file("checks.txt");

    if (in_file.bad()) {
        std::cerr << "Error opening input file\n";
        exit (8);
    }
    while (1) {
        check_info next_info;  // Current check

        next_info.read(in_file);
        if (in_file.fail())
            break;

        checkbook.push_back(next_info);
    }
    double total = 0.00;    // Total in the bank
    for (check_vector::iterator
            cur_check = checkbook.begin();
         cur_check != checkbook.end();
         cur_check++)
    {
         cur_check->print(std::cout);
         total += cur_check->amount;
    }
    std::cout << "Total " << std::setw(62) <<
        std::setprecision(2) <<
        total << std::endl;
    return (0);
}
