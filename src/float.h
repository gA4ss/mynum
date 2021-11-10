#ifndef MYNUM_FLOAT_H_
#define MYNUM_FLOAT_H_

#include <mynum/integer.h>

#include <ctype.h>
#include <iostream>

namespace mynum {

class Float {
public:
  Float();
  Float(const char* number, int base=10);
  Float(std::string& number, int base=10);
  Float(const bignum_t& integer_park);
  Float(const bignum_t& integer_park, const bignum_t& decimal_park);
  Float(const Integer& integer_park, const Integer& decimal_park);
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
  void operator+=(const Float& num2);
  void operator+=(const char* num2);
  void operator-=(const Float& num2);
  void operator-=(const char* num2);
  void operator*=(const Float& num2);
  void operator*=(const char* num2);
  void operator/=(const Float& num2);
  void operator/=(const char* num2);
  void operator%=(const Float& num2);
  void operator%=(const char* num2);

  // 迭代运算符
  char operator[](uinteger_t i);

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

Float add(const Float& num1, const Float& num2);
Float sub(const Float& num1, const Float& num2);
Float mul(const Float& num1, const Float& num2);
Float div(const Float& num1, const Float& num2, uinteger_t significant_digits=16);
void div2(const Float& num1, const Float& num2, Float& quo, Float& rem, uinteger_t significant_digits=16);
Float mod(const Float& num1, const Float& num2, uinteger_t significant_digits=16);

Float abs(const Float& num1);
Float floor(const Float& num1);
Float ceil(const Float& num1);
Float round(const Float& num1, uinteger_t significant_digits=0);
Float integer(const Float& num1);
Float pow(const Float& num1, const Float& exp);
Float rooting(const Float& num1, const Float& exp);
Float factorial(const Float& num1);
Float log(const Float& base, const Float& log);
Float log2(const Float& n);
Float log10(const Float& n);
Float ln(const Float& n);
int sgn(const Float& num1);

//
// 三角函数
//
Float sin(const Float& x, uinteger_t significant_digits=16);
Float cos(const Float& x);
Float tan(const Float& x);
Float csc(const Float& x);
Float sec(const Float& x);
Float cot(const Float& x);

//
// 反三角函数
//
Float arcsin(const Float& x);
Float arccos(const Float& x);
Float arctan(const Float& x);
Float arccsc(const Float& x);
Float arcsec(const Float& x);
Float arccot(const Float& x);

//
// 双曲函数
//
Float sinh(const Float& x);
Float cosh(const Float& x);
Float tanh(const Float& x);
Float csch(const Float& x);
Float sech(const Float& x);
Float coth(const Float& x);

//
// 反双曲函数
//
Float arcsinh(const Float& x);
Float arccosh(const Float& x);
Float arctanh(const Float& x);
Float arccsch(const Float& x);
Float arcsech(const Float& x);
Float arccoth(const Float& x);

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

bool operator||(const Float& num1, const Float& num2);
bool operator&&(const Float& num1, const Float& num2);
bool operator!(const Float& num1);
bool operator||(const Float& num1, const char* num2);
bool operator&&(const Float& num1, const char* num2);
bool operator||(const char* num1, const Float& num2);
bool operator&&(const char* num1, const Float& num2);

} // namespace mynum

#endif // MYNUM_INTEGER_H_