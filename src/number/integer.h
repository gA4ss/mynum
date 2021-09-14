#ifndef MYNUM_NUMBER_INTEGER_H_
#define MYNUM_NUMBER_INTEGER_H_

#include <mynum/number/real.h>

namespace mynum {
namespace number {

class Integer : public Real {
public:
  Integer() { zero(); }
  Integer(const char* number, int base=10) { __create_from_string(number, base); real_park_ = integer(real_park_); }
  Integer(std::string& number, int base=10) { __create_from_string(number.c_str(), base); real_park_ = integer(real_park_); }
  Integer(const Numeric& real_park) { real_park_ = integer(real_park); }
  Integer(Integer* number) { assign(*number); }
  Integer(const Integer& number) { assign(number); }
  virtual ~Integer() {}

  Numeric integer_park() const { return integer(real_park_); }
  virtual std::string str() const { return integer_park().str(); }
  virtual std::string class_name() const { return "integer"; }

  virtual void assign(const Integer& n) { real_park_ = integer(n.real_park()); }

  //////////////////////////////
  // operation function
  //////////////////////////////

  // 单目运算符 *(指针)，&(取地址)
  Integer& operator+() { +real_park_; return *this; }
  Integer& operator-() { -real_park_; return *this; }

  // 自增自减运算符
  Integer& operator++() { ++real_park_; return *this; }
  Integer operator++(int) { Integer t = *this; real_park_++; return t; }
  Integer& operator--() { --real_park_; return *this; }
  Integer operator--(int) { Integer t = *this; real_park_--; return t; }

  //////////////////////////////
  // friend function
  //////////////////////////////
  //
  // 比较运算
  //
  friend bool equ(const Integer& num1, const Integer& num2);
  friend bool gt(const Integer& num1, const Integer& num2);
  friend bool lt(const Integer& num1, const Integer& num2);
  friend bool ge(const Integer& num1, const Integer& num2);
  friend bool le(const Integer& num1, const Integer& num2);

  //
  // 基础的运算
  //
  friend bool is_zero(const Integer& num1);
  friend bool is_one(const Integer& num1);
  friend bool is_nan(const Integer& num1);
  friend bool is_infinite(const Integer& num1);
  friend bool is_none(const Integer& num1);
  friend bool is_integer(const Integer& num1);
  friend bool is_float(const Integer& num1);
  friend bool is_odd(const Integer& num1);
  friend bool is_even(const Integer& num1);
  friend Integer add(const Integer& num1, const Integer& num2);
  friend Integer sub(const Integer& num1, const Integer& num2);
  friend Integer mul(const Integer& num1, const Integer& num2);
  friend Integer div(const Integer& num1, const Integer& num2);
  friend Integer quo(const Integer& num1, const Integer& num2);
  friend Integer rem(const Integer& num1, const Integer& num2);
  friend Integer mod(const Integer& num1, const Integer& num2);
  friend Integer or_bits(const Integer& num1, const Integer& num2);
  friend Integer and_bits(const Integer& num1, const Integer& num2);
  friend Integer xor_bits(const Integer& num1, const Integer& num2);
  friend Integer not_bits(const Integer& num1);
  friend Integer lshift_bits(const Integer& num1, const Integer& bits);
  friend Integer rshift_bits(const Integer& num1, const Integer& bits);
  friend Integer abs(const Integer& num1);
  friend Integer floor(const Integer& num1);
  friend Integer ceil(const Integer& num1);
  friend Integer round(const Integer& num1, uinteger_t precision=0);
  friend Integer pow(const Integer& num1, const Integer& exp);
  friend Integer rooting(const Integer& num1, const Integer& exp);
  friend Integer log(const Integer& base, const Integer& log);
  friend Integer log2(const Integer& log);
  friend Integer log10(const Integer& log);
  friend Integer ln(const Integer& log);
  friend Integer factorial(const Integer& num1);
  friend std::pair<Integer, Integer> extended_euclidean(const Integer& num1, const Integer& num2);
  friend Integer gcd(const Integer& num1, const Integer& num2);
  friend Integer lcm(const Integer& num1, const Integer& num2);

  //
  // 友元重载运算符
  //

  // 双目算术运算符
  friend Integer operator+(const Integer& num1, const Integer& num2);
  friend Integer operator-(const Integer& num1, const Integer& num2);
  friend Integer operator*(const Integer& num1, const Integer& num2);
  friend Integer operator/(const Integer& num1, const Integer& num2);
  friend Integer operator%(const Integer& num1, const Integer& num2);

  friend Integer operator+(const Integer& num1, const char* num2);
  friend Integer operator-(const Integer& num1, const char* num2);
  friend Integer operator*(const Integer& num1, const char* num2);
  friend Integer operator/(const Integer& num1, const char* num2);
  friend Integer operator%(const Integer& num1, const char* num2);

  friend Integer operator+(const char* num1, const Integer& num2);
  friend Integer operator-(const char* num1, const Integer& num2);
  friend Integer operator*(const char* num1, const Integer& num2);
  friend Integer operator/(const char* num1, const Integer& num2);
  friend Integer operator%(const char* num1, const Integer& num2);

  // 关系运算符
  friend bool operator==(const Integer& num1, const Integer& num2);
  friend bool operator!=(const Integer& num1, const Integer& num2);
  friend bool operator<(const Integer& num1, const Integer& num2);
  friend bool operator>(const Integer& num1, const Integer& num2);
  friend bool operator<=(const Integer& num1, const Integer& num2);
  friend bool operator>=(const Integer& num1, const Integer& num2);

  friend bool operator==(const Integer& num1, const char* num2);
  friend bool operator!=(const Integer& num1, const char* num2);
  friend bool operator<(const Integer& num1, const char* num2);
  friend bool operator>(const Integer& num1, const char* num2);
  friend bool operator<=(const Integer& num1, const char* num2);
  friend bool operator>=(const Integer& num1, const char* num2);

  friend bool operator==(const char* num1, const Integer& num2);
  friend bool operator!=(const char* num1, const Integer& num2);
  friend bool operator<(const char* num1, const Integer& num2);
  friend bool operator>(const char* num1, const Integer& num2);
  friend bool operator<=(const char* num1, const Integer& num2);
  friend bool operator>=(const char* num1, const Integer& num2);

  // 逻辑运算符
  friend bool operator||(const Integer& num1, const Integer& num2);
  friend bool operator&&(const Integer& num1, const Integer& num2);
  friend bool operator!(const Integer& num1);

  friend bool operator||(const Integer& num1, const char* num2);
  friend bool operator&&(const Integer& num1, const char* num2);

  friend bool operator||(const char* num1, const Integer& num2);
  friend bool operator&&(const char* num1, const Integer& num2);

  // 位运算符
  friend Integer operator~(const Integer& num1);
  friend Integer operator|(const Integer& num1, const Integer& num2);
  friend Integer operator&(const Integer& num1, const Integer& num2);
  friend Integer operator^(const Integer& num1, const Integer& num2);
  friend Integer operator<<(const Integer& num1, const Integer& bits);
  friend Integer operator>>(const Integer& num1, const Integer& bits);

  friend Integer operator|(const Integer& num1, const char* num2);
  friend Integer operator&(const Integer& num1, const char* num2);
  friend Integer operator^(const Integer& num1, const char* num2);
  friend Integer operator<<(const Integer& num1, const char* bits);
  friend Integer operator>>(const Integer& num1, const char* bits);

  friend Integer operator|(const char* num1, const Integer& num2);
  friend Integer operator&(const char* num1, const Integer& num2);
  friend Integer operator^(const char* num1, const Integer& num2);
  friend Integer operator<<(const char* num1, const Integer& bits);
  friend Integer operator>>(const char* num1, const Integer& bits);

  // 赋值运算符
  virtual void operator=(const Integer& num2) { assign(num2); }
  virtual void operator=(const char* num2) { assign(Integer(num2)); }
  virtual void operator+=(const Integer& num2) { *this = add(*this, num2); }
  virtual void operator+=(const char* num2) { *this += Integer(num2); }
  virtual void operator-=(const Integer& num2) { *this = sub(*this, num2); }
  virtual void operator-=(const char* num2) { *this -= Integer(num2); }
  virtual void operator*=(const Integer& num2) { *this = mul(*this, num2); }
  virtual void operator*=(const char* num2) { *this *= Integer(num2); }
  virtual void operator/=(const Integer& num2) { *this = div(*this, num2); }
  virtual void operator/=(const char* num2) { *this /= Integer(num2); }
  virtual void operator%=(const Integer& num2) { *this = mod(*this, num2); }
  virtual void operator%=(const char* num2) { *this %= Integer(num2); }
  virtual void operator&=(const Integer& num2) { *this = and_bits(*this, num2); }
  virtual void operator&=(const char* num2) { *this &= Integer(num2); }
  virtual void operator|=(const Integer& num2) { *this = or_bits(*this, num2); }
  virtual void operator|=(const char* num2) { *this |= Integer(num2); }
  virtual void operator^=(const Integer& num2) { *this = xor_bits(*this, num2); }
  virtual void operator^=(const char* num2) { *this ^= Integer(num2);  }
  virtual void operator<<=(const Integer& bits) { *this = lshift_bits(*this, bits); }
  virtual void operator>>=(const Integer& bits) { *this = rshift_bits(*this, bits); }
};

typedef std::shared_ptr<Integer> mynum_integer_t;

} // namespace number
} // namespace mynum

#endif // MYNUM_NUMBER_INTEGER_H_