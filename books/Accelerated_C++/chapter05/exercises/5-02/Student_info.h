#ifndef GUARD_Student_info
#define GUARD_Student_info

#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

struct Student_info {
    std::string name;
    double midterm, final;
    std::vector<double> homework;
};

bool compare(const Student_info&, const Student_info&);
std::istream& read(std::istream&, Student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);

vector<Student_info> extract_fails1(vector<Student_info>& students);
vector<Student_info> extract_fails2(vector<Student_info>& students);
vector<Student_info> extract_fails3(vector<Student_info>& students);
list<Student_info> extract_fails4(list<Student_info>& students);

#endif
