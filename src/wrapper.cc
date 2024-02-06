#include <mynum/mynum.h>

mynum::number_t& operator>>(std::istream& in, mynum::number_t &x)
{
  std::string str;
  in >> str;
  x = mynum::__number_t(str);
  return x;
}

std::ostream& operator<<(std::ostream& out, const mynum::number_t &x)
{
  out << x.value();
  return out;
}

//
// number_t,number_t
//

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
  return !is_zero(x) || !is_zero(y);
}

bool operator&&(const mynum::number_t &x, const mynum::number_t &y)
{
  return !is_zero(x) && !is_zero(y);
}

bool operator!(const mynum::number_t &x)
{
  return is_zero(x);
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

//
// number_t,string
//

mynum::number_t operator+(const mynum::number_t &x, std::string y)
{
  return mynum::add(x, mynum::number_t(y));
}

mynum::number_t operator-(const mynum::number_t &x, std::string y)
{
  return mynum::sub(x, mynum::number_t(y));
}

mynum::number_t operator*(const mynum::number_t &x, std::string y)
{
  return mynum::mul(x, mynum::number_t(y));
}

mynum::number_t operator/(const mynum::number_t &x, std::string y)
{
  return mynum::div(x, mynum::number_t(y));
}

mynum::number_t operator%(const mynum::number_t &x, std::string y)
{
  return mynum::mod(x, mynum::number_t(y));
}

bool operator||(const mynum::number_t &x, std::string y)
{
  return !is_zero(x) || !is_zero(mynum::number_t(y));
}

bool operator&&(const mynum::number_t &x, std::string y)
{
  return !is_zero(x) && !is_zero(mynum::number_t(y));
}

bool operator<(const mynum::number_t &x, std::string y)
{
  return (cmp(x, mynum::number_t(y)) == -1);
}

bool operator<=(const mynum::number_t &x, std::string y)
{
  return ((cmp(x, mynum::number_t(y)) == -1) || (cmp(x, mynum::number_t(y)) == 0));
}

bool operator>(const mynum::number_t &x, std::string y)
{
  return (cmp(x, mynum::number_t(y)) == 1);
}

bool operator>=(const mynum::number_t &x, std::string y)
{
  return ((cmp(x, mynum::number_t(y)) == 1) || (cmp(x, mynum::number_t(y)) == 0));
}

bool operator==(const mynum::number_t &x, std::string y)
{
  return (cmp(x, mynum::number_t(y)) == 0);
}

bool operator!=(const mynum::number_t &x, std::string y)
{
  return (cmp(x, mynum::number_t(y)) != 0);
}

//
// string,number_t
//

mynum::number_t operator+(std::string x, const mynum::number_t &y)
{
  return mynum::add(mynum::number_t(x), y);
}

mynum::number_t operator-(std::string x, const mynum::number_t &y)
{
  return mynum::sub(mynum::number_t(x), y);
}

mynum::number_t operator*(std::string x, const mynum::number_t &y)
{
  return mynum::mul(mynum::number_t(x), y);
}

mynum::number_t operator/(std::string x, const mynum::number_t &y)
{
  return mynum::div(mynum::number_t(x), y);
}

mynum::number_t operator%(std::string x, const mynum::number_t &y)
{
  return mynum::mod(mynum::number_t(x), y);
}

bool operator||(std::string x, const mynum::number_t &y)
{
  return !is_zero(mynum::number_t(x)) || !is_zero(y);
}

bool operator&&(std::string x, const mynum::number_t &y)
{
  return !is_zero(mynum::number_t(x)) && !is_zero(y);
}

bool operator<(std::string x, const mynum::number_t &y)
{
  return (cmp(mynum::number_t(x), y) == -1);
}

bool operator<=(std::string x, const mynum::number_t &y)
{
  return ((cmp(mynum::number_t(x), y) == -1) || (cmp(mynum::number_t(x), y) == 0));
}

bool operator>(std::string x, const mynum::number_t &y)
{
  return (cmp(mynum::number_t(x), y) == 1);
}

bool operator>=(std::string x, const mynum::number_t &y)
{
  return ((cmp(mynum::number_t(x), y) == 1) || (cmp(mynum::number_t(x), y) == 0));
}

bool operator==(std::string x, const mynum::number_t &y)
{
  return (cmp(mynum::number_t(x), y) == 0);
}

bool operator!=(std::string x, const mynum::number_t &y)
{
  return (cmp(mynum::number_t(x), y) != 0);
}

//
// number_t,myflt_t
//

mynum::number_t operator+(const mynum::number_t &x, mynum::myflt_t y)
{
  return mynum::add(x, mynum::number_t(y));
}

mynum::number_t operator-(const mynum::number_t &x, mynum::myflt_t y)
{
  return mynum::sub(x, mynum::number_t(y));
}

mynum::number_t operator*(const mynum::number_t &x, mynum::myflt_t y)
{
  return mynum::mul(x, mynum::number_t(y));
}

mynum::number_t operator/(const mynum::number_t &x, mynum::myflt_t y)
{
  return mynum::div(x, mynum::number_t(y));
}

mynum::number_t operator%(const mynum::number_t &x, mynum::myflt_t y)
{
  return mynum::mod(x, mynum::number_t(y));
}

bool operator||(const mynum::number_t &x, mynum::myflt_t y)
{
  return !is_zero(x) || !is_zero(mynum::number_t(y));
}

bool operator&&(const mynum::number_t &x, mynum::myflt_t y)
{
  return !is_zero(x) && !is_zero(mynum::number_t(y));
}

bool operator<(const mynum::number_t &x, mynum::myflt_t y)
{
  return (cmp(x, mynum::number_t(y)) == -1);
}

bool operator<=(const mynum::number_t &x, mynum::myflt_t y)
{
  return ((cmp(x, mynum::number_t(y)) == -1) || (cmp(x, mynum::number_t(y)) == 0));
}

bool operator>(const mynum::number_t &x, mynum::myflt_t y)
{
  return (cmp(x, mynum::number_t(y)) == 1);
}

bool operator>=(const mynum::number_t &x, mynum::myflt_t y)
{
  return ((cmp(x, mynum::number_t(y)) == 1) || (cmp(x, mynum::number_t(y)) == 0));
}

bool operator==(const mynum::number_t &x, mynum::myflt_t y)
{
  return (cmp(x, mynum::number_t(y)) == 0);
}

bool operator!=(const mynum::number_t &x, mynum::myflt_t y)
{
  return (cmp(x, mynum::number_t(y)) != 0);
}

//
// myflt_t,number_t
//
mynum::number_t operator+(mynum::myflt_t x, const mynum::number_t &y)
{
  return mynum::add(mynum::number_t(x), y);
}

mynum::number_t operator-(mynum::myflt_t x, const mynum::number_t &y)
{
  return mynum::sub(mynum::number_t(x), y);
}

mynum::number_t operator*(mynum::myflt_t x, const mynum::number_t &y)
{
  return mynum::mul(mynum::number_t(x), y);
}

mynum::number_t operator/(mynum::myflt_t x, const mynum::number_t &y)
{
  return mynum::div(mynum::number_t(x), y);
}

mynum::number_t operator%(mynum::myflt_t x, const mynum::number_t &y)
{
  return mynum::mod(mynum::number_t(x), y);
}

bool operator||(mynum::myflt_t x, const mynum::number_t &y)
{
  return !is_zero(mynum::number_t(x)) || !is_zero(y);
}

bool operator&&(mynum::myflt_t x, const mynum::number_t &y)
{
  return !is_zero(mynum::number_t(x)) && !is_zero(y);
}

bool operator<(mynum::myflt_t x, const mynum::number_t &y)
{
  return (cmp(mynum::number_t(x), y) == -1);
}

bool operator<=(mynum::myflt_t x, const mynum::number_t &y)
{
  return ((cmp(mynum::number_t(x), y) == -1) || (cmp(mynum::number_t(x), y) == 0));
}

bool operator>(mynum::myflt_t x, const mynum::number_t &y)
{
  return (cmp(mynum::number_t(x), y) == 1);
}

bool operator>=(mynum::myflt_t x, const mynum::number_t &y)
{
  return ((cmp(mynum::number_t(x), y) == 1) || (cmp(mynum::number_t(x), y) == 0));
}

bool operator==(mynum::myflt_t x, const mynum::number_t &y)
{
  return (cmp(mynum::number_t(x), y) == 0);
}

bool operator!=(mynum::myflt_t x, const mynum::number_t &y)
{
  return (cmp(mynum::number_t(x), y) != 0);
}