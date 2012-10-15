/**
 * 3-5. Write a program that will keep track of grades for several students at once. The
 * program could keep two vectors in sync: The first should hold the student's names, and
 * the second the final grades that can be computed as input is read. For now, you should
 * assume a fixed number of homework grades. We'll see in §4.1.3/56 how to handle a variable
 * number of grades intermixed with student names.
 */
 
#include <cstdio>
#include <iostream>
#include <vector>

int main()
{
  std::vector<std::string> student_names;
  std::vector<double> student_grades;

  std::string name;
  while (std::cout << "Enter student name: ", std::cin >> name)
  {
    student_names.push_back(name);
    std::cout << "  Enter grades for " << name << ": " << std::endl;;
    unsigned int count = 0;
    double grade;
    while (count < 5)
    {
      std::cout << "    Enter grade " << count + 1 << ": ";
      std::cin >> grade;
      student_grades.push_back(grade);
      count++;
    }
  }

  unsigned int nb_students = 0;
  for (std::vector<std::string>::const_iterator it=student_names.begin();
      it < student_names.end(); it++)
  {
    nb_students += 1;
    std::cout << "Grades for " << *it << ":" << std::endl;;

    for (std::vector<double>::size_type global_index = (nb_students-1)*5;
         global_index < nb_students*5;
         global_index++)
    {
      std::cout << "  " << student_grades[global_index] << std::endl;
    }

  }
}
