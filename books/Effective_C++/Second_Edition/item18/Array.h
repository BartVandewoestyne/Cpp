#include <vector>
using namespace std;

template<class T>
class Array {

public:
    enum BoundsCheckingStatus {NO_CHECK_BOUNDS = 0,
                               CHECK_BOUNDS = 1};

    Array(int lowBound, int highBound,
          BoundsCheckingStatus check = NO_CHECK_BOUNDS);

    Array(const Array& rhs);

    ~Array();

    Array& operator=(const Array& rhs);

    // return element for read/write
    T& operator[](int index);

    // return element for read-only
    const T& operator[](int index) const;

    // best to only provide these on the assumption that assignment can modify
    // the bounds of an object.
    int lowBound() const;
    int highBound() const;

    // TODO: define operator<< function for objects of type T.

private:
    int lBound, hBound;         // low bound, high bound
    vector<T> data;             // contents of array; see
                                // Item 49 for vector info
    BoundsCheckingStatus checkingBounds;

};
