/**
 * Example that demonstrates operations on complex matrices.
 *
 * TODO: find a good way to compute the determinant and inverse.
 */
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>

int main () {

    using namespace boost::numeric::ublas;

    matrix<std::complex<double> > m1(3, 3);
    matrix<std::complex<double> > m2(3, 3);

    for (unsigned i = 0; i < m1.size1(); ++i)
        for (unsigned j = 0; j < m1.size2(); ++j)
            m1(i, j) = std::complex<double> (3*i + j, 3*i + j);

    for (unsigned i = 0; i < m2.size1 (); ++ i)
        for (unsigned j = 0; j < m2.size2 (); ++ j)
            m2(i, j) = std::complex<double> (4*i + j, 5*i + j);

    // Additive inverse.
    std::cout << -m1 << std::endl;

    // Complex conjugate.
    std::cout << conj(m1) << std::endl;

    // Real part.
    std::cout << real(m1) << std::endl;

    // Imaginary part.
    std::cout << imag(m1) << std::endl;

    // Transpose.
    std::cout << trans(m1) << std::endl;

    // Hermitian (complex conjugate of the transpose).
    std::cout << herm(m1) << std::endl;

    // Complex matrix product.
    std::cout << prod(m1, m2) << std::endl;

    // Determinant???
    // http://www.anderswallin.net/2010/05/matrix-determinant-with-boostublas/
    // http://boost.2283326.n4.nabble.com/How-to-compute-determinant-td2710896.html
    // http://stackoverflow.com/questions/1419681/boost-library-how-to-get-determinant-from-lu-factorize

    // Inverse???
    // http://www.crystalclearsoftware.com/cgi-bin/boost_wiki/wiki.pl?LU_Matrix_Inversion
    // http://www.crystalclearsoftware.com/cgi-bin/boost_wiki/wiki.pl?Effective_UBLAS/Matrix_Inversion

}
