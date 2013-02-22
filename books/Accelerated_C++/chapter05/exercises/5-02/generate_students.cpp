/**
 * Program to generate a (random) grades file for Exercise 5-2.
 */

#include <sstream>
#include <iostream>
#include <cstdlib>

unsigned int generate_random_grade(unsigned int M, unsigned int N)
{
    // See http://c-faq.com/lib/randrange.html
    return M + rand() / (RAND_MAX / (N - M + 1) + 1);
}


int main(int argc, char* argv[])
{
    unsigned int nbStudents;
    unsigned int nbCourses;
    std::stringstream streamStudents(argv[1]);
    std::stringstream streamCourses(argv[2]);
    streamStudents >> nbStudents;
    streamCourses >> nbCourses;

    for (unsigned int i = 1; i <= nbStudents; ++i)
    {
        std::cout << "Student" << i;
        for (unsigned int j = 1; j <= nbCourses; ++j)
        {
            std::cout << " " << generate_random_grade(0, 100);
        }
        std::cout << std::endl;
    }
}
