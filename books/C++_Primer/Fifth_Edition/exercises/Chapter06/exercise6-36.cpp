// TODO: check this!

#include <string>

int main()
{
    // An array of 10 strings.
    std::string arr[10] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j"};

    std::string (&func())[10] = arr;
}
