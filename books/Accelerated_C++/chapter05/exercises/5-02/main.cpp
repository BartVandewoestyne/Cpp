/**
 * TODO:
 *   - cleanup code
 *   - time code
 *   - make easily changeable between vector and list
 */
#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "grade.h"
#include "Student_info.h"

using std::cin;                     using std::setprecision;
using std::cout;                    using std::sort;
using std::domain_error;            using std::streamsize;
using std::endl;                    using std::string;
using std::max;                     using std::vector;


// write the names and grades
void write_names_and_grades(vector<Student_info>& students, string::size_type maxlen) {

    for (vector<Student_info>::size_type i = 0;
         i != students.size(); ++i) {
    
    	// write the name, padded on the right to `maxlen' `+' `1' characters
    	cout << students[i].name
    	     << string(maxlen + 1 - students[i].name.size(), ' ');
    
    	// compute and write the grade
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
	string::size_type maxlen = 0;       // the length of the longest name

	// read and store all the students' data.
	// Invariant:	`students' contains all the student records read so far
	//			`maxlen' contains the length of the longest name in `students'
	while (read(cin, record)) {
		// find length of longest name
		maxlen = max(maxlen, record.name.size());
		students.push_back(record);
	}

        // Extract failed students.
        vector<Student_info> fails = extract_fails1(students);

	// alphabetize the student records
	sort(students.begin(), students.end(), compare);

        std::cout << "Passed students:" << std::endl;
        write_names_and_grades(students, maxlen);
        std::cout << "Failed students:" << std::endl;
        write_names_and_grades(fails, maxlen);

	return 0;
}
