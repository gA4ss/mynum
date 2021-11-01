#ifndef MYNUM_NUMERIC_H_
#define MYNUM_NUMERIC_H_

#include <ctype.h>
#include <iostream>

#include <mynum/common.h>

namespace mynum {

class Numeric;
typedef int8_t unit_t;
typedef std::deque<unit_t> bignum_t;
typedef std::pair<std::vector<Numeric>, std::vector<Numeric> > fraction_vector_t;
typedef std::vector<Numeric> array_t;

typedef struct Config {
  uinteger_t max_quotient_borrow;
  uinteger_t taylor_expansion;
  uinteger_t precision;
  std::string epsilon;
} config_t;

class Numeric {
public:
  Numeric();
  Numeric(const char* number, int base=10);
  Numeric(std::string& number, int base=10);
  Numeric(Numeric* number);
  Numeric(const Numeric& number);
  virtual ~Numeric();

  int sign() const { return sign_; }
  size_t precision() const { return decimal_park_.size(); }
  bignum_t integer_park() const { return integer_park_; }
  bignum_t decimal_park() const { return decimal_park_; }
  bool infinite() const { return infinite_; }

  void assign(const Numeric& n);
  void zero();
  void one(bool sign=true);
  void nan(bool sign=true);   // sign = false,为一种特殊的nan值，表示数值不确定。用于内部计算。为none值。
  void infinite(bool sign);
  void none();

  std::string str() const;

  //////////////////////////////
  // friend function
  //////////////////////////////

  //
  // 比较运算
  //
  friend bool equ(const Numeric& num1, const Numeric& num2);
  friend bool gt(const Numeric& num1, const Numeric& num2);
  friend bool lt(const Numeric& num1, const Numeric& num2);
  friend bool ge(const Numeric& num1, const Numeric& num2);
  friend bool le(const Numeric& num1, const Numeric& num2);

  //
  // 基础的运算
  //
  friend bool is_zero(const Numeric& num1);
  friend bool is_one(const Numeric& num1);
  friend bool is_nan(const Numeric& num1);
  friend bool is_infinite(const Numeric& num1);
  friend bool is_none(const Numeric& num1);
  friend bool is_integer(const Numeric& num1);
  friend bool is_float(const Numeric& num1);
  friend bool is_odd(const Numeric& num1);
  friend bool is_even(const Numeric& num1);

  friend Numeric add(const Numeric& num1, const Numeric& num2);
  friend Numeric sub(const Numeric& num1, const Numeric& num2);
  friend Numeric mul(const Numeric& num1, const Numeric& num2);
  friend Numeric div(const Numeric& num1, const Numeric& num2);
  friend void idiv(const Numeric& num1, const Numeric& num2, Numeric& quo, Numeric& rem);
  friend Numeric quo(const Numeric& num1, const Numeric& num2);
  friend Numeric rem(const Numeric& num1, const Numeric& num2);
  friend Numeric mod(const Numeric& num1, const Numeric& num2);
  friend Numeric or_bits(const Numeric& num1, const Numeric& num2);
  friend Numeric and_bits(const Numeric& num1, const Numeric& num2);
  friend Numeric xor_bits(const Numeric& num1, const Numeric& num2);
  friend Numeric not_bits(const Numeric& num1);
  friend Numeric lshift_bits(const Numeric& num1, const Numeric& bits);
  friend Numeric rshift_bits(const Numeric& num1, const Numeric& bits);
  friend Numeric abs(const Numeric& num1);
  friend Numeric floor(const Numeric& num1);
  friend Numeric ceil(const Numeric& num1);
  friend Numeric round(const Numeric& num1, uinteger_t precision=0);
  friend Numeric integer(const Numeric& num1);
  friend Numeric decimal(const Numeric& num1);
  friend Numeric pow(const Numeric& num1, const Numeric& exp);
  friend Numeric rooting(const Numeric& num1, const Numeric& exp);
  friend Numeric log(const Numeric& base, const Numeric& log);
  friend Numeric log2(const Numeric& n);
  friend Numeric log10(const Numeric& n);
  friend Numeric ln(const Numeric& n);
  friend Numeric factorial(const Numeric& num1);
  friend std::pair<Numeric, Numeric> extended_euclidean(const Numeric& num1, const Numeric& num2);
  friend Numeric gcd(const Numeric& num1, const Numeric& num2);
  friend Numeric lcm(const Numeric& num1, const Numeric& num2);
  friend int sgn(const Numeric& num1);

  //
  // 三角函数
  //
  friend Numeric sin(const Numeric& x);
  friend Numeric cos(const Numeric& x);
  friend Numeric tan(const Numeric& x);
  friend Numeric csc(const Numeric& x);
  friend Numeric sec(const Numeric& x);
  friend Numeric cot(const Numeric& x);

  //
  // 反三角函数
  //
  friend Numeric arcsin(const Numeric& x);
  friend Numeric arccos(const Numeric& x);
  friend Numeric arctan(const Numeric& x);
  friend Numeric arccsc(const Numeric& x);
  friend Numeric arcsec(const Numeric& x);
  friend Numeric arccot(const Numeric& x);

  //
  // 双曲函数
  //
  friend Numeric sinh(const Numeric& x);
  friend Numeric cosh(const Numeric& x);
  friend Numeric tanh(const Numeric& x);
  friend Numeric csch(const Numeric& x);
  friend Numeric sech(const Numeric& x);
  friend Numeric coth(const Numeric& x);

  //
  // 反双曲函数
  //
  friend Numeric arcsinh(const Numeric& x);
  friend Numeric arccosh(const Numeric& x);
  friend Numeric arctanh(const Numeric& x);
  friend Numeric arccsch(const Numeric& x);
  friend Numeric arcsech(const Numeric& x);
  friend Numeric arccoth(const Numeric& x);

  //
  // 各种代数数
  //
  friend fraction_vector_t bernoulli_numbers(uinteger_t n);
  friend array_t euler_numbers(uinteger_t m);

  //
  // 友元重载运算符
  //

  // 双目算术运算符
  friend Numeric operator+(const Numeric& num1, const Numeric& num2);
  friend Numeric operator-(const Numeric& num1, const Numeric& num2);
  friend Numeric operator*(const Numeric& num1, const Numeric& num2);
  friend Numeric operator/(const Numeric& num1, const Numeric& num2);
  friend Numeric operator%(const Numeric& num1, const Numeric& num2);

  friend Numeric operator+(const Numeric& num1, const char* num2);
  friend Numeric operator-(const Numeric& num1, const char* num2);
  friend Numeric operator*(const Numeric& num1, const char* num2);
  friend Numeric operator/(const Numeric& num1, const char* num2);
  friend Numeric operator%(const Numeric& num1, const char* num2);

  friend Numeric operator+(const char* num1, const Numeric& num2);
  friend Numeric operator-(const char* num1, const Numeric& num2);
  friend Numeric operator*(const char* num1, const Numeric& num2);
  friend Numeric operator/(const char* num1, const Numeric& num2);
  friend Numeric operator%(const char* num1, const Numeric& num2);

  // 关系运算符
  friend bool operator==(const Numeric& num1, const Numeric& num2);
  friend bool operator!=(const Numeric& num1, const Numeric& num2);
  friend bool operator<(const Numeric& num1, const Numeric& num2);
  friend bool operator>(const Numeric& num1, const Numeric& num2);
  friend bool operator<=(const Numeric& num1, const Numeric& num2);
  friend bool operator>=(const Numeric& num1, const Numeric& num2);

  friend bool operator==(const Numeric& num1, const char* num2);
  friend bool operator!=(const Numeric& num1, const char* num2);
  friend bool operator<(const Numeric& num1, const char* num2);
  friend bool operator>(const Numeric& num1, const char* num2);
  friend bool operator<=(const Numeric& num1, const char* num2);
  friend bool operator>=(const Numeric& num1, const char* num2);

  friend bool operator==(const char* num1, const Numeric& num2);
  friend bool operator!=(const char* num1, const Numeric& num2);
  friend bool operator<(const char* num1, const Numeric& num2);
  friend bool operator>(const char* num1, const Numeric& num2);
  friend bool operator<=(const char* num1, const Numeric& num2);
  friend bool operator>=(const char* num1, const Numeric& num2);

  // 逻辑运算符
  friend bool operator||(const Numeric& num1, const Numeric& num2);
  friend bool operator&&(const Numeric& num1, const Numeric& num2);
  friend bool operator!(const Numeric& num1);

  friend bool operator||(const Numeric& num1, const char* num2);
  friend bool operator&&(const Numeric& num1, const char* num2);

  friend bool operator||(const char* num1, const Numeric& num2);
  friend bool operator&&(const char* num1, const Numeric& num2);

  // 位运算符
  friend Numeric operator~(const Numeric& num1);
  friend Numeric operator|(const Numeric& num1, const Numeric& num2);
  friend Numeric operator&(const Numeric& num1, const Numeric& num2);
  friend Numeric operator^(const Numeric& num1, const Numeric& num2);
  friend Numeric operator<<(const Numeric& num1, const Numeric& bits);
  friend Numeric operator>>(const Numeric& num1, const Numeric& bits);

  friend Numeric operator|(const Numeric& num1, const char* num2);
  friend Numeric operator&(const Numeric& num1, const char* num2);
  friend Numeric operator^(const Numeric& num1, const char* num2);
  friend Numeric operator<<(const Numeric& num1, const char* bits);
  friend Numeric operator>>(const Numeric& num1, const char* bits);

  friend Numeric operator|(const char* num1, const Numeric& num2);
  friend Numeric operator&(const char* num1, const Numeric& num2);
  friend Numeric operator^(const char* num1, const Numeric& num2);
  friend Numeric operator<<(const char* num1, const Numeric& bits);
  friend Numeric operator>>(const char* num1, const Numeric& bits);

  //
  // 功能函数
  //
  friend void copy(Numeric& to, const Numeric& from);
  friend void same_digits(Numeric& num1, Numeric& num2);

  //
  // 重载运算符，非友元。
  //

  // 单目运算符 *(指针)，&(取地址)
  Numeric& operator+();
  Numeric& operator-();

  // 自增自减运算符
  Numeric& operator++();
  Numeric operator++(int);
  Numeric& operator--();
  Numeric operator--(int);

  // 赋值运算符
  void operator=(const Numeric& num2);
  void operator=(const char* num2);
  void operator+=(const Numeric& num2);
  void operator+=(const char* num2);
  void operator-=(const Numeric& num2);
  void operator-=(const char* num2);
  void operator*=(const Numeric& num2);
  void operator*=(const char* num2);
  void operator/=(const Numeric& num2);
  void operator/=(const char* num2);
  void operator%=(const Numeric& num2);
  void operator%=(const char* num2);
  void operator&=(const Numeric& num2);
  void operator&=(const char* num2);
  void operator|=(const Numeric& num2);
  void operator|=(const char* num2);
  void operator^=(const Numeric& num2);
  void operator^=(const char* num2);
  void operator<<=(const Numeric& bits);
  void operator>>=(const Numeric& bits);

  // 迭代运算符
  char operator[](uinteger_t i);

  //////////////////////////////
  // static function
  //////////////////////////////
  static void set_config(config_t& config) { config_ = config; }
  static config_t config() { return config_; }

protected:
  void __create_from_string(const char* n, int base);
  void __set_sign(bool sign) { sign_ = static_cast<int>(sign); }
  void __set_integer_park(const bignum_t& integer_park) { integer_park_ = integer_park; }
  void __set_decimal_park(const bignum_t& decimal_park) { decimal_park_ = decimal_park; }
  void __set_infinite(bool infinite) { infinite_ = infinite; }
  void __set_integer_park_zero();
  void __set_decimal_park_zero();

protected:
  int sign_;
  bignum_t integer_park_;
  bignum_t decimal_park_;
  bool infinite_;

  //////////////////////////////
  // static variable
  //////////////////////////////
  static config_t config_;
};

//
// 比较运算
//
bool equ(const Numeric& num1, const Numeric& num2);
bool gt(const Numeric& num1, const Numeric& num2);
bool lt(const Numeric& num1, const Numeric& num2);
bool ge(const Numeric& num1, const Numeric& num2);
bool le(const Numeric& num1, const Numeric& num2);

//
// 基础的运算
//
bool is_zero(const Numeric& num1);
bool is_one(const Numeric& num1);
bool is_nan(const Numeric& num1);
bool is_infinite(const Numeric& num1);
bool is_none(const Numeric& num1);
bool is_integer(const Numeric& num1);
bool is_float(const Numeric& num1);
bool is_odd(const Numeric& num1);
bool is_even(const Numeric& num1);
Numeric add(const Numeric& num1, const Numeric& num2);
Numeric sub(const Numeric& num1, const Numeric& num2);
Numeric mul(const Numeric& num1, const Numeric& num2);
Numeric div(const Numeric& num1, const Numeric& num2);
void idiv(const Numeric& num1, const Numeric& num2, Numeric& quo, Numeric& rem);
Numeric quo(const Numeric& num1, const Numeric& num2);
Numeric rem(const Numeric& num1, const Numeric& num2);
Numeric mod(const Numeric& num1, const Numeric& num2);
Numeric or_bits(const Numeric& num1, const Numeric& num2);
Numeric and_bits(const Numeric& num1, const Numeric& num2);
Numeric xor_bits(const Numeric& num1, const Numeric& num2);
Numeric not_bits(const Numeric& num1);
Numeric lshift_bits(const Numeric& num1, const Numeric& bits);
Numeric rshift_bits(const Numeric& num1, const Numeric& bits);
Numeric abs(const Numeric& num1);
Numeric floor(const Numeric& num1);
Numeric ceil(const Numeric& num1);
Numeric round(const Numeric& num1, uinteger_t precision);
Numeric integer(const Numeric& num1);
Numeric decimal(const Numeric& num1);
Numeric pow(const Numeric& num1, const Numeric& exp);
Numeric rooting(const Numeric& num1, const Numeric& exp);
Numeric log(const Numeric& base, const Numeric& log);
Numeric log2(const Numeric& n);
Numeric log10(const Numeric& n);
Numeric ln(const Numeric& n);
Numeric factorial(const Numeric& num1);
std::pair<Numeric, Numeric> extended_euclidean(const Numeric& num1, const Numeric& num2);
Numeric gcd(const Numeric& num1, const Numeric& num2);
Numeric lcm(const Numeric& num1, const Numeric& num2);
int sgn(const Numeric& num1);

//
// 三角函数
//
Numeric sin(const Numeric& x);
Numeric cos(const Numeric& x);
Numeric tan(const Numeric& x);
Numeric csc(const Numeric& x);
Numeric sec(const Numeric& x);
Numeric cot(const Numeric& x);

//
// 反三角函数
//
Numeric arcsin(const Numeric& x);
Numeric arccos(const Numeric& x);
Numeric arctan(const Numeric& x);
Numeric arccsc(const Numeric& x);
Numeric arcsec(const Numeric& x);
Numeric arccot(const Numeric& x);

//
// 双曲函数
//
Numeric sinh(const Numeric& x);
Numeric cosh(const Numeric& x);
Numeric tanh(const Numeric& x);
Numeric csch(const Numeric& x);
Numeric sech(const Numeric& x);
Numeric coth(const Numeric& x);

//
// 反双曲函数
//
Numeric arcsinh(const Numeric& x);
Numeric arccosh(const Numeric& x);
Numeric arctanh(const Numeric& x);
Numeric arccsch(const Numeric& x);
Numeric arcsech(const Numeric& x);
Numeric arccoth(const Numeric& x);

//
// 各种代数数
//
fraction_vector_t bernoulli_numbers(uinteger_t n);
array_t euler_numbers(uinteger_t m);

//
// 友元重载运算符
//

// 双目算术运算符
Numeric operator+(const Numeric& num1, const Numeric& num2);
Numeric operator-(const Numeric& num1, const Numeric& num2);
Numeric operator*(const Numeric& num1, const Numeric& num2);
Numeric operator/(const Numeric& num1, const Numeric& num2);
Numeric operator%(const Numeric& num1, const Numeric& num2);

Numeric operator+(const Numeric& num1, const char* num2);
Numeric operator-(const Numeric& num1, const char* num2);
Numeric operator*(const Numeric& num1, const char* num2);
Numeric operator/(const Numeric& num1, const char* num2);
Numeric operator%(const Numeric& num1, const char* num2);

Numeric operator+(const char* num1, const Numeric& num2);
Numeric operator-(const char* num1, const Numeric& num2);
Numeric operator*(const char* num1, const Numeric& num2);
Numeric operator/(const char* num1, const Numeric& num2);
Numeric operator%(const char* num1, const Numeric& num2);

// 逻辑运算符
bool operator||(const Numeric& num1, const Numeric& num2);
bool operator&&(const Numeric& num1, const Numeric& num2);
bool operator!(const Numeric& num1);

bool operator||(const Numeric& num1, const char* num2);
bool operator&&(const Numeric& num1, const char* num2);

bool operator||(const char* num1, const Numeric& num2);
bool operator&&(const char* num1, const Numeric& num2);

// 位运算符
Numeric operator~(const Numeric& num1);
Numeric operator|(const Numeric& num1, const Numeric& num2);
Numeric operator&(const Numeric& num1, const Numeric& num2);
Numeric operator^(const Numeric& num1, const Numeric& num2);
Numeric operator<<(const Numeric& num1, const Numeric& bits);
Numeric operator>>(const Numeric& num1, const Numeric& bits);

Numeric operator|(const Numeric& num1, const char* num2);
Numeric operator&(const Numeric& num1, const char* num2);
Numeric operator^(const Numeric& num1, const char* num2);
Numeric operator<<(const Numeric& num1, const char* bits);
Numeric operator>>(const Numeric& num1, const char* bits);

Numeric operator|(const char* num1, const Numeric& num2);
Numeric operator&(const char* num1, const Numeric& num2);
Numeric operator^(const char* num1, const Numeric& num2);
Numeric operator<<(const char* num1, const Numeric& bits);
Numeric operator>>(const char* num1, const Numeric& bits);

//
// 功能函数
//
void copy(Numeric& to, const Numeric& from);
void same_digits(Numeric& num1, Numeric& num2);

} // namespace mynum

#endif // MYNUM_NUMERIC_H_