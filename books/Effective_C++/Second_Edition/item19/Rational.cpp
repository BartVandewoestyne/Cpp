#include "Rational.h"

Rational::Rational(int numerator, int denominator)
  : m_numerator(numerator), m_denominator(denominator)
{}

int Rational::numerator() const
{
  return m_numerator;
}

int Rational::denominator() const
{
  return m_denominator;
}

const Rational operator*(const Rational& lhs,
                         const Rational& rhs)
{
  return Rational(lhs.numerator() * rhs.numerator(),
                  lhs.denominator() * rhs.denominator());
}
