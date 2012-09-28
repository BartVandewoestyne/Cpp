class Rational {          // class for rational numbers

public:

  Rational(int numerator = 0, int denominator = 1);
  ~Rational();

private:
  int n, d;               // numerator and denominator

  // notice that operator* (incorrectly) returns a reference
  friend const Rational& operator*(const Rational& lhs,
                                   const Rational& rhs);

};


//// an incorrect implementation of operator*
//inline const Rational& operator*(const Rational& lhs,
//                                 const Rational& rhs)
//{
//  Rational result(lhs.n * rhs.n, lhs.d * rhs.d);
//  return result;
//}

// another incorrect implementation of operator*
inline const Rational& operator*(const Rational& lhs,
                                 const Rational& rhs)
{
  // create a new object on the heap
  Rational *result =
    new Rational(lhs.n * rhs.n, lhs.d * rhs.d);
   // return it
  return *result;
}


int main()
{
  Rational two = 2;

  //Rational four = two * two; // same as operator*(two, two)

  // get dereferenced pointer; store it in a reference
  const Rational& four = two * two;
  delete &four; // retrieve pointer and delete it

  Rational one(1), two2(2), three(3), four2(4);
  Rational product;
  //product = one * two2 * three * four2;
  const Rational& temp1 = one * two;
  const Rational& temp2 = temp1 * three;
  const Rational& temp3 = temp2 * four;
  delete &temp1;
  delete &temp2;
  delete &temp3;
}
