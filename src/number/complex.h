#ifndef MYNUM_NUMBER_COMPLEX_H_
#define MYNUM_NUMBER_COMPLEX_H_

#include <mynum/number/number.h>

namespace mynum {
namespace number {

class Complex : public Number {
public:
  Complex() { zero(); }
  Complex(const char* number, int base=10) { __create_from_string(number, base); }
  Complex(std::string& number, int base=10) { __create_from_string(number.c_str(), base); }
  Complex(const Numeric& real_park, const Numeric& imaginary_park) { real_park_ = real_park; imaginary_park_ = imaginary_park; }
  Complex(Complex* c) { assign(*c); }
  Complex(const Complex& c) { assign(c); }
  virtual ~Complex() {}

  virtual void assign(const Complex& n) { real_park_ = n.real_park(); imaginary_park_ = n.imaginary_park(); }
  virtual void zero() { real_park_.zero(); imaginary_park_.zero(); }
  virtual void one(int sign) { real_park_.one(sign); imaginary_park_.zero(); }
  virtual void infinite(int sign) { operand_type_is_invalid_exception("%s", "infinite"); }
  virtual void nan() { real_park_.nan(kPositive); imaginary_park_.nan(kPositive); }
  virtual void none() { real_park_.none(); imaginary_park_.none(); }

  Numeric real_park() const { return real_park_; }
  Numeric imaginary_park() const { return imaginary_park_; }

  virtual std::string str() const;
  virtual std::string class_name() const { return "complex"; }

  //////////////////////////////
  // friend function
  //////////////////////////////

  //
  // 比较运算
  //
  friend bool equ(const Complex& num1, const Complex& num2);
  friend bool gt(const Complex& num1, const Complex& num2);
  friend bool lt(const Complex& num1, const Complex& num2);
  friend bool ge(const Complex& num1, const Complex& num2);
  friend bool le(const Complex& num1, const Complex& num2);

  //
  // 基础的运算
  //
  friend bool is_zero(const Complex& num1);
  friend bool is_one(const Complex& num1);
  friend bool is_nan(const Complex& num1);
  friend bool is_infinite(const Complex& num1);
  friend bool is_none(const Complex& num1);
  friend bool is_integer(const Complex& num1);
  friend bool is_float(const Complex& num1);
  friend bool is_odd(const Complex& num1);
  friend bool is_even(const Complex& num1);
  friend Complex add(const Complex& num1, const Complex& num2);
  friend Complex sub(const Complex& num1, const Complex& num2);
  friend Complex mul(const Complex& num1, const Complex& num2);
  friend Complex div(const Complex& num1, const Complex& num2);
  friend Complex quo(const Complex& num1, const Complex& num2);
  friend Complex rem(const Complex& num1, const Complex& num2);
  friend Complex mod(const Complex& num1, const Complex& num2);
  friend Complex or_bits(const Complex& num1, const Complex& num2);
  friend Complex and_bits(const Complex& num1, const Complex& num2);
  friend Complex xor_bits(const Complex& num1, const Complex& num2);
  friend Complex not_bits(const Complex& num1);
  friend Complex lshift_bits(const Complex& num1, const Complex& bits);
  friend Complex rshift_bits(const Complex& num1, const Complex& bits);
  friend Complex abs(const Complex& num1);
  friend Complex floor(const Complex& num1);
  friend Complex ceil(const Complex& num1);
  friend Complex round(const Complex& num1, uinteger_t precision=0);
  friend Complex integer(const Complex& num1);
  friend Complex decimal(const Complex& num1);
  friend Complex pow(const Complex& num1, const Complex& exp);
  friend Complex rooting(const Complex& num1, const Complex& exp);
  friend Complex log(const Complex& base, const Complex& log);
  friend Complex log2(const Complex& n);
  friend Complex log10(const Complex& n);
  friend Complex ln(const Complex& n);
  friend Complex factorial(const Complex& num1);
  friend std::pair<Complex, Complex> extended_euclidean(const Complex& num1, const Complex& num2);
  friend Complex gcd(const Complex& num1, const Complex& num2);
  friend Complex lcm(const Complex& num1, const Complex& num2);

  //
  // 三角函数
  //
  friend Complex sin(const Complex& x);
  friend Complex cos(const Complex& x);
  friend Complex tan(const Complex& x);
  friend Complex csc(const Complex& x);
  friend Complex sec(const Complex& x);
  friend Complex cot(const Complex& x);

  //
  // 反三角函数
  //
  friend Complex arcsin(const Complex& x);
  friend Complex arccos(const Complex& x);
  friend Complex arctan(const Complex& x);
  friend Complex arccsc(const Complex& x);
  friend Complex arcsec(const Complex& x);
  friend Complex arccot(const Complex& x);

  //
  // 双曲函数
  //
  friend Complex sinh(const Complex& x);
  friend Complex cosh(const Complex& x);
  friend Complex tanh(const Complex& x);
  friend Complex csch(const Complex& x);
  friend Complex sech(const Complex& x);
  friend Complex coth(const Complex& x);

  //
  // 反双曲函数
  //
  friend Complex arcsinh(const Complex& x);
  friend Complex arccosh(const Complex& x);
  friend Complex arctanh(const Complex& x);
  friend Complex arccsch(const Complex& x);
  friend Complex arcsech(const Complex& x);
  friend Complex arccoth(const Complex& x);

  //
  // 功能函数
  //
  friend void copy(Complex& to, const Complex& from);
  //
  // 友元重载运算符
  //

  // 双目算术运算符
  friend Complex operator+(const Complex& num1, const Complex& num2);
  friend Complex operator-(const Complex& num1, const Complex& num2);
  friend Complex operator*(const Complex& num1, const Complex& num2);
  friend Complex operator/(const Complex& num1, const Complex& num2);
  friend Complex operator%(const Complex& num1, const Complex& num2);

  friend Complex operator+(const Complex& num1, const char* num2);
  friend Complex operator-(const Complex& num1, const char* num2);
  friend Complex operator*(const Complex& num1, const char* num2);
  friend Complex operator/(const Complex& num1, const char* num2);
  friend Complex operator%(const Complex& num1, const char* num2);

  friend Complex operator+(const char* num1, const Complex& num2);
  friend Complex operator-(const char* num1, const Complex& num2);
  friend Complex operator*(const char* num1, const Complex& num2);
  friend Complex operator/(const char* num1, const Complex& num2);
  friend Complex operator%(const char* num1, const Complex& num2);

  // 关系运算符
  friend bool operator==(const Complex& num1, const Complex& num2);
  friend bool operator!=(const Complex& num1, const Complex& num2);
  friend bool operator<(const Complex& num1, const Complex& num2);
  friend bool operator>(const Complex& num1, const Complex& num2);
  friend bool operator<=(const Complex& num1, const Complex& num2);
  friend bool operator>=(const Complex& num1, const Complex& num2);

  friend bool operator==(const Complex& num1, const char* num2);
  friend bool operator!=(const Complex& num1, const char* num2);
  friend bool operator<(const Complex& num1, const char* num2);
  friend bool operator>(const Complex& num1, const char* num2);
  friend bool operator<=(const Complex& num1, const char* num2);
  friend bool operator>=(const Complex& num1, const char* num2);

  friend bool operator==(const char* num1, const Complex& num2);
  friend bool operator!=(const char* num1, const Complex& num2);
  friend bool operator<(const char* num1, const Complex& num2);
  friend bool operator>(const char* num1, const Complex& num2);
  friend bool operator<=(const char* num1, const Complex& num2);
  friend bool operator>=(const char* num1, const Complex& num2);

  // 逻辑运算符
  friend bool operator||(const Complex& num1, const Complex& num2);
  friend bool operator&&(const Complex& num1, const Complex& num2);
  friend bool operator!(const Complex& num1);

  friend bool operator||(const Complex& num1, const char* num2);
  friend bool operator&&(const Complex& num1, const char* num2);

  friend bool operator||(const char* num1, const Complex& num2);
  friend bool operator&&(const char* num1, const Complex& num2);

  // 位运算符
  friend Complex operator~(const Complex& num1);
  friend Complex operator|(const Complex& num1, const Complex& num2);
  friend Complex operator&(const Complex& num1, const Complex& num2);
  friend Complex operator^(const Complex& num1, const Complex& num2);
  friend Complex operator<<(const Complex& num1, const Complex& bits);
  friend Complex operator>>(const Complex& num1, const Complex& bits);

  friend Complex operator|(const Complex& num1, const char* num2);
  friend Complex operator&(const Complex& num1, const char* num2);
  friend Complex operator^(const Complex& num1, const char* num2);
  friend Complex operator<<(const Complex& num1, const char* bits);
  friend Complex operator>>(const Complex& num1, const char* bits);

  friend Complex operator|(const char* num1, const Complex& num2);
  friend Complex operator&(const char* num1, const Complex& num2);
  friend Complex operator^(const char* num1, const Complex& num2);
  friend Complex operator<<(const char* num1, const Complex& bits);
  friend Complex operator>>(const char* num1, const Complex& bits);

  friend Complex conjugate(const Complex& num1);

  //////////////////////////////
  // operation function
  //////////////////////////////
  // 单目运算符
  Complex& operator+() { +real_park_; +imaginary_park_; return *this; }
  Complex& operator-() { -real_park_; -imaginary_park_; return *this; }

  // 自增自减运算符
  Complex& operator++() { ++real_park_; ++imaginary_park_; return *this; }
  Complex operator++(int) { Complex t = *this; real_park_++; imaginary_park_++; return t; }
  Complex& operator--() { --real_park_; --imaginary_park_; return *this; }
  Complex operator--(int) { Complex t = *this; real_park_--; imaginary_park_--; return t; }

  // 赋值运算符
  virtual void operator=(const Complex& num2) { assign(num2); }
  virtual void operator=(const char* num2) { assign(Complex(num2)); }
  virtual void operator+=(const Complex& num2) { *this = add(*this, num2); }
  virtual void operator+=(const char* num2) { *this += Complex(num2); }
  virtual void operator-=(const Complex& num2) { *this = sub(*this, num2); }
  virtual void operator-=(const char* num2) { *this -= Complex(num2); }
  virtual void operator*=(const Complex& num2) { *this = mul(*this, num2); }
  virtual void operator*=(const char* num2) { *this *= Complex(num2); }
  virtual void operator/=(const Complex& num2) { *this = div(*this, num2); }
  virtual void operator/=(const char* num2) { *this /= Complex(num2); }
  virtual void operator%=(const Complex& num2) { *this = mod(*this, num2); }
  virtual void operator%=(const char* num2) { *this %= Complex(num2); }
  virtual void operator&=(const Complex& num2) { *this = and_bits(*this, num2); }
  virtual void operator&=(const char* num2) { *this &= Complex(num2); }
  virtual void operator|=(const Complex& num2) { *this = or_bits(*this, num2); }
  virtual void operator|=(const char* num2) { *this |= Complex(num2); }
  virtual void operator^=(const Complex& num2) { *this = xor_bits(*this, num2); }
  virtual void operator^=(const char* num2) { *this ^= Complex(num2);  }
  virtual void operator<<=(const Complex& bits) { *this = lshift_bits(*this, bits); }
  virtual void operator>>=(const Complex& bits) { *this = rshift_bits(*this, bits); }
  virtual char operator[](uinteger_t i);    // 迭代运算符

protected:
  void __create_from_string(const char* n, int base);
  void __set_real_park(const Numeric& real_park) { real_park_ = real_park; }
  void __set_real_park_zero() { real_park_.zero(); }
  void __set_imaginary_park(const Numeric& imaginary_park) { imaginary_park_ = imaginary_park; }
  void __set_imaginary_park_zero() { imaginary_park_.zero(); }

protected:
  Numeric real_park_;
  Numeric imaginary_park_;
};

//
// 比较运算
//
bool equ(const Complex& num1, const Complex& num2);
bool gt(const Complex& num1, const Complex& num2);
bool lt(const Complex& num1, const Complex& num2);
bool ge(const Complex& num1, const Complex& num2);
bool le(const Complex& num1, const Complex& num2);

//
// 基础的运算
//
bool is_zero(const Complex& num1);
bool is_one(const Complex& num1);
bool is_nan(const Complex& num1);
bool is_infinite(const Complex& num1);
bool is_none(const Complex& num1);
bool is_integer(const Complex& num1);
bool is_float(const Complex& num1);
bool is_odd(const Complex& num1);
bool is_even(const Complex& num1);
Complex add(const Complex& num1, const Complex& num2);
Complex sub(const Complex& num1, const Complex& num2);
Complex mul(const Complex& num1, const Complex& num2);
Complex div(const Complex& num1, const Complex& num2);
Complex quo(const Complex& num1, const Complex& num2);
Complex rem(const Complex& num1, const Complex& num2);
Complex mod(const Complex& num1, const Complex& num2);
Complex or_bits(const Complex& num1, const Complex& num2);
Complex and_bits(const Complex& num1, const Complex& num2);
Complex xor_bits(const Complex& num1, const Complex& num2);
Complex not_bits(const Complex& num1);
Complex lshift_bits(const Complex& num1, const Complex& bits);
Complex rshift_bits(const Complex& num1, const Complex& bits);
Complex abs(const Complex& num1);
Complex floor(const Complex& num1);
Complex ceil(const Complex& num1);
Complex round(const Complex& num1, uinteger_t precision);
Complex integer(const Complex& num1);
Complex decimal(const Complex& num1);
Complex pow(const Complex& num1, const Complex& exp);
Complex rooting(const Complex& num1, const Complex& exp);
Complex log(const Complex& base, const Complex& log);
Complex log2(const Complex& n);
Complex log10(const Complex& n);
Complex ln(const Complex& n);
Complex factorial(const Complex& num1);
std::pair<Complex, Complex> extended_euclidean(const Complex& num1, const Complex& num2);
Complex gcd(const Complex& num1, const Complex& num2);
Complex lcm(const Complex& num1, const Complex& num2);

//
// 三角函数
//
Complex sin(const Complex& x);
Complex cos(const Complex& x);
Complex tan(const Complex& x);
Complex csc(const Complex& x);
Complex sec(const Complex& x);
Complex cot(const Complex& x);

//
// 反三角函数
//
Complex arcsin(const Complex& x);
Complex arccos(const Complex& x);
Complex arctan(const Complex& x);
Complex arccsc(const Complex& x);
Complex arcsec(const Complex& x);
Complex arccot(const Complex& x);

//
// 双曲函数
//
Complex sinh(const Complex& x);
Complex cosh(const Complex& x);
Complex tanh(const Complex& x);
Complex csch(const Complex& x);
Complex sech(const Complex& x);
Complex coth(const Complex& x);

//
// 反双曲函数
//
Complex arcsinh(const Complex& x);
Complex arccosh(const Complex& x);
Complex arctanh(const Complex& x);
Complex arccsch(const Complex& x);
Complex arcsech(const Complex& x);
Complex arccoth(const Complex& x);

//
// 功能函数
//
void copy(Complex& to, const Complex& from);

//
// 友元重载运算符
//

// 双目算术运算符
Complex operator+(const Complex& num1, const Complex& num2);
Complex operator-(const Complex& num1, const Complex& num2);
Complex operator*(const Complex& num1, const Complex& num2);
Complex operator/(const Complex& num1, const Complex& num2);
Complex operator%(const Complex& num1, const Complex& num2);

Complex operator+(const Complex& num1, const char* num2);
Complex operator-(const Complex& num1, const char* num2);
Complex operator*(const Complex& num1, const char* num2);
Complex operator/(const Complex& num1, const char* num2);
Complex operator%(const Complex& num1, const char* num2);

Complex operator+(const char* num1, const Complex& num2);
Complex operator-(const char* num1, const Complex& num2);
Complex operator*(const char* num1, const Complex& num2);
Complex operator/(const char* num1, const Complex& num2);
Complex operator%(const char* num1, const Complex& num2);

// 关系运算符
bool operator==(const Complex& num1, const Complex& num2);
bool operator!=(const Complex& num1, const Complex& num2);
bool operator<(const Complex& num1, const Complex& num2);
bool operator>(const Complex& num1, const Complex& num2);
bool operator<=(const Complex& num1, const Complex& num2);
bool operator>=(const Complex& num1, const Complex& num2);

bool operator==(const Complex& num1, const char* num2);
bool operator!=(const Complex& num1, const char* num2);
bool operator<(const Complex& num1, const char* num2);
bool operator>(const Complex& num1, const char* num2);
bool operator<=(const Complex& num1, const char* num2);
bool operator>=(const Complex& num1, const char* num2);

bool operator==(const char* num1, const Complex& num2);
bool operator!=(const char* num1, const Complex& num2);
bool operator<(const char* num1, const Complex& num2);
bool operator>(const char* num1, const Complex& num2);
bool operator<=(const char* num1, const Complex& num2);
bool operator>=(const char* num1, const Complex& num2);

// 逻辑运算符
bool operator||(const Complex& num1, const Complex& num2);
bool operator&&(const Complex& num1, const Complex& num2);
bool operator!(const Complex& num1);

bool operator||(const Complex& num1, const char* num2);
bool operator&&(const Complex& num1, const char* num2);

bool operator||(const char* num1, const Complex& num2);
bool operator&&(const char* num1, const Complex& num2);

// 位运算符
Complex operator~(const Complex& num1);
Complex operator|(const Complex& num1, const Complex& num2);
Complex operator&(const Complex& num1, const Complex& num2);
Complex operator^(const Complex& num1, const Complex& num2);
Complex operator<<(const Complex& num1, const Complex& bits);
Complex operator>>(const Complex& num1, const Complex& bits);

Complex operator|(const Complex& num1, const char* num2);
Complex operator&(const Complex& num1, const char* num2);
Complex operator^(const Complex& num1, const char* num2);
Complex operator<<(const Complex& num1, const char* bits);
Complex operator>>(const Complex& num1, const char* bits);

Complex operator|(const char* num1, const Complex& num2);
Complex operator&(const char* num1, const Complex& num2);
Complex operator^(const char* num1, const Complex& num2);
Complex operator<<(const char* num1, const Complex& bits);
Complex operator>>(const char* num1, const Complex& bits);

Complex conjugate(const Complex& num1);

typedef std::shared_ptr<Complex> mynum_complex_t;

} // namespace number
} // namespace mynum

#endif // MYNUM_NUMBER_COMPLEX_H_