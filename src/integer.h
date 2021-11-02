#ifndef MYNUM_INTEGER_H_
#define MYNUM_INTEGER_H_

#include <mynum/bignum.h>

#include <ctype.h>
#include <iostream>

namespace mynum {

class Integer {
public:
  Integer();
  Integer(const char* number, int base=10);
  Integer(std::string& number, int base=10);
  Integer(Integer* number);
  Integer(const Integer& number);
  virtual ~Integer();

  void assign(const Integer& n);
  void zero();
  void one(bool sign=true);
  void nan(bool sign=true);   // sign = false,为一种特殊的nan值，表示数值不确定。用于内部计算。为none值。
  void none();

  int sign() const;
  bool infinite() const;
  bignum_t integer_park() const;
  std::string str() const;

  void set_sign(bool sign);
  void set_infinite(bool infinite);
  void set_integer_park(const bignum_t& integer_park);
  void set_integer_park_zero();

  // 单目运算符 *(指针)，&(取地址)
  Integer& operator+();
  Integer& operator-();

  // 自增自减运算符
  Integer& operator++();
  Integer operator++(int);
  Integer& operator--();
  Integer operator--(int);

  // 赋值运算符
  void operator=(const Integer& num2);
  void operator=(const char* num2);
  void operator+=(const Integer& num2);
  void operator+=(const char* num2);
  void operator-=(const Integer& num2);
  void operator-=(const char* num2);
  void operator*=(const Integer& num2);
  void operator*=(const char* num2);
  void operator/=(const Integer& num2);
  void operator/=(const char* num2);
  void operator%=(const Integer& num2);
  void operator%=(const char* num2);
  void operator&=(const Integer& num2);
  void operator&=(const char* num2);
  void operator|=(const Integer& num2);
  void operator|=(const char* num2);
  void operator^=(const Integer& num2);
  void operator^=(const char* num2);
  void operator<<=(const Integer& bits);
  void operator>>=(const Integer& bits);

  // 迭代运算符
  char operator[](uinteger_t i);

protected:
  void __create_from_string(const char* n, int base);

protected:
  int sign_;
  bool infinite_;
  bignum_t integer_park_;
};

//
// 与无穷相关的运算
//
int cmp_infinite(const Numeric& num1, const Numeric& num2);
int add_infinite(const Numeric& num1, const Numeric& num2);
int sub_infinite(const Numeric& num1, const Numeric& num2);
int mul_infinite(const Numeric& num1, const Numeric& num2);
int div_infinite(const Numeric& num1, const Numeric& num2);
int mod_infinite(const Numeric& num1, const Numeric& num2);
Numeric infinite_operation_result(int inf);

//
// 比较运算
//
bool equ(const Integer& num1, const Integer& num2);
bool gt(const Integer& num1, const Integer& num2);
bool lt(const Integer& num1, const Integer& num2);
bool ge(const Integer& num1, const Integer& num2);
bool le(const Integer& num1, const Integer& num2);

//
// 基础的运算
//
bool is_zero(const Integer& num1);
bool is_one(const Integer& num1);
bool is_nan(const Integer& num1);
bool is_infinite(const Integer& num1);
bool is_none(const Integer& num1);
bool is_odd(const Integer& num1);
bool is_even(const Integer& num1);

Integer add(const Integer& num1, const Integer& num2);
Integer sub(const Integer& num1, const Integer& num2);
Integer mul(const Integer& num1, const Integer& num2);
Integer div(const Integer& num1, const Integer& num2);
std::pair<Integer, Integer> div(const Integer& num1, const Integer& num2);
Integer quo(const Integer& num1, const Integer& num2);
Integer mod(const Integer& num1, const Integer& num2);

Integer abs(const Integer& num1);
Integer pow(const Integer& num1, const Integer& exp);
Integer factorial(const Integer& num1);
std::pair<Integer, Integer> extended_euclidean(const Integer& num1, const Integer& num2);
Integer gcd(const Integer& num1, const Integer& num2);
Integer lcm(const Integer& num1, const Integer& num2);
int sgn(const Integer& num1);

Integer or_bits(const Integer& num1, const Integer& num2);
Integer and_bits(const Integer& num1, const Integer& num2);
Integer xor_bits(const Integer& num1, const Integer& num2);
Integer not_bits(const Integer& num1);
Integer lshift_bits(const Integer& num1, const Integer& bits);
Integer rshift_bits(const Integer& num1, const Integer& bits);

//
// 功能函数
//
void copy(Integer& to, const Integer& from);
void same_digits(Integer& num1, Integer& num2);

//
// 双目算术运算符
//
Integer operator+(const Integer& num1, const Integer& num2);
Integer operator-(const Integer& num1, const Integer& num2);
Integer operator*(const Integer& num1, const Integer& num2);
Integer operator/(const Integer& num1, const Integer& num2);
Integer operator%(const Integer& num1, const Integer& num2);

Integer operator+(const Integer& num1, const char* num2);
Integer operator-(const Integer& num1, const char* num2);
Integer operator*(const Integer& num1, const char* num2);
Integer operator/(const Integer& num1, const char* num2);
Integer operator%(const Integer& num1, const char* num2);

Integer operator+(const char* num1, const Integer& num2);
Integer operator-(const char* num1, const Integer& num2);
Integer operator*(const char* num1, const Integer& num2);
Integer operator/(const char* num1, const Integer& num2);
Integer operator%(const char* num1, const Integer& num2);

// 逻辑运算符
bool operator||(const Integer& num1, const Integer& num2);
bool operator&&(const Integer& num1, const Integer& num2);
bool operator!(const Integer& num1);

bool operator||(const Integer& num1, const char* num2);
bool operator&&(const Integer& num1, const char* num2);

bool operator||(const char* num1, const Integer& num2);
bool operator&&(const char* num1, const Integer& num2);

// 位运算符
Integer operator~(const Integer& num1);
Integer operator|(const Integer& num1, const Integer& num2);
Integer operator&(const Integer& num1, const Integer& num2);
Integer operator^(const Integer& num1, const Integer& num2);
Integer operator<<(const Integer& num1, const Integer& bits);
Integer operator>>(const Integer& num1, const Integer& bits);

Integer operator|(const Integer& num1, const char* num2);
Integer operator&(const Integer& num1, const char* num2);
Integer operator^(const Integer& num1, const char* num2);
Integer operator<<(const Integer& num1, const char* bits);
Integer operator>>(const Integer& num1, const char* bits);

Integer operator|(const char* num1, const Integer& num2);
Integer operator&(const char* num1, const Integer& num2);
Integer operator^(const char* num1, const Integer& num2);
Integer operator<<(const char* num1, const Integer& bits);
Integer operator>>(const char* num1, const Integer& bits);

} // namespace mynum

#endif // MYNUM_INTEGER_H_