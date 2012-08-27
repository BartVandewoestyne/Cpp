/**
 * References:
 *
 *   [1] http://blog.smartbear.com/software-quality/bid/210923/c11-tutorial-new-constructor-features-that-make-object-initialization-faster-and-smoother
 *
 * TODO: currently does not seem to compile with g++ 4.6.2.
 */
class M
{

  int j = 5;        // in-class initializer
  bool flag(false); //another in-class initializer

public:

  M();

};

M m1; // m1.j = 5, m1.flag = false
