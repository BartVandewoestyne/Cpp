#ifndef RATIONAL_H
#define RATIONAL_H

class Rational {
public:
  Rational(int numerator = 0, int denominator = 1);
  int numerator() const;
  int denominator() const;

  // If we define it as a mamber, we don't have commutativity.
  // Better make it a friend!
  //const Rational operator*(const Rational& rhs) const;

private:
  int m_numerator;
  int m_denominator;

};

const Rational operator*(const Rational& lhs,
                         const Rational& rhs);

#endif /* RATIONAL_H */
