#include <stdio.h>
#include <vector>
#include <algorithm>

template< class I > struct XRange {

    typedef I value_type;
    typedef I difference_type;
    struct iterator 
        : std::iterator<std::random_access_iterator_tag,I,I>
    {
        value_type i;
        constexpr iterator( value_type i ) : i(i) { }

        constexpr value_type operator* () { return i; }

        iterator operator++ () { return ++i; }
        iterator operator++ (int) { return i++; }

        iterator operator-- () { return --i; }
        iterator operator-- (int) { return i--; }

        // Return an iterator when added to. (Random access requirement.)
        constexpr iterator operator+ ( difference_type n ) { return i + n; }
        constexpr iterator operator- ( difference_type n ) { return i - n; } 

        // it - it = the distance between two iterators. (Random access req.)
        constexpr difference_type operator- ( iterator other ) { return i - *other; }

        constexpr bool operator== ( iterator other ) { return i == *other; }
        constexpr bool operator!= ( iterator other ) { return i != *other; }

        // Random access also requires += and -=
        iterator& operator+= ( iterator other ) {
            i += *other;
            return *this;
        }

        iterator& operator-= ( iterator other ) {
            i -= *other;
            return *this;
        }
    };

    iterator b, e;

    constexpr XRange( value_type b, value_type e ) : b(b), e(e) { }
    constexpr XRange( iterator b, iterator e ) : b(b), e(e) { }

    constexpr iterator begin() { return b; }
    constexpr iterator end()   { return e; }
    constexpr value_type size() { return e - b; }
};

typedef XRange<unsigned int> IRange;
constexpr IRange enumerate( unsigned int b, unsigned int e ) {
    return IRange( b, e + 1 );
}

int main() {

    for( unsigned int x : enumerate(1,10) )
    {
        printf( "%d ", x );
    }
    puts("");

}
