/*
 * Notes:
 *
 *   1) According to [sutter199801XX], it seems like std::valarray is redundant
 *   and could use revision or removal.  Probably better not to use it.
 *
 *   2) In a recent Twitter post, Bryce Lelbach announced that
 *   he is hoping to deprecate std::valarray for C++20.
 
 * TODO: check what the alternatives to std::valarray are.  Is there something
 *       in the standard?  Does one need to use a library?
 *
 * References:
 *
 *   [lelbach20170308] Don't use valarray, I am hoping to deprecate it for C++20
 *     https://twitter.com/blelbach/status/839743137761259521
 *
 *   [mirchev20170213-19] C++ tips, 2017 Week 7 (13-Feb - 19-Feb-2017)
 *     http://dvmirchevcpp.blogspot.com/2017/03/c-tips-2017-week-7-13-feb-19-feb-2017.html?_sm_au_=iHV7p6WpZHZ6WHsj
 *
 *   [gonen20170206] Introduction To valarray
 *     http://cppisland.com/?p=518
 *
 *   [nyhoff20120803] Programming in C++ for Engineering and Science 1st Edition
 *     https://cs.calvin.edu/activities/books/c++/engr-sci/WebItems/Chap12/Valarrays.pdf
 *
 *   [josuttis2012XXXX] The C++ Standard Library - A Tutorial and Reference (Second Edition)
 *     http://www.cppstdlib.com/cppstdlib_supplementary.pdf
 *
 *   [andand20100405] What's the future of std::valarray look like?
 *     https://stackoverflow.com/questions/2576688/whats-the-future-of-stdvalarray-look-like
 *
 *   [rlbond20091021] C++ valarray vs. vector
 *     https://stackoverflow.com/questions/1602451/c-valarray-vs-vector
 *
 *   [josuttis1999XXXX] The C++ Standard Library: A Tutorial and Reference
 *     https://books.google.be/books?id=n9VEG2Gp5pkC&pg=PA547&lpg=PA547&dq=valarray&source=bl&ots=Rgj6no59OT&sig=ACfU3U3fcaxEHbjP06l5s-I89okdvT-MPA&hl=nl&sa=X&ved=2ahUKEwjNgJvb57jhAhUit3EKHYoqAkA4ChDoATACegQICBAB
 *
 *   [sutter199801XX] C++ State of the Union
 *     http://www.gotw.ca/publications/mill01.htm
 */

#include <iostream>
#include <valarray>

int main()
{
    std::valarray<int> val(10);

    // Assign -1 to all elements.
    val = -1;

    // Get minimum and maximum.
    std::cout << val.min() << std::endl;
    std::cout << val.max() << std::endl;

    // Get sum of all elements.
    std::cout << val.sum() << std::endl;

    // Perform mathematical operation on all elements.
    std::valarray<int> abs_val = std::abs(val);

    // ... and lots of other goodies.
}
