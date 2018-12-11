#include "complex.h"
#include <cmath>

std::ostream& operator<<(std::ostream &os, const complex &c)
{
  return os << "re:" << c._re << " im:" << c._im;
}

complex::complex(double re, double im) : _re(re), _im(im)
{}

complex complex::operator+(const complex &c) const
{
  complex tmp(*this);
  return tmp += c;
}

complex complex::operator-(const complex &c) const
{
  complex tmp(*this);
  return tmp -= c;
}

complex complex::operator*(const complex &c) const
{
  complex tmp(*this);
  return tmp *= c;
}

const complex& complex::operator+=(const complex &c)
{
  _re += c._re;
  _im += c._im;
  return *this;
}

const complex& complex::operator-=(const complex &c)
{
  _re -= c._re;
  _im -= c._im;
  return *this;
}

const complex& complex::operator*=(const complex &c)
{
  double r = _re*c._re - _im*c._im;
  _im = _im*c._re + _re*c._im;
  _re = r;
  return *this;
}

bool complex::operator<(const complex &c) const
{
  return abs() < c.abs();
}

bool complex::operator>(const complex &c) const
{
  return abs() > c.abs();
}

bool complex::operator<=(const complex &c) const
{
  return abs() <= c.abs();
}

bool complex::operator>=(const complex &c) const
{
  return abs() >= c.abs();
}

bool complex::operator==(const complex &c) const
{
  return (_re == c._re) && (_im == c._im);
}

double complex::abs() const
{
  return sqrt(_re*_re + _im*_im);
}
