#include <string>
#include <vector>

using std::string;
using std::vector;

int main()
{
    vector<string>::iterator iter;

    // (a) LEGAL: this is equivalent to *(iter++).  The subexpression iter++
    // increments iter and yields a copy of the previous value of iter as its
    // result.  Accordingly, the operand of * is the unincremented value of
    // iter.  Thus, the statement dereferences the element to which iter
    // originally pointed and increments iter.
    *iter++;

    // (b) error: no ‘operator++(int)’ declared for postfix ‘++’
    //(*iter)++;

    // (c) error: ‘std::vector<std::basic_string<char> >::iterator’ has no
    // member named ‘empty’
    //*iter.empty();

    // (d) LEGAL
    iter->empty();

    // (e) error: no match for ‘operator++’ in
    // ‘++iter.__gnu_cxx::__normal_iterator<_Iterator,
    // _Container>::operator*<std::basic_string<char>*,
    // std::vector<std::basic_string<char> > >()’
    //++*iter;

    // (f) LEGAL: first check if the currently pointed to string is empty() and
    // then increment iter.
    iter++->empty();
}
