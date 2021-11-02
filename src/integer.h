#ifndef MYNUM_INTEGER_H_
#define MYNUM_INTEGER_H_

#include <ctype.h>
#include <iostream>

#include <mynum/numeric.h>

namespace mynum {

class Integer : public Numeric {
public:
  Integer();
  Integer(const bignum_t& number);
  virtual ~Integer();

  virtual std::string str() const;

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
  virtual void __create_from_string(const char* n, int base);
};

//
// 基础的运算
//
Integer add(const Integer& num1, const Integer& num2);
Integer sub(const Integer& num1, const Integer& num2);
Integer mul(const Integer& num1, const Integer& num2);
Integer div(const Integer& num1, const Integer& num2);
void idiv(const Integer& num1, const Integer& num2, Integer& quo, Integer& rem);
Integer quo(const Integer& num1, const Integer& num2);
Integer rem(const Integer& num1, const Integer& num2);
Integer mod(const Integer& num1, const Integer& num2);

Integer abs(const Integer& num1);
Integer pow(const Integer& num1, const Integer& exp);
Integer factorial(const Integer& num1);
std::pair<Integer, Integer> extended_euclidean(const Integer& num1, const Integer& num2);
Integer gcd(const Integer& num1, const Integer& num2);
Integer lcm(const Integer& num1, const Integer& num2);
int sgn(const Integer& num1);

//
// 离散运算
//
Integer or_bits(const Integer& num1, const Integer& num2);
Integer and_bits(const Integer& num1, const Integer& num2);
Integer xor_bits(const Integer& num1, const Integer& num2);
Integer not_bits(const Integer& num1);
Integer lshift_bits(const Integer& num1, const Integer& bits);
Integer rshift_bits(const Integer& num1, const Integer& bits);



// 双目算术运算符
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

// 关系运算符
bool operator==(const Integer& num1, const Integer& num2);
bool operator!=(const Integer& num1, const Integer& num2);
bool operator<(const Integer& num1, const Integer& num2);
bool operator>(const Integer& num1, const Integer& num2);
bool operator<=(const Integer& num1, const Integer& num2);
bool operator>=(const Integer& num1, const Integer& num2);

bool operator==(const Integer& num1, const char* num2);
bool operator!=(const Integer& num1, const char* num2);
bool operator<(const Integer& num1, const char* num2);
bool operator>(const Integer& num1, const char* num2);
bool operator<=(const Integer& num1, const char* num2);
bool operator>=(const Integer& num1, const char* num2);

bool operator==(const char* num1, const Integer& num2);
bool operator!=(const char* num1, const Integer& num2);
bool operator<(const char* num1, const Integer& num2);
bool operator>(const char* num1, const Integer& num2);
bool operator<=(const char* num1, const Integer& num2);
bool operator>=(const char* num1, const Integer& num2);

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

//
// 功能函数
//
void copy(Integer& to, const Integer& from);
void same_digits(Integer& num1, Integer& num2);

} // namespace mynum

#endif // MYNUM_INTEGER_H_