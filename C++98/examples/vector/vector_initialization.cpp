// This is my own attempt to try to find a way to initialize
// a vector in a similar way as with C++11 initializer lists.
// TODO: finish this, init_vect1 is not working because arraySize
// is incorrect due to the incorrect sizeof.
//
// https://stackoverflow.com/questions/2236197/what-is-the-easiest-way-to-initialize-a-stdvector-with-hardcoded-elements

#include <iostream>
#include <vector>

template <typename T, std::size_t N>
inline std::size_t size_of_array( const T [N] ) {
   return N;
}

template <typename T>
std::vector<T> init_vec1(const T arr[])
{
    // TODO: how to get the size???
    //const size_t arraySize = sizeof(*arr)/sizeof(arr[0]);
    const std::size_t arraySize = size_of_array(arr);
    std::cout << "arraySize = " << arraySize << std::endl;

    std::vector<T> v(arr, arr + arraySize);
    return v;
}

template <typename T>
std::vector<T> init_vec2(const T arr[], int N)
{
    std::vector<T> v(arr, arr + N);
    return v;
}

int main()
{
    // Works in C++11.
    // std::vector<int> v = {1, 2, 3};

    const int a[] = {1, 2, 3};
    std::vector<int> va = init_vec1(a);

    const float b[] = {1.0, 2.0, 3.0};
    std::vector<float> vb = init_vec2(b, 3);
}
