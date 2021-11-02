#ifndef MYNUM_NUMERIC_H_
#define MYNUM_NUMERIC_H_

#include <ctype.h>
#include <iostream>

#include <mynum/common.h>
#include <mynum/bignum.h>

namespace mynum {

// 与无穷相关的运算
enum {
  kOperandInfNegInfinity = -1,        // 结果是负无穷
  kOperandInfZero = 0,                // 结果是0
  kOperandInfPosInfinity = 1,         // 结果是正无穷
  kOperandInfOne = 2,                 // 结果是1
  kOperandInfNegOne = 3,              // 结果是-1
  kOperandInfNan = 4,                 // 结果是空值
  kOperandInfIndeterminacy = 5        // 结果不确定
};

class Numeric {
public:
  Numeric();
  Numeric(const char* number, int base=10);
  Numeric(std::string& number, int base=10);
  Numeric(Numeric* number);
  Numeric(const Numeric& number);
  virtual ~Numeric();

  void assign(const Numeric& n);
  void zero();
  void one(bool sign=true);
  void nan(bool sign=true);   // sign = false,为一种特殊的nan值，表示数值不确定。用于内部计算。为none值。
  void none();

  int sign() const { return sign_; }
  bool infinite() const { return infinite_; }
  size_t precision() const { return decimal_park_.size(); }
  bignum_t integer_park() const { return integer_park_; }
  bignum_t decimal_park() const { return decimal_park_; }
  virtual std::string str() const;

  void set_sign(bool negative=false);
  void set_infinite(int sign=kPositive);
  void set_integer_park(const bignum_t& integer_park) { integer_park_ = integer_park; }
  void set_decimal_park(const bignum_t& decimal_park) { decimal_park_ = decimal_park; }
  void set_integer_park_zero();
  void set_decimal_park_zero();

  // 单目运算符 *(指针)，&(取地址)
  Numeric& operator+();
  Numeric& operator-();
  // 迭代运算符
  char operator[](uinteger_t i);

protected:
  virtual void __create_from_string(const char* n, int base);

protected:
  int sign_;
  bool infinite_;

  bignum_t integer_park_;
  bignum_t decimal_park_;
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
bool equ(const Numeric& num1, const Numeric& num2);
bool gt(const Numeric& num1, const Numeric& num2);
bool lt(const Numeric& num1, const Numeric& num2);
bool ge(const Numeric& num1, const Numeric& num2);
bool le(const Numeric& num1, const Numeric& num2);

//
// 基础运算
//
Numeric abs(const Numeric& num1);
Numeric integer(const Numeric& num1);
Numeric decimal(const Numeric& num1);
int sgn(const Numeric& num1);

//
// 判断类型
//
bool is_zero(const Numeric& num1);
bool is_one(const Numeric& num1);
bool is_nan(const Numeric& num1);
bool is_infinite(const Numeric& num1);
bool is_none(const Numeric& num1);
bool is_integer(const Numeric& num1);
bool is_float(const Numeric& num1);

//
// 功能函数
//
void copy(Numeric& to, const Numeric& from);
void same_digits(Numeric& num1, Numeric& num2);

//
// 关系运算符
//
bool operator==(const Numeric& num1, const Numeric& num2);
bool operator!=(const Numeric& num1, const Numeric& num2);
bool operator<(const Numeric& num1, const Numeric& num2);
bool operator>(const Numeric& num1, const Numeric& num2);
bool operator<=(const Numeric& num1, const Numeric& num2);
bool operator>=(const Numeric& num1, const Numeric& num2);

bool operator==(const Numeric& num1, const char* num2);
bool operator!=(const Numeric& num1, const char* num2);
bool operator<(const Numeric& num1, const char* num2);
bool operator>(const Numeric& num1, const char* num2);
bool operator<=(const Numeric& num1, const char* num2);
bool operator>=(const Numeric& num1, const char* num2);

bool operator==(const char* num1, const Numeric& num2);
bool operator!=(const char* num1, const Numeric& num2);
bool operator<(const char* num1, const Numeric& num2);
bool operator>(const char* num1, const Numeric& num2);
bool operator<=(const char* num1, const Numeric& num2);
bool operator>=(const char* num1, const Numeric& num2);

// 逻辑运算符
bool operator||(const Numeric& num1, const Numeric& num2);
bool operator&&(const Numeric& num1, const Numeric& num2);
bool operator!(const Numeric& num1);

bool operator||(const Numeric& num1, const char* num2);
bool operator&&(const Numeric& num1, const char* num2);

bool operator||(const char* num1, const Numeric& num2);
bool operator&&(const char* num1, const Numeric& num2);

} // namespace mynum

#endif // MYNUM_NUMERIC_H_