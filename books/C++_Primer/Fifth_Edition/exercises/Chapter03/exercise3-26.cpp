#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::string;

int main()
{
    vector<string> text = {"Jake", "Melvin", "Jan", "Bart", "Melissa", "Xavier"};
    string sought("Bart");

    // text must be sorted
    // beg and end will denote the range we're searching
    auto beg = text.begin(), end = text.end();
    auto mid = text.begin() + (end - beg)/2; // original midpoint
    
    // while there are still elements to look at and we haven't yet found sought
    while (mid != end && *mid != sought) {
        if (sought < *mid)            // is the element we want in the first half
            end = mid;                // if so, adjust the range to ignore the second half
        else                          // the element we want is in the second half
            beg = mid + 1;            // start looking with the element just after mid
        mid = beg + (end - beg)/2;    // new midpoint
        //mid = (beg + end)/2;        // error: no match for ‘operator+’ in ‘beg + end’

                                      // Note that we do not use
                                      //   mid = (beg + end)/2
                                      // here because the resulting
                                      // iterator must refer to elements in, or
                                      // one off the end of the vector.
                                      // There is also no operator+ defined for iterators.
    }

    if (*mid == sought)
    {
        cout << "Found " << *mid << " at index " << mid-beg << "." << endl;
    }
    else
    {
        cout << "Dit not find " << sought << "." << endl;
    }
}
