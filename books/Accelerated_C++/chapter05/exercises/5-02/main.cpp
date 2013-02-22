/**
 * TODO:
 *   - cleanup code
 *   - time code
 *   - make easily changeable between vector and list
 *
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
#include <vector>
#include <ctime>
#include "grade.h"
#include "Student_info.h"
#include "extract_fails.h"

using std::cin;                     using std::setprecision;
using std::cout;                    using std::sort;
using std::domain_error;            using std::streamsize;
using std::endl;                    using std::string;
using std::max;                     using std::vector;


// Write the names and grades of the students.
void write_names_and_grades(
        vector<Student_info>& students,
        string::size_type maxlen
        )
{
    for (vector<Student_info>::size_type i = 0;
         i != students.size();
         ++i)
    {
        // Write the name, padded on the right to `maxlen' `+' `1' characters.
        cout << students[i].name
             << string(maxlen + 1 - students[i].name.size(), ' ');
        
        // Compute and write the grade.
        try {
            double final_grade = grade(students[i]);
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
    vector<Student_info> students;
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
    vector<Student_info> fails = extract_fails1(students);
    clock_t elapsed_time = clock() - start_time;

    // Alphabetize the student records.
    sort(students.begin(), students.end(), compare);

    std::cout << "Passed students:" << std::endl;
    write_names_and_grades(students, maxlen);
    std::cout << "Failed students:" << std::endl;
    write_names_and_grades(fails, maxlen);

    cout << "Elapsed CPU time for failed student extraction: "
         << elapsed_time << endl;

    return 0;
}
