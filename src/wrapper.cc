#include <mynum/mynum.h>

mynum::number_t operator+(const mynum::number_t &x, const mynum::number_t &y)
{
  return mynum::add(x, y);
}

mynum::number_t operator-(const mynum::number_t &x, const mynum::number_t &y)
{
  return mynum::sub(x, y);
}

mynum::number_t operator*(const mynum::number_t &x, const mynum::number_t &y)
{
  return mynum::mul(x, y);
}

mynum::number_t operator/(const mynum::number_t &x, const mynum::number_t &y)
{
  return mynum::div(x, y);
}

mynum::number_t operator%(const mynum::number_t &x, const mynum::number_t &y)
{
  return mynum::mod(x, y);
}
