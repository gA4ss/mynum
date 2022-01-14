#ifndef MYNUM_FLOAT_H_
#define MYNUM_FLOAT_H_

#include <mynum/integer.h>

#include <ctype.h>
#include <iostream>

namespace mynum {

#define kDefEpsilon               "0.000001"

class Float {
public:
  Float();
  Float(const char* number, int base=10);
  Float(std::string number, int base=10);
  Float(my::float_t number);
  Float(const bignum_t& integer_park);
  Float(const bignum_t& integer_park, const bignum_t& decimal_park);
  Float(const Integer& integer_park, const Integer& decimal_park);
  Float(Integer* number);
  Float(const Integer& number);
  Float(Float* number);
  Float(const Float& number);
  virtual ~Float();

  void assign(const Float& n);
  void zero();
  void one();
  void nan();
  void none();

  int sign() const;
  bool infinite() const;
  bignum_t integer_park() const;
  bignum_t decimal_park() const;
  size_t precision() const;
  std::string str() const;

  void set_sign(int sign=kPositive);
  void set_infinite(bool infinite=true);
  void set_integer_park(const bignum_t& integer_park);
  void set_decimal_park(const bignum_t& decimal_park);
  void set_integer_park_zero();
  void set_decimal_park_zero();

  // 单目运算符 *(指针)，&(取地址)
  Float& operator+();
  Float& operator-();

  // 自增自减运算符
  Float& operator++();
  Float operator++(int);
  Float& operator--();
  Float operator--(int);

  // 赋值运算符
  void operator=(const Float& num2);
  void operator=(const char* num2);
  void operator=(const my::float_t& num2);
  void operator+=(const Float& num2);
  void operator+=(const char* num2);
  void operator+=(const my::float_t& num2);
  void operator-=(const Float& num2);
  void operator-=(const char* num2);
  void operator-=(const my::float_t& num2);
  void operator*=(const Float& num2);
  void operator*=(const char* num2);
  void operator*=(const my::float_t& num2);
  void operator/=(const Float& num2);
  void operator/=(const char* num2);
  void operator/=(const my::float_t& num2);
  void operator%=(const Float& num2);
  void operator%=(const char* num2);
  void operator%=(const my::float_t& num2);

  // 迭代运算符
  char operator[](my::uinteger_t i);

protected:
  void __create_from_string(const char* n, int base);

protected:
  int sign_;
  bool infinite_;
  bignum_t integer_park_;
  bignum_t decimal_park_;
};

//
// 与无穷相关的运算
//
int __cmp_infinite(const Float& num1, const Float& num2);
int __add_infinite(const Float& num1, const Float& num2);
int __sub_infinite(const Float& num1, const Float& num2);
int __mul_infinite(const Float& num1, const Float& num2);
int __div_infinite(const Float& num1, const Float& num2);
int __mod_infinite(const Float& num1, const Float& num2);
Float __infinite_operation_result(int inf, int unused=0);

//
// 比较运算
//
int __cmp(const Float& num1, const Float& num2);
bool equ(const Float& num1, const Float& num2);
bool gt(const Float& num1, const Float& num2);
bool lt(const Float& num1, const Float& num2);
bool ge(const Float& num1, const Float& num2);
bool le(const Float& num1, const Float& num2);

//
// 基础的运算
//
bool is_zero(const Float& num1);
bool is_one(const Float& num1);
bool is_nan(const Float& num1);
bool is_infinite(const Float& num1);
bool is_none(const Float& num1);
bool is_integer(const Float& num1);
bool is_float(const Float& num1);
bool is_subnormal(const Float& num1);

Float add(const Float& num1, const Float& num2);
Float sub(const Float& num1, const Float& num2);
Float mul(const Float& num1, const Float& num2);
Float div(const Float& num1, const Float& num2, my::uinteger_t significant_digits=16);
void div2(const Float& num1, const Float& num2, Float& quo, Float& rem, my::uinteger_t significant_digits=16);
Float mod(const Float& num1, const Float& num2, my::uinteger_t significant_digits=16);

Float abs(const Float& num1);
Float floor(const Float& num1);
Float ceil(const Float& num1);
Float round(const Float& num1, my::uinteger_t significant_digits=0);
Float integer(const Float& num1);
Float pow(const Float& a, const Float& x, const char* epsilon="0.0000000000000001");
Float exp(const Float& x, const char* epsilon="0.0000000000000001");
Float sqrt(const Float& num1, const char* epsilon=kDefEpsilon);
Float factorial(const Float& num1);
Float log(const Float& base, const Float& x, const char* epsilon="0.0000000000000001");
Float log2(const Float& x, const char* epsilon="0.0000000000000001");
Float log10(const Float& x, const char* epsilon="0.0000000000000001");
Float ln(const Float& x, const char* epsilon="0.0000000000000001");
int sgn(const Float& num1);

//
// 三角函数
//
Float sin(const Float& x, const char* epsilon=kDefEpsilon);
Float cos(const Float& x, const char* epsilon=kDefEpsilon);
Float tan(const Float& x, const char* epsilon=kDefEpsilon);
Float csc(const Float& x, const char* epsilon=kDefEpsilon);
Float sec(const Float& x, const char* epsilon=kDefEpsilon);
Float cot(const Float& x, const char* epsilon=kDefEpsilon);

//
// 反三角函数
//
Float arcsin(const Float& x, const char* epsilon=kDefEpsilon);
Float arccos(const Float& x, const char* epsilon=kDefEpsilon);
Float arctan(const Float& x, const char* epsilon=kDefEpsilon);
Float arccsc(const Float& x, const char* epsilon=kDefEpsilon);
Float arcsec(const Float& x, const char* epsilon=kDefEpsilon);
Float arccot(const Float& x, const char* epsilon=kDefEpsilon);

//
// 双曲函数
//
Float sinh(const Float& x, const char* epsilon=kDefEpsilon);
Float cosh(const Float& x, const char* epsilon=kDefEpsilon);
Float tanh(const Float& x, const char* epsilon=kDefEpsilon);
Float csch(const Float& x, const char* epsilon=kDefEpsilon);
Float sech(const Float& x, const char* epsilon=kDefEpsilon);
Float coth(const Float& x, const char* epsilon=kDefEpsilon);

//
// 反双曲函数
//
Float arcsinh(const Float& x, const char* epsilon=kDefEpsilon);
Float arccosh(const Float& x, const char* epsilon=kDefEpsilon);
Float arctanh(const Float& x, const char* epsilon=kDefEpsilon);
Float arccsch(const Float& x, const char* epsilon=kDefEpsilon);
Float arcsech(const Float& x, const char* epsilon=kDefEpsilon);
Float arccoth(const Float& x, const char* epsilon=kDefEpsilon);

//
// 误差函数
//
Float erf(const Float& x, const char* epsilon=kDefEpsilon);
Float erfc(const Float& x, const char* epsilon=kDefEpsilon);

//
// 伽马函数
//
Float gamma(const Float& x, const char* epsilon=kDefEpsilon);

//
// 分数相关
//
std::pair<Integer, Integer> fraction(const Float& x);

//
// 功能函数
//
void copy(Float& to, const Float& from);
void same_digits(Float& num1, Float& num2);

//
// 双目算术运算符
//
Float operator+(const Float& num1, const Float& num2);
Float operator-(const Float& num1, const Float& num2);
Float operator*(const Float& num1, const Float& num2);
Float operator/(const Float& num1, const Float& num2);
Float operator%(const Float& num1, const Float& num2);
Float operator+(const Float& num1, const char* num2);
Float operator-(const Float& num1, const char* num2);
Float operator*(const Float& num1, const char* num2);
Float operator/(const Float& num1, const char* num2);
Float operator%(const Float& num1, const char* num2);
Float operator+(const char* num1, const Float& num2);
Float operator-(const char* num1, const Float& num2);
Float operator*(const char* num1, const Float& num2);
Float operator/(const char* num1, const Float& num2);
Float operator%(const char* num1, const Float& num2);
Float operator+(const Float& num1, const my::float_t& num2);
Float operator-(const Float& num1, const my::float_t& num2);
Float operator*(const Float& num1, const my::float_t& num2);
Float operator/(const Float& num1, const my::float_t& num2);
Float operator%(const Float& num1, const my::float_t& num2);
Float operator+(const my::float_t& num1, const Float& num2);
Float operator-(const my::float_t& num1, const Float& num2);
Float operator*(const my::float_t& num1, const Float& num2);
Float operator/(const my::float_t& num1, const Float& num2);
Float operator%(const my::float_t& num1, const Float& num2);

bool operator==(const Float& num1, const Float& num2);
bool operator!=(const Float& num1, const Float& num2);
bool operator<(const Float& num1, const Float& num2);
bool operator>(const Float& num1, const Float& num2);
bool operator<=(const Float& num1, const Float& num2);
bool operator>=(const Float& num1, const Float& num2);
bool operator==(const Float& num1, const char* num2);
bool operator!=(const Float& num1, const char* num2);
bool operator<(const Float& num1, const char* num2);
bool operator>(const Float& num1, const char* num2);
bool operator<=(const Float& num1, const char* num2);
bool operator>=(const Float& num1, const char* num2);
bool operator==(const char* num1, const Float& num2);
bool operator!=(const char* num1, const Float& num2);
bool operator<(const char* num1, const Float& num2);
bool operator>(const char* num1, const Float& num2);
bool operator<=(const char* num1, const Float& num2);
bool operator>=(const char* num1, const Float& num2);
bool operator==(const Float& num1, const my::float_t& num2);
bool operator!=(const Float& num1, const my::float_t& num2);
bool operator<(const Float& num1, const my::float_t& num2);
bool operator>(const Float& num1, const my::float_t& num2);
bool operator<=(const Float& num1, const my::float_t& num2);
bool operator>=(const Float& num1, const my::float_t& num2);
bool operator==(const my::float_t& num1, const Float& num2);
bool operator!=(const my::float_t& num1, const Float& num2);
bool operator<(const my::float_t& num1, const Float& num2);
bool operator>(const my::float_t& num1, const Float& num2);
bool operator<=(const my::float_t& num1, const Float& num2);
bool operator>=(const my::float_t& num1, const Float& num2);

bool operator||(const Float& num1, const Float& num2);
bool operator&&(const Float& num1, const Float& num2);
bool operator!(const Float& num1);
bool operator||(const Float& num1, const char* num2);
bool operator&&(const Float& num1, const char* num2);
bool operator||(const char* num1, const Float& num2);
bool operator&&(const char* num1, const Float& num2);
bool operator||(const Float& num1, const my::float_t& num2);
bool operator&&(const Float& num1, const my::float_t& num2);
bool operator||(const my::float_t& num1, const Float& num2);
bool operator&&(const my::float_t& num1, const Float& num2);

std::ostream& operator << (std::ostream& out, const Float& num);
std::istream& operator >> (std::istream& in, Float& num);

} // namespace mynum

#endif // MYNUM_INTEGER_H_