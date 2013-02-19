/**
 * Self-written program that illustrates how the assigment of a vector to
 * another vector removes all elements of the original vector.
 */

#include <vector>
#include <iostream>

int main()
{
    std::vector<int> v1;
    std::vector<int> v2;

    v1.push_back(1);
    v1.push_back(2);

    v2.push_back(1);

    std::cout << v1.size() << std::endl;
    v1 = v2; // all original elements of v1 are removed here!
    std::cout << v1.size() << std::endl;
}
