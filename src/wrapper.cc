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

bool operator||(const mynum::number_t &x, const mynum::number_t &y)
{
  return is_one(x) || is_one(y);
}

bool operator&&(const mynum::number_t &x, const mynum::number_t &y)
{
  return is_one(x) && is_one(y);
}

bool operator!(const mynum::number_t &x)
{
  return !is_one(x);
}

bool operator<(const mynum::number_t &x, const mynum::number_t &y)
{
  return (cmp(x, y) == -1);
}

bool operator<=(const mynum::number_t &x, const mynum::number_t &y)
{
  return ((cmp(x, y) == -1) || (cmp(x, y) == 0));
}

bool operator>(const mynum::number_t &x, const mynum::number_t &y)
{
  return (cmp(x, y) == 1);
}

bool operator>=(const mynum::number_t &x, const mynum::number_t &y)
{
  return ((cmp(x, y) == 1) || (cmp(x, y) == 0));
}

bool operator==(const mynum::number_t &x, const mynum::number_t &y)
{
  return (cmp(x, y) == 0);
}

bool operator!=(const mynum::number_t &x, const mynum::number_t &y)
{
  return (cmp(x, y) != 0);
}
