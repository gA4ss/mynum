#ifndef MYNUM_NUMBER_FRACTION_H_
#define MYNUM_NUMBER_FRACTION_H_

#include <mynum/number/complex.h>
#include <mynum/number/real.h>
#include <mynum/number/integer.h>

namespace mynum {
namespace number {

class Fraction {
public:
  Fraction() { zero(); }
  Fraction(const char* number, int base=10) { __create_from_string(number, base); }
  Fraction(std::string& number, int base=10) { __create_from_string(number.c_str(), base); }
  Fraction(const Numeric& real_park, const Numeric& imaginary_park) { real_park_ = real_park; imaginary_park_ = imaginary_park; }
  Fraction(Fraction* c) { assign(*c); }
  Fraction(const Fraction& c) { assign(c); }
  virtual ~Fraction() {}

  virtual void assign(const Fraction& n) {
    numerator_park_ = n.numerator_park(); 
    denominator_park_ = n.denominator_park(); 
  }
  virtual void zero() { numerator_park_.zero(); denominator_park_.zero(); }
  virtual void one(int sign) { numerator_park_.one(sign); denominator_park_.zero(); }
  virtual void infinite(int sign) { operand_type_is_invalid_exception("infinite"); }
  virtual void nan() { numerator_park_.nan(kPositive); denominator_park_.nan(kPositive); }
  virtual void none() { numerator_park_.none(); denominator_park_.none(); }

  Complex numerator_park() const { return numerator_park_; }
  Complex denominator_park() const { return denominator_park_; }

  virtual std::string str() const;

  //////////////////////////////
  // friend function
  //////////////////////////////

  //
  // 比较运算
  //
  friend bool equ(const Fraction& num1, const Fraction& num2);
  friend bool gt(const Fraction& num1, const Fraction& num2);
  friend bool lt(const Fraction& num1, const Fraction& num2);
  friend bool ge(const Fraction& num1, const Fraction& num2);
  friend bool le(const Fraction& num1, const Fraction& num2);

  //
  // 基础的运算
  //
  friend bool is_zero(const Fraction& num1);
  friend bool is_one(const Fraction& num1);
  friend bool is_nan(const Fraction& num1);
  friend bool is_infinite(const Fraction& num1);
  friend bool is_none(const Fraction& num1);
  friend bool is_integer(const Fraction& num1);
  friend bool is_float(const Fraction& num1);
  friend bool is_odd(const Fraction& num1);
  friend bool is_even(const Fraction& num1);
  friend Fraction add(const Fraction& num1, const Fraction& num2);
  friend Fraction sub(const Fraction& num1, const Fraction& num2);
  friend Fraction mul(const Fraction& num1, const Fraction& num2);
  friend Fraction div(const Fraction& num1, const Fraction& num2);
  friend Fraction quo(const Fraction& num1, const Fraction& num2);
  friend Fraction rem(const Fraction& num1, const Fraction& num2);
  friend Fraction mod(const Fraction& num1, const Fraction& num2);
  friend Fraction or_bits(const Fraction& num1, const Fraction& num2);
  friend Fraction and_bits(const Fraction& num1, const Fraction& num2);
  friend Fraction xor_bits(const Fraction& num1, const Fraction& num2);
  friend Fraction not_bits(const Fraction& num1);
  friend Fraction lshift_bits(const Fraction& num1, const Fraction& bits);
  friend Fraction rshift_bits(const Fraction& num1, const Fraction& bits);
  friend Fraction abs(const Fraction& num1);
  friend Fraction floor(const Fraction& num1);
  friend Fraction ceil(const Fraction& num1);
  friend Fraction round(const Fraction& num1, uinteger_t precision=0);
  friend Fraction integer(const Fraction& num1);
  friend Fraction decimal(const Fraction& num1);
  friend Fraction pow(const Fraction& num1, const Fraction& exp);
  friend Fraction rooting(const Fraction& num1, const Fraction& exp);
  friend Fraction log(const Fraction& base, const Fraction& log);
  friend Fraction log2(const Fraction& n);
  friend Fraction log10(const Fraction& n);
  friend Fraction ln(const Fraction& n);
  friend Fraction factorial(const Fraction& num1);
  friend std::pair<Fraction, Fraction> extended_euclidean(const Fraction& num1, const Fraction& num2);
  friend Fraction gcd(const Fraction& num1, const Fraction& num2);
  friend Fraction lcm(const Fraction& num1, const Fraction& num2);

  //
  // 三角函数
  //
  friend Fraction sin(const Fraction& x);
  friend Fraction cos(const Fraction& x);
  friend Fraction tan(const Fraction& x);
  friend Fraction csc(const Fraction& x);
  friend Fraction sec(const Fraction& x);
  friend Fraction cot(const Fraction& x);

  //
  // 反三角函数
  //
  friend Fraction arcsin(const Fraction& x);
  friend Fraction arccos(const Fraction& x);
  friend Fraction arctan(const Fraction& x);
  friend Fraction arccsc(const Fraction& x);
  friend Fraction arcsec(const Fraction& x);
  friend Fraction arccot(const Fraction& x);

  //
  // 双曲函数
  //
  friend Fraction sinh(const Fraction& x);
  friend Fraction cosh(const Fraction& x);
  friend Fraction tanh(const Fraction& x);
  friend Fraction csch(const Fraction& x);
  friend Fraction sech(const Fraction& x);
  friend Fraction coth(const Fraction& x);

  //
  // 反双曲函数
  //
  friend Fraction arcsinh(const Fraction& x);
  friend Fraction arccosh(const Fraction& x);
  friend Fraction arctanh(const Fraction& x);
  friend Fraction arccsch(const Fraction& x);
  friend Fraction arcsech(const Fraction& x);
  friend Fraction arccoth(const Fraction& x);

  //
  // 功能函数
  //
  friend void copy(Fraction& to, const Fraction& from);
  //
  // 友元重载运算符
  //

  // 双目算术运算符
  friend Fraction operator+(const Fraction& num1, const Fraction& num2);
  friend Fraction operator-(const Fraction& num1, const Fraction& num2);
  friend Fraction operator*(const Fraction& num1, const Fraction& num2);
  friend Fraction operator/(const Fraction& num1, const Fraction& num2);
  friend Fraction operator%(const Fraction& num1, const Fraction& num2);

  friend Fraction operator+(const Fraction& num1, const char* num2);
  friend Fraction operator-(const Fraction& num1, const char* num2);
  friend Fraction operator*(const Fraction& num1, const char* num2);
  friend Fraction operator/(const Fraction& num1, const char* num2);
  friend Fraction operator%(const Fraction& num1, const char* num2);

  friend Fraction operator+(const char* num1, const Fraction& num2);
  friend Fraction operator-(const char* num1, const Fraction& num2);
  friend Fraction operator*(const char* num1, const Fraction& num2);
  friend Fraction operator/(const char* num1, const Fraction& num2);
  friend Fraction operator%(const char* num1, const Fraction& num2);

  // 关系运算符
  friend bool operator==(const Fraction& num1, const Fraction& num2);
  friend bool operator!=(const Fraction& num1, const Fraction& num2);
  friend bool operator<(const Fraction& num1, const Fraction& num2);
  friend bool operator>(const Fraction& num1, const Fraction& num2);
  friend bool operator<=(const Fraction& num1, const Fraction& num2);
  friend bool operator>=(const Fraction& num1, const Fraction& num2);

  friend bool operator==(const Fraction& num1, const char* num2);
  friend bool operator!=(const Fraction& num1, const char* num2);
  friend bool operator<(const Fraction& num1, const char* num2);
  friend bool operator>(const Fraction& num1, const char* num2);
  friend bool operator<=(const Fraction& num1, const char* num2);
  friend bool operator>=(const Fraction& num1, const char* num2);

  friend bool operator==(const char* num1, const Fraction& num2);
  friend bool operator!=(const char* num1, const Fraction& num2);
  friend bool operator<(const char* num1, const Fraction& num2);
  friend bool operator>(const char* num1, const Fraction& num2);
  friend bool operator<=(const char* num1, const Fraction& num2);
  friend bool operator>=(const char* num1, const Fraction& num2);

  // 逻辑运算符
  friend bool operator||(const Fraction& num1, const Fraction& num2);
  friend bool operator&&(const Fraction& num1, const Fraction& num2);
  friend bool operator!(const Fraction& num1);

  friend bool operator||(const Fraction& num1, const char* num2);
  friend bool operator&&(const Fraction& num1, const char* num2);

  friend bool operator||(const char* num1, const Fraction& num2);
  friend bool operator&&(const char* num1, const Fraction& num2);

  // 位运算符
  friend Fraction operator~(const Fraction& num1);
  friend Fraction operator|(const Fraction& num1, const Fraction& num2);
  friend Fraction operator&(const Fraction& num1, const Fraction& num2);
  friend Fraction operator^(const Fraction& num1, const Fraction& num2);
  friend Fraction operator<<(const Fraction& num1, const Fraction& bits);
  friend Fraction operator>>(const Fraction& num1, const Fraction& bits);

  friend Fraction operator|(const Fraction& num1, const char* num2);
  friend Fraction operator&(const Fraction& num1, const char* num2);
  friend Fraction operator^(const Fraction& num1, const char* num2);
  friend Fraction operator<<(const Fraction& num1, const char* bits);
  friend Fraction operator>>(const Fraction& num1, const char* bits);

  friend Fraction operator|(const char* num1, const Fraction& num2);
  friend Fraction operator&(const char* num1, const Fraction& num2);
  friend Fraction operator^(const char* num1, const Fraction& num2);
  friend Fraction operator<<(const char* num1, const Fraction& bits);
  friend Fraction operator>>(const char* num1, const Fraction& bits);

  //////////////////////////////
  // operation function
  //////////////////////////////
  // 单目运算符
  Fraction& operator+() { +real_park_; +imaginary_park_; return *this; }
  Fraction& operator-() { -real_park_; -imaginary_park_; return *this; }

  // 自增自减运算符
  Fraction& operator++() { ++real_park_; ++imaginary_park_; return *this; }
  Fraction operator++(int) { Fraction t = *this; real_park_++; imaginary_park_++; return t; }
  Fraction& operator--() { --real_park_; --imaginary_park_; return *this; }
  Fraction operator--(int) { Fraction t = *this; real_park_--; imaginary_park_--; return t; }

  // 赋值运算符
  virtual void operator=(const Fraction& num2) { assign(num2); }
  virtual void operator=(const char* num2) { assign(Fraction(num2)); }
  virtual void operator+=(const Fraction& num2) { *this = add(*this, num2); }
  virtual void operator+=(const char* num2) { *this += Fraction(num2); }
  virtual void operator-=(const Fraction& num2) { *this = sub(*this, num2); }
  virtual void operator-=(const char* num2) { *this -= Fraction(num2); }
  virtual void operator*=(const Fraction& num2) { *this = mul(*this, num2); }
  virtual void operator*=(const char* num2) { *this *= Fraction(num2); }
  virtual void operator/=(const Fraction& num2) { *this = div(*this, num2); }
  virtual void operator/=(const char* num2) { *this /= Fraction(num2); }
  virtual void operator%=(const Fraction& num2) { *this = mod(*this, num2); }
  virtual void operator%=(const char* num2) { *this %= Fraction(num2); }
  virtual void operator&=(const Fraction& num2) { *this = and_bits(*this, num2); }
  virtual void operator&=(const char* num2) { *this &= Fraction(num2); }
  virtual void operator|=(const Fraction& num2) { *this = or_bits(*this, num2); }
  virtual void operator|=(const char* num2) { *this |= Fraction(num2); }
  virtual void operator^=(const Fraction& num2) { *this = xor_bits(*this, num2); }
  virtual void operator^=(const char* num2) { *this ^= Fraction(num2);  }
  virtual void operator<<=(const Fraction& bits) { *this = lshift_bits(*this, bits); }
  virtual void operator>>=(const Fraction& bits) { *this = rshift_bits(*this, bits); }
  virtual char operator[](uinteger_t i);    // 迭代运算符

protected:
  void __create_from_string(const char* n, int base);
  void __set_numerator_park(const Numeric& numerator_park) { numerator_park_ = numerator_park; }
  void __set_numerator_park_zero() { numerator_park_.zero(); }
  void __set_denominator_park(const Numeric& denominator_park) { denominator_park_ = denominator_park; }
  void __set_denominator_park_zero() { denominator_park_.zero(); }

protected:
  Complex numerator_park_;
  Complex denominator_park_;
};

//
// 比较运算
//
bool equ(const Fraction& num1, const Fraction& num2);
bool gt(const Fraction& num1, const Fraction& num2);
bool lt(const Fraction& num1, const Fraction& num2);
bool ge(const Fraction& num1, const Fraction& num2);
bool le(const Fraction& num1, const Fraction& num2);

//
// 基础的运算
//
bool is_zero(const Fraction& num1);
bool is_one(const Fraction& num1);
bool is_nan(const Fraction& num1);
bool is_infinite(const Fraction& num1);
bool is_none(const Fraction& num1);
bool is_integer(const Fraction& num1);
bool is_float(const Fraction& num1);
bool is_odd(const Fraction& num1);
bool is_even(const Fraction& num1);
Fraction add(const Fraction& num1, const Fraction& num2);
Fraction sub(const Fraction& num1, const Fraction& num2);
Fraction mul(const Fraction& num1, const Fraction& num2);
Fraction div(const Fraction& num1, const Fraction& num2);
Fraction quo(const Fraction& num1, const Fraction& num2);
Fraction rem(const Fraction& num1, const Fraction& num2);
Fraction mod(const Fraction& num1, const Fraction& num2);
Fraction or_bits(const Fraction& num1, const Fraction& num2);
Fraction and_bits(const Fraction& num1, const Fraction& num2);
Fraction xor_bits(const Fraction& num1, const Fraction& num2);
Fraction not_bits(const Fraction& num1);
Fraction lshift_bits(const Fraction& num1, const Fraction& bits);
Fraction rshift_bits(const Fraction& num1, const Fraction& bits);
Fraction abs(const Fraction& num1);
Fraction floor(const Fraction& num1);
Fraction ceil(const Fraction& num1);
Fraction round(const Fraction& num1, uinteger_t precision);
Fraction integer(const Fraction& num1);
Fraction decimal(const Fraction& num1);
Fraction pow(const Fraction& num1, const Fraction& exp);
Fraction rooting(const Fraction& num1, const Fraction& exp);
Fraction log(const Fraction& base, const Fraction& log);
Fraction log2(const Fraction& n);
Fraction log10(const Fraction& n);
Fraction ln(const Fraction& n);
Fraction factorial(const Fraction& num1);
std::pair<Fraction, Fraction> extended_euclidean(const Fraction& num1, const Fraction& num2);
Fraction gcd(const Fraction& num1, const Fraction& num2);
Fraction lcm(const Fraction& num1, const Fraction& num2);

//
// 三角函数
//
Fraction sin(const Fraction& x);
Fraction cos(const Fraction& x);
Fraction tan(const Fraction& x);
Fraction csc(const Fraction& x);
Fraction sec(const Fraction& x);
Fraction cot(const Fraction& x);

//
// 反三角函数
//
Fraction arcsin(const Fraction& x);
Fraction arccos(const Fraction& x);
Fraction arctan(const Fraction& x);
Fraction arccsc(const Fraction& x);
Fraction arcsec(const Fraction& x);
Fraction arccot(const Fraction& x);

//
// 双曲函数
//
Fraction sinh(const Fraction& x);
Fraction cosh(const Fraction& x);
Fraction tanh(const Fraction& x);
Fraction csch(const Fraction& x);
Fraction sech(const Fraction& x);
Fraction coth(const Fraction& x);

//
// 反双曲函数
//
Fraction arcsinh(const Fraction& x);
Fraction arccosh(const Fraction& x);
Fraction arctanh(const Fraction& x);
Fraction arccsch(const Fraction& x);
Fraction arcsech(const Fraction& x);
Fraction arccoth(const Fraction& x);

//
// 功能函数
//
void copy(Fraction& to, const Fraction& from);

//
// 友元重载运算符
//

// 双目算术运算符
Fraction operator+(const Fraction& num1, const Fraction& num2);
Fraction operator-(const Fraction& num1, const Fraction& num2);
Fraction operator*(const Fraction& num1, const Fraction& num2);
Fraction operator/(const Fraction& num1, const Fraction& num2);
Fraction operator%(const Fraction& num1, const Fraction& num2);

Fraction operator+(const Fraction& num1, const char* num2);
Fraction operator-(const Fraction& num1, const char* num2);
Fraction operator*(const Fraction& num1, const char* num2);
Fraction operator/(const Fraction& num1, const char* num2);
Fraction operator%(const Fraction& num1, const char* num2);

Fraction operator+(const char* num1, const Fraction& num2);
Fraction operator-(const char* num1, const Fraction& num2);
Fraction operator*(const char* num1, const Fraction& num2);
Fraction operator/(const char* num1, const Fraction& num2);
Fraction operator%(const char* num1, const Fraction& num2);

// 关系运算符
bool operator==(const Fraction& num1, const Fraction& num2);
bool operator!=(const Fraction& num1, const Fraction& num2);
bool operator<(const Fraction& num1, const Fraction& num2);
bool operator>(const Fraction& num1, const Fraction& num2);
bool operator<=(const Fraction& num1, const Fraction& num2);
bool operator>=(const Fraction& num1, const Fraction& num2);

bool operator==(const Fraction& num1, const char* num2);
bool operator!=(const Fraction& num1, const char* num2);
bool operator<(const Fraction& num1, const char* num2);
bool operator>(const Fraction& num1, const char* num2);
bool operator<=(const Fraction& num1, const char* num2);
bool operator>=(const Fraction& num1, const char* num2);

bool operator==(const char* num1, const Fraction& num2);
bool operator!=(const char* num1, const Fraction& num2);
bool operator<(const char* num1, const Fraction& num2);
bool operator>(const char* num1, const Fraction& num2);
bool operator<=(const char* num1, const Fraction& num2);
bool operator>=(const char* num1, const Fraction& num2);

// 逻辑运算符
bool operator||(const Fraction& num1, const Fraction& num2);
bool operator&&(const Fraction& num1, const Fraction& num2);
bool operator!(const Fraction& num1);

bool operator||(const Fraction& num1, const char* num2);
bool operator&&(const Fraction& num1, const char* num2);

bool operator||(const char* num1, const Fraction& num2);
bool operator&&(const char* num1, const Fraction& num2);

// 位运算符
Fraction operator~(const Fraction& num1);
Fraction operator|(const Fraction& num1, const Fraction& num2);
Fraction operator&(const Fraction& num1, const Fraction& num2);
Fraction operator^(const Fraction& num1, const Fraction& num2);
Fraction operator<<(const Fraction& num1, const Fraction& bits);
Fraction operator>>(const Fraction& num1, const Fraction& bits);

Fraction operator|(const Fraction& num1, const char* num2);
Fraction operator&(const Fraction& num1, const char* num2);
Fraction operator^(const Fraction& num1, const char* num2);
Fraction operator<<(const Fraction& num1, const char* bits);
Fraction operator>>(const Fraction& num1, const char* bits);

Fraction operator|(const char* num1, const Fraction& num2);
Fraction operator&(const char* num1, const Fraction& num2);
Fraction operator^(const char* num1, const Fraction& num2);
Fraction operator<<(const char* num1, const Fraction& bits);
Fraction operator>>(const char* num1, const Fraction& bits);

typedef std::shared_ptr<Fraction> fraction_t;

} // namespace number
} // namespace mynum

#endif // MYNUM_NUMBER_FRACTION_H_