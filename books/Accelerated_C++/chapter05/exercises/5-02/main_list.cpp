/**
 * References:
 *
 *   [1] http://bytes.com/topic/c/answers/167496-accelerated-c-clarification-wording-exercises
 */
#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <list>
#include <ctime>
#include "grade.h"
#include "Student_info.h"
#include "extract_fails.h"

using std::cin;                     using std::setprecision;
using std::cout;                    using std::sort;
using std::domain_error;            using std::streamsize;
using std::endl;                    using std::string;
using std::max;                     using std::list;


// Write the names and grades of the students.
void write_names_and_grades(
        list<Student_info>& students,
        string::size_type maxlen
        )
{
    for (list<Student_info>::const_iterator it = students.begin();
         it != students.end();
         ++it)
    {
        cout << it->name
             << string(maxlen + 1 - it->name.size(), ' ');

        // Compute and write the grade.
        try {
            double final_grade = grade(*it);
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade
                 << setprecision(prec);
        } catch (domain_error e) {
            cout << e.what();
        }
        cout << endl;
    }
}


int main()
{
    list<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;  // The length of the longest name.

    // Read and store all the students' data.
    // Invariant:
    //   - `students' contains all the student records read so far
    //   - `maxlen' contains the length of the longest name in `students'
    while (read(cin, record)) {
        // Find length of longest name.
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }

    // Extract failed students.
    clock_t start_time = clock();
    list<Student_info> fails = extract_fails4(students);
    clock_t elapsed_time = clock() - start_time;

    // Alphabetize the student records.
    //sort(students.begin(), students.end(), compare); // TODO: sort for list!!!

    std::cout << "Passed students:" << std::endl;
    write_names_and_grades(students, maxlen);
    std::cout << "Failed students:" << std::endl;
    write_names_and_grades(fails, maxlen);

    cout << "Elapsed CPU time for failed student extraction: "
         << (double)elapsed_time/CLOCKS_PER_SEC << " seconds." << endl;

    return 0;
}
