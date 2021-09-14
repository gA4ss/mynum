#ifndef MYNUM_NUMBER_REAL_H_
#define MYNUM_NUMBER_REAL_H_

#include <mynum/number/complex.h>

namespace mynum {
namespace number {

class Real : public Complex {
public:
  Real() { zero(); }
  Real(const Numeric& real_park) { real_park_ = real_park; }
  virtual ~Real() {}

  virtual std::string str() const { return real_park_.str(); }
  virtual std::string class_name() const { return "real"; }

  //////////////////////////////
  // operation function
  //////////////////////////////

  // 单目运算符 *(指针)，&(取地址)
  Real& operator+() { +real_park_; return *this; }
  Real& operator-() { -real_park_; return *this; }

  // 自增自减运算符
  Real& operator++() { ++real_park_; return *this; }
  Real operator++(int) { Real t = *this; real_park_++; return t; }
  Real& operator--() { --real_park_; return *this; }
  Real operator--(int) { Real t = *this; real_park_--; return t; }

  //////////////////////////////
  // friend function
  //////////////////////////////
  //
  // 比较运算
  //
  friend bool equ(const Real& num1, const Real& num2);
  friend bool gt(const Real& num1, const Real& num2);
  friend bool lt(const Real& num1, const Real& num2);
  friend bool ge(const Real& num1, const Real& num2);
  friend bool le(const Real& num1, const Real& num2);

  //
  // 基础的运算
  //
  friend bool is_zero(const Real& num1);
  friend bool is_one(const Real& num1);
  friend bool is_nan(const Real& num1);
  friend bool is_infinite(const Real& num1);
  friend bool is_none(const Real& num1);
  friend bool is_integer(const Real& num1);
  friend bool is_float(const Real& num1);
  friend bool is_odd(const Real& num1);
  friend bool is_even(const Real& num1);
  friend Real add(const Real& num1, const Real& num2);
  friend Real sub(const Real& num1, const Real& num2);
  friend Real mul(const Real& num1, const Real& num2);
  friend Real div(const Real& num1, const Real& num2);
  friend Real quo(const Real& num1, const Real& num2);
  friend Real rem(const Real& num1, const Real& num2);
  friend Real mod(const Real& num1, const Real& num2);
  friend Real or_bits(const Real& num1, const Real& num2);
  friend Real and_bits(const Real& num1, const Real& num2);
  friend Real xor_bits(const Real& num1, const Real& num2);
  friend Real not_bits(const Real& num1);
  friend Real lshift_bits(const Real& num1, const Real& bits);
  friend Real rshift_bits(const Real& num1, const Real& bits);
  friend Real abs(const Real& num1);
  friend Real floor(const Real& num1);
  friend Real ceil(const Real& num1);
  friend Real round(const Real& num1, uinteger_t precision=0);
  friend Real integer(const Real& num1);
  friend Real decimal(const Real& num1);
  friend Real pow(const Real& num1, const Real& exp);
  friend Real rooting(const Real& num1, const Real& exp);
  friend Real log(const Real& base, const Real& log);
  friend Real log2(const Real& log);
  friend Real log10(const Real& log);
  friend Real ln(const Real& log);
  friend Real factorial(const Real& num1);
  friend std::pair<Real, Real> extended_euclidean(const Real& num1, const Real& num2);
  friend Real gcd(const Real& num1, const Real& num2);
  friend Real lcm(const Real& num1, const Real& num2);

  //
  // 三角函数
  //
  friend Real sin(const Real& x);
  friend Real cos(const Real& x);
  friend Real tan(const Real& x);
  friend Real csc(const Real& x);
  friend Real sec(const Real& x);
  friend Real cot(const Real& x);

  //
  // 反三角函数
  //
  friend Real arcsin(const Real& x);
  friend Real arccos(const Real& x);
  friend Real arctan(const Real& x);
  friend Real arccsc(const Real& x);
  friend Real arcsec(const Real& x);
  friend Real arccot(const Real& x);

  //
  // 双曲函数
  //
  friend Real sinh(const Real& x);
  friend Real cosh(const Real& x);
  friend Real tanh(const Real& x);
  friend Real csch(const Real& x);
  friend Real sech(const Real& x);
  friend Real coth(const Real& x);

  //
  // 反双曲函数
  //
  friend Real arcsinh(const Real& x);
  friend Real arccosh(const Real& x);
  friend Real arctanh(const Real& x);
  friend Real arccsch(const Real& x);
  friend Real arcsech(const Real& x);
  friend Real arccoth(const Real& x);

  //
  // 功能函数
  //
  friend void copy(Real& to, const Real& from);
  friend Real convert_to_number(const Real& n);

  //
  // 友元重载运算符
  //

  // 双目算术运算符
  friend Real operator+(const Real& num1, const Real& num2);
  friend Real operator-(const Real& num1, const Real& num2);
  friend Real operator*(const Real& num1, const Real& num2);
  friend Real operator/(const Real& num1, const Real& num2);
  friend Real operator%(const Real& num1, const Real& num2);

  friend Real operator+(const Real& num1, const char* num2);
  friend Real operator-(const Real& num1, const char* num2);
  friend Real operator*(const Real& num1, const char* num2);
  friend Real operator/(const Real& num1, const char* num2);
  friend Real operator%(const Real& num1, const char* num2);

  friend Real operator+(const char* num1, const Real& num2);
  friend Real operator-(const char* num1, const Real& num2);
  friend Real operator*(const char* num1, const Real& num2);
  friend Real operator/(const char* num1, const Real& num2);
  friend Real operator%(const char* num1, const Real& num2);

  // 关系运算符
  friend bool operator==(const Real& num1, const Real& num2);
  friend bool operator!=(const Real& num1, const Real& num2);
  friend bool operator<(const Real& num1, const Real& num2);
  friend bool operator>(const Real& num1, const Real& num2);
  friend bool operator<=(const Real& num1, const Real& num2);
  friend bool operator>=(const Real& num1, const Real& num2);

  friend bool operator==(const Real& num1, const char* num2);
  friend bool operator!=(const Real& num1, const char* num2);
  friend bool operator<(const Real& num1, const char* num2);
  friend bool operator>(const Real& num1, const char* num2);
  friend bool operator<=(const Real& num1, const char* num2);
  friend bool operator>=(const Real& num1, const char* num2);

  friend bool operator==(const char* num1, const Real& num2);
  friend bool operator!=(const char* num1, const Real& num2);
  friend bool operator<(const char* num1, const Real& num2);
  friend bool operator>(const char* num1, const Real& num2);
  friend bool operator<=(const char* num1, const Real& num2);
  friend bool operator>=(const char* num1, const Real& num2);

  // 逻辑运算符
  friend bool operator||(const Real& num1, const Real& num2);
  friend bool operator&&(const Real& num1, const Real& num2);
  friend bool operator!(const Real& num1);

  friend bool operator||(const Real& num1, const char* num2);
  friend bool operator&&(const Real& num1, const char* num2);

  friend bool operator||(const char* num1, const Real& num2);
  friend bool operator&&(const char* num1, const Real& num2);

  // 位运算符
  friend Real operator~(const Real& num1);
  friend Real operator|(const Real& num1, const Real& num2);
  friend Real operator&(const Real& num1, const Real& num2);
  friend Real operator^(const Real& num1, const Real& num2);
  friend Real operator<<(const Real& num1, const Real& bits);
  friend Real operator>>(const Real& num1, const Real& bits);

  friend Real operator|(const Real& num1, const char* num2);
  friend Real operator&(const Real& num1, const char* num2);
  friend Real operator^(const Real& num1, const char* num2);
  friend Real operator<<(const Real& num1, const char* bits);
  friend Real operator>>(const Real& num1, const char* bits);

  friend Real operator|(const char* num1, const Real& num2);
  friend Real operator&(const char* num1, const Real& num2);
  friend Real operator^(const char* num1, const Real& num2);
  friend Real operator<<(const char* num1, const Real& bits);
  friend Real operator>>(const char* num1, const Real& bits);

  // 赋值运算符
  virtual void operator=(const Real& num2) { assign(num2); }
  virtual void operator=(const char* num2) { assign(Real(num2)); }
  virtual void operator+=(const Real& num2) { *this = add(*this, num2); }
  virtual void operator+=(const char* num2) { *this += Real(num2); }
  virtual void operator-=(const Real& num2) { *this = sub(*this, num2); }
  virtual void operator-=(const char* num2) { *this -= Real(num2); }
  virtual void operator*=(const Real& num2) { *this = mul(*this, num2); }
  virtual void operator*=(const char* num2) { *this *= Real(num2); }
  virtual void operator/=(const Real& num2) { *this = div(*this, num2); }
  virtual void operator/=(const char* num2) { *this /= Real(num2); }
  virtual void operator%=(const Real& num2) { *this = mod(*this, num2); }
  virtual void operator%=(const char* num2) { *this %= Real(num2); }
  virtual void operator&=(const Real& num2) { *this = and_bits(*this, num2); }
  virtual void operator&=(const char* num2) { *this &= Real(num2); }
  virtual void operator|=(const Real& num2) { *this = or_bits(*this, num2); }
  virtual void operator|=(const char* num2) { *this |= Real(num2); }
  virtual void operator^=(const Real& num2) { *this = xor_bits(*this, num2); }
  virtual void operator^=(const char* num2) { *this ^= Real(num2);  }
  virtual void operator<<=(const Real& bits) { *this = lshift_bits(*this, bits); }
  virtual void operator>>=(const Real& bits) { *this = rshift_bits(*this, bits); }
};

//
// 比较运算
//
bool equ(const Real& num1, const Real& num2);
bool gt(const Real& num1, const Real& num2);
bool lt(const Real& num1, const Real& num2);
bool ge(const Real& num1, const Real& num2);
bool le(const Real& num1, const Real& num2);

//
// 基础的运算
//
bool is_zero(const Real& num1);
bool is_one(const Real& num1);
bool is_nan(const Real& num1);
bool is_infinite(const Real& num1);
bool is_none(const Real& num1);
bool is_integer(const Real& num1);
bool is_float(const Real& num1);
bool is_odd(const Real& num1);
bool is_even(const Real& num1);
Real add(const Real& num1, const Real& num2);
Real sub(const Real& num1, const Real& num2);
Real mul(const Real& num1, const Real& num2);
Real div(const Real& num1, const Real& num2);
Real quo(const Real& num1, const Real& num2);
Real rem(const Real& num1, const Real& num2);
Real mod(const Real& num1, const Real& num2);
Real or_bits(const Real& num1, const Real& num2);
Real and_bits(const Real& num1, const Real& num2);
Real xor_bits(const Real& num1, const Real& num2);
Real not_bits(const Real& num1);
Real lshift_bits(const Real& num1, const Real& bits);
Real rshift_bits(const Real& num1, const Real& bits);
Real abs(const Real& num1);
Real floor(const Real& num1);
Real ceil(const Real& num1);
Real round(const Real& num1, uinteger_t precision);
Real integer(const Real& num1);
Real decimal(const Real& num1);
Real pow(const Real& num1, const Real& exp);
Real rooting(const Real& num1, const Real& exp);
Real log(const Real& base, const Real& n);
Real log2(const Real& log);
Real log10(const Real& log);
Real ln(const Real& log);
Real factorial(const Real& num1);
std::pair<Real, Real> extended_euclidean(const Real& num1, const Real& num2);
Real gcd(const Real& num1, const Real& num2);
Real lcm(const Real& num1, const Real& num2);

//
// 三角函数
//
Real sin(const Real& x);
Real cos(const Real& x);
Real tan(const Real& x);
Real csc(const Real& x);
Real sec(const Real& x);
Real cot(const Real& x);

//
// 反三角函数
//
Real arcsin(const Real& x);
Real arccos(const Real& x);
Real arctan(const Real& x);
Real arccsc(const Real& x);
Real arcsec(const Real& x);
Real arccot(const Real& x);

//
// 双曲函数
//
Real sinh(const Real& x);
Real cosh(const Real& x);
Real tanh(const Real& x);
Real csch(const Real& x);
Real sech(const Real& x);
Real coth(const Real& x);

//
// 反双曲函数
//
Real arcsinh(const Real& x);
Real arccosh(const Real& x);
Real arctanh(const Real& x);
Real arccsch(const Real& x);
Real arcsech(const Real& x);
Real arccoth(const Real& x);

//
// 功能函数
//
void copy(Real& to, const Real& from);

//
// 友元重载运算符
//

// 双目算术运算符
Real operator+(const Real& num1, const Real& num2);
Real operator-(const Real& num1, const Real& num2);
Real operator*(const Real& num1, const Real& num2);
Real operator/(const Real& num1, const Real& num2);
Real operator%(const Real& num1, const Real& num2);

Real operator+(const Real& num1, const char* num2);
Real operator-(const Real& num1, const char* num2);
Real operator*(const Real& num1, const char* num2);
Real operator/(const Real& num1, const char* num2);
Real operator%(const Real& num1, const char* num2);

Real operator+(const char* num1, const Real& num2);
Real operator-(const char* num1, const Real& num2);
Real operator*(const char* num1, const Real& num2);
Real operator/(const char* num1, const Real& num2);
Real operator%(const char* num1, const Real& num2);

// 关系运算符
bool operator==(const Real& num1, const Real& num2);
bool operator!=(const Real& num1, const Real& num2);
bool operator<(const Real& num1, const Real& num2);
bool operator>(const Real& num1, const Real& num2);
bool operator<=(const Real& num1, const Real& num2);
bool operator>=(const Real& num1, const Real& num2);

bool operator==(const Real& num1, const char* num2);
bool operator!=(const Real& num1, const char* num2);
bool operator<(const Real& num1, const char* num2);
bool operator>(const Real& num1, const char* num2);
bool operator<=(const Real& num1, const char* num2);
bool operator>=(const Real& num1, const char* num2);

bool operator==(const char* num1, const Real& num2);
bool operator!=(const char* num1, const Real& num2);
bool operator<(const char* num1, const Real& num2);
bool operator>(const char* num1, const Real& num2);
bool operator<=(const char* num1, const Real& num2);
bool operator>=(const char* num1, const Real& num2);

// 逻辑运算符
bool operator||(const Real& num1, const Real& num2);
bool operator&&(const Real& num1, const Real& num2);
bool operator!(const Real& num1);

bool operator||(const Real& num1, const char* num2);
bool operator&&(const Real& num1, const char* num2);

bool operator||(const char* num1, const Real& num2);
bool operator&&(const char* num1, const Real& num2);

// 位运算符
Real operator~(const Real& num1);
Real operator|(const Real& num1, const Real& num2);
Real operator&(const Real& num1, const Real& num2);
Real operator^(const Real& num1, const Real& num2);
Real operator<<(const Real& num1, const Real& bits);
Real operator>>(const Real& num1, const Real& bits);

Real operator|(const Real& num1, const char* num2);
Real operator&(const Real& num1, const char* num2);
Real operator^(const Real& num1, const char* num2);
Real operator<<(const Real& num1, const char* bits);
Real operator>>(const Real& num1, const char* bits);

Real operator|(const char* num1, const Real& num2);
Real operator&(const char* num1, const Real& num2);
Real operator^(const char* num1, const Real& num2);
Real operator<<(const char* num1, const Real& bits);
Real operator>>(const char* num1, const Real& bits);

typedef std::shared_ptr<Real> mynum_real_t;

} // namespace number
} // namespace mynum

#endif // MYNUM_NUMBER_REAL_H_