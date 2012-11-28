/*
 * Compile with:
 *
 *   g++ -c main1.cpp -I../chapter04
 */

#include <list>
#include "grade.h"
#include "Student_info.h"

using namespace std;

// predicate to determine whether a student failed
bool fgrade(const Student_info& s)
{
    return grade(s) < 60;
}

// first try
// separate passing and failing student records: first try
//vector<Student_info> extract_fails(vector<Student_info>& students)
//{
//    vector<Student_info> pass, fail;
//    for (vector<Student_info>::size_type i = 0;
//        i != students.size(); ++i)
//       if (fgrade(students[i]))
//           fail.push_back(students[i]);
//       else
//           pass.push_back(students[i]);
//    students = pass;
//    return fail;
//}

// second try: correct but potentially slow
//vector<Student_info> extract_fails(vector<Student_info>& students)
//{
//    vector<Student_info> fail;
//    vector<Student_info>::size_type i = 0;
//
//    // invariant:elements [0, i) of students represent passing grades
//    while (i != students.size()) {
//        if (fgrade(students[i])) {
//            fail.push_back(students[i]);
//            students.erase(students.begin() + i);
//        } else
//            ++i;
//    }
//    return fail;
//}

// version 3: iterators but no indexing; still potentially slow
//vector<Student_info> extract_fails(vector<Student_info>& students)
//{
//    vector<Student_info> fail;
//    vector<Student_info>::iterator iter = students.begin();
//    while (iter != students.end()) {
//        if (fgrade(*iter)) {
//            fail.push_back(*iter);
//            iter = students.erase(iter);
//        } else
//            ++iter;
//    }
//    return fail;
//}

// version 4: use list instead of vector
list<Student_info> extract_fails(list<Student_info>& students)
{
    list<Student_info> fail;
    list<Student_info>::iterator iter = students.begin();

    while (iter != students.end()) {
        if (fgrade(*iter)) {
            fail.push_back(*iter);
            iter = students.erase(iter);
        } else
            ++iter;
    }
    return fail;
}
