#include <vector>
using std::vector;

int main()
{
    // Preferred way to do it.
    vector<int> vec1(10, 42);

    // List initialize.
    vector<int> vec2 = {42, 42, 42, 42, 42, 42, 42, 42, 42, 42};
    vector<int> vec3{42, 42, 42, 42, 42, 42, 42, 42, 42, 42};

    // Using push_back.
    vector<int> vec4;
    for (int i = 0; i < 10; ++i)
    {
        vec4.push_back(42);
    }
}
