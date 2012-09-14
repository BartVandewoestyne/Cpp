class Rational {
public:
  Rational(int numerator = 0, int denominator = 1);
 
private:
  int n, d;              // numerator and denominator
 
friend
  const Rational                     // see Item 21 for why
    operator*(const Rational& lhs,    // the return value is
              const Rational& rhs);   // const
};

// The GOOD way to do it!
inline const Rational operator*(const Rational& lhs, const Rational& rhs)
{
  return Rational(lhs.n * rhs.n, lhs.d * rhs.d);
}

// The first WRONG way to write this function.
//inline const Rational& operator*(const Rational& lhs, const Rational& rhs)
//{
//  // result is created on the STACK
//  Rational result(lhs.n * rhs.n, lhs.d * rhs.d);
//  return result;
//}

// The second WRONG way to write this function:
//    * we still have to pay for a constructor call here.
//    * who will apply delete to the object that was constructed???
//      -> This is a memory leak
//inline const Rational& operator*(const Rational& lhs, const Rational& rhs)
//{
//  Rational *result =
//    new Rational(lhs.n * rhs.n, lhs.d * rhs.d);
//  return *result;
//}

// The third WRONG way to write this function:
//   * still need to invoke Rational constructor to give result the correct
//     value...
//inline const Rational& operator*(const Rational& lhs, const Rational& rhs)
//{
//  static Rational result;      // static object to which a
//                               // reference will be returned
// 
//  //somehow multiply lhs and rhs and put the
//  //resulting value inside result;
// 
//  return result;
//}
