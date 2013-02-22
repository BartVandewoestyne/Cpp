#ifndef GUARD_extract_fails
#define GUARD_extract_fails

#include "Student_info.h"
#include <vector>
#include <list>
using namespace std;

vector<Student_info> extract_fails1(vector<Student_info>& students);
vector<Student_info> extract_fails2(vector<Student_info>& students);
vector<Student_info> extract_fails3(vector<Student_info>& students);
list<Student_info>   extract_fails4(list<Student_info>& students);

#endif /* GUARD_extract_fails */
