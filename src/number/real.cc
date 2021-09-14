#include <mynum/number/real.h>

namespace mynum {
namespace number {

bool equ(const Real& num1, const Real& num2) {
  return equ(num1.real_park(), num2.real_park());
}

bool gt(const Real& num1, const Real& num2) {
  return gt(num1.real_park(), num2.real_park());
}

bool lt(const Real& num1, const Real& num2) {
  return lt(num1.real_park(), num2.real_park());
}

bool ge(const Real& num1, const Real& num2) {
  return ge(num1.real_park(), num2.real_park());
}

bool le(const Real& num1, const Real& num2) {
  return le(num1.real_park(), num2.real_park());
}

bool is_zero(const Real& num1) {
  return is_zero(num1.real_park_);
}

bool is_one(const Real& num1) {
  return is_one(num1.real_park_);
}

bool is_nan(const Real& num1) {
  return is_nan(num1.real_park_);
}

bool is_infinite(const Real& num1) {
  return is_infinite(num1.real_park_);
}

bool is_none(const Real& num1) {
  return is_none(num1.real_park_);
}

bool is_integer(const Real& num1) {
  return is_integer(num1.real_park_);
}

bool is_float(const Real& num1) {
  return is_float(num1.real_park_);
}

bool is_odd(const Real& num1) {
  return is_odd(num1.real_park_);
}

bool is_even(const Real& num1) {
  return is_even(num1.real_park_);
}

Real add(const Real& num1, const Real& num2) {
  Real res;
  res.real_park_ = add(num1.real_park(), num2.real_park());
  return res;
}

Real sub(const Real& num1, const Real& num2) {
  Real res;
  res.real_park_ = sub(num1.real_park(), num2.real_park());
  return res;
}
Real mul(const Real& num1, const Real& num2) {
  Real res;
  res.real_park_ = mul(num1.real_park(), num2.real_park());
  return res;
}

Real div(const Real& num1, const Real& num2) {
  Real res;
  res.real_park_ = div(num1.real_park(), num2.real_park());
  return res;
}

Real quo(const Real& num1, const Real& num2) {
  Real res;
  res.real_park_ = quo(num1.real_park(), num2.real_park());
  return res;
}

Real rem(const Real& num1, const Real& num2) {
  Real res;
  res.real_park_ = rem(num1.real_park(), num2.real_park());
  return res;
}

Real mod(const Real& num1, const Real& num2) {
  Real res;
  res.real_park_ = mod(num1.real_park(), num2.real_park());
  return res;
}

Real or_bits(const Real& num1, const Real& num2) {
  Real res;
  res.real_park_ = or_bits(num1.real_park(), num2.real_park());
  return res;
}

Real and_bits(const Real& num1, const Real& num2) {
  Real res;
  res.real_park_ = and_bits(num1.real_park(), num2.real_park());
  return res;
}

Real xor_bits(const Real& num1, const Real& num2) {
  Real res;
  res.real_park_ = xor_bits(num1.real_park(), num2.real_park());
  return res;
}

Real not_bits(const Real& num1) {
  Real res;
  res.real_park_ = not_bits(num1.real_park());
  return res;
}

Real lshift_bits(const Real& num1, const Real& bits) {
  Real res;
  res.real_park_ = lshift_bits(num1.real_park(), bits.real_park());
  return res;
}

Real rshift_bits(const Real& num1, const Real& bits) {
  Real res;
  res.real_park_ = rshift_bits(num1.real_park(), bits.real_park());
  return res;
}

Real abs(const Real& num1) {
  Real res;
  res.real_park_ = abs(num1.real_park());
  return res;
}

Real floor(const Real& num1) {
  Real res;
  res.real_park_ = floor(num1.real_park());
  return res;
}

Real ceil(const Real& num1) {
  Real res;
  res.real_park_ = ceil(num1.real_park());
  return res;
}

Real round(const Real& num1, uinteger_t precision) {
  Real res;

  res.real_park_ = round(num1.real_park(), precision);
  return res;
}

Real integer(const Real& num1) {
  Real res;
  res.real_park_ = integer(num1.real_park());
  return res;
}

Real decimal(const Real& num1) {
  Real res;
  res.real_park_ = decimal(num1.real_park());
  return res;
}

Real pow(const Real& num1, const Real& exp) {
  Real res;
  res.real_park_ = pow(num1.real_park(), exp.real_park());
  return res;
}

Real rooting(const Real& num1, const Real& exp) {
  Real res;
  res.real_park_ = rooting(num1.real_park(), exp.real_park());
  return res;
}

Real log(const Real& base, const Real& n) {
  Real res;
  res.real_park_ = log(base.real_park(), n.real_park());
  return res;
}

Real log2(const Real& log) {
  Real res;
  res.real_park_ = log2(log.real_park());
  return res;
}

Real log10(const Real& log) {
  Real res;
  res.real_park_ = log10(log.real_park());
  return res;
}

Real ln(const Real& log) {
  Real res;
  res.real_park_ = ln(log.real_park());
  return res;
}

Real factorial(const Real& num1) {
  Real res;
  res.real_park_ = factorial(num1.real_park());
  return res;
}

std::pair<Real, Real> extended_euclidean(const Real& num1, const Real& num2) {
  Real res1, res2;
  std::pair<Numeric, Numeric> num = 
    extended_euclidean(num1.real_park(), num2.real_park());
  res1.real_park_ = num.first;
  res2.real_park_ = num.second;
  return {res1, res2};
}

Real gcd(const Real& num1, const Real& num2) {
  Real res;
  res.real_park_ = gcd(num1.real_park(), num2.real_park());
  return res;
}

Real lcm(const Real& num1, const Real& num2) {
  Real res;
  res.real_park_ = lcm(num1.real_park(), num2.real_park());
  return res;
}

//
// 三角函数
//
Real sin(const Real& x) {
  Real res;
  res.real_park_ = sin(x.real_park());
  return res;
}

Real cos(const Real& x) {
  Real res;
  res.real_park_ = cos(x.real_park());
  return res;
}

Real tan(const Real& x) {
  Real res;
  res.real_park_ = tan(x.real_park());
  return res;
}

Real csc(const Real& x) {
  Real res;
  res.real_park_ = csc(x.real_park());
  return res;
}

Real sec(const Real& x) {
  Real res;
  res.real_park_ = sec(x.real_park());
  return res;
}

Real cot(const Real& x) {
  Real res;
  res.real_park_ = cot(x.real_park());
  return res;
}

//
// 反三角函数
//
Real arcsin(const Real& x) {
  Real res;
  res.real_park_ = arcsin(x.real_park());
  return res;
}

Real arccos(const Real& x) {
  Real res;
  res.real_park_ = arccos(x.real_park());
  return res;
}

Real arctan(const Real& x) {
  Real res;
  res.real_park_ = arctan(x.real_park());
  return res;
}

Real arccsc(const Real& x) {
  Real res;
  res.real_park_ = arccsc(x.real_park());
  return res;
}

Real arcsec(const Real& x) {
  Real res;
  res.real_park_ = arcsec(x.real_park());
  return res;
}

Real arccot(const Real& x) {
  Real res;
  res.real_park_ = arccot(x.real_park());
  return res;
}


//
// 双曲函数
//
Real sinh(const Real& x) {
  Real res;
  res.real_park_ = sinh(x.real_park());
  return res;
}

Real cosh(const Real& x) {
  Real res;
  res.real_park_ = cosh(x.real_park());
  return res;
}

Real tanh(const Real& x) {
  Real res;
  res.real_park_ = tanh(x.real_park());
  return res;
}

Real csch(const Real& x) {
  Real res;
  res.real_park_ = csch(x.real_park());
  return res;
}

Real sech(const Real& x) {
  Real res;
  res.real_park_ = sech(x.real_park());
  return res;
}

Real coth(const Real& x) {
  Real res;
  res.real_park_ = coth(x.real_park());
  return res;
}

//
// 反双曲函数
//
Real arcsinh(const Real& x) {
  Real res;
  res.real_park_ = arcsinh(x.real_park());
  return res;
}

Real arccosh(const Real& x) {
  Real res;
  res.real_park_ = arccosh(x.real_park());
  return res;
}

Real arctanh(const Real& x) {
  Real res;
  res.real_park_ = arctanh(x.real_park());
  return res;
}

Real arccsch(const Real& x) {
  Real res;
  res.real_park_ = arccsch(x.real_park());
  return res;
}

Real arcsech(const Real& x) {
  Real res;
  res.real_park_ = arcsech(x.real_park());
  return res;
}

Real arccoth(const Real& x) {
  Real res;
  res.real_park_ = arccoth(x.real_park());
  return res;
}

//
// 功能函数
//
void copy(Real& to, const Real& from) {
  to.real_park_ = from.real_park_;
}

//
// 友元重载运算符
//

// 双目算术运算符
Real operator+(const Real& num1, const Real& num2) {
  return add(num1, num2);
}

Real operator-(const Real& num1, const Real& num2) {
  return sub(num1, num2);
}

Real operator*(const Real& num1, const Real& num2) {
  return mul(num1, num2);
}

Real operator/(const Real& num1, const Real& num2) {
  return div(num1, num2);
}

Real operator%(const Real& num1, const Real& num2) {
  return mod(num1, num2);
}

Real operator+(const Real& num1, const char* num2) {
  return add(num1, Real(num2));
}

Real operator-(const Real& num1, const char* num2) {
  return sub(num1, Real(num2));
}

Real operator*(const Real& num1, const char* num2) {
  return mul(num1, Real(num2));
}

Real operator/(const Real& num1, const char* num2) {
  return div(num1, Real(num2));
}

Real operator%(const Real& num1, const char* num2) {
  return mod(num1, Real(num2));
}

Real operator+(const char* num1, const Real& num2) {
  return add(Real(num1), num2);
}

Real operator-(const char* num1, const Real& num2) {
  return sub(Real(num1), num2);
}

Real operator*(const char* num1, const Real& num2) {
  return mul(Real(num1), num2);
}

Real operator/(const char* num1, const Real& num2) {
  return div(Real(num1), num2);
}

Real operator%(const char* num1, const Real& num2) {
  return mod(Real(num1), num2);
}

// 关系运算符
bool operator==(const Real& num1, const Real& num2) {
  return num1.real_park_ == num2.real_park_;
}

bool operator!=(const Real& num1, const Real& num2) {
  return num1.real_park_ != num2.real_park_;
}

bool operator<(const Real& num1, const Real& num2) {
  return num1.real_park_ < num2.real_park_;
}

bool operator>(const Real& num1, const Real& num2) {
  return num1.real_park_ > num2.real_park_;
}

bool operator<=(const Real& num1, const Real& num2) {
  return num1.real_park_ <= num2.real_park_;
}

bool operator>=(const Real& num1, const Real& num2) {
  return num1.real_park_ >= num2.real_park_;
}

bool operator==(const Real& num1, const char* num2) {
  return num1.real_park_ == num2;
}

bool operator!=(const Real& num1, const char* num2) {
  return num1.real_park_ != num2;
}

bool operator<(const Real& num1, const char* num2) {
  return num1.real_park_ < num2;
}

bool operator>(const Real& num1, const char* num2) {
  return num1.real_park_ > num2;
}

bool operator<=(const Real& num1, const char* num2) {
  return num1.real_park_ <= num2;
}

bool operator>=(const Real& num1, const char* num2) {
  return num1.real_park_ >= num2;
}

bool operator==(const char* num1, const Real& num2) {
  return num1 == num2.real_park_;
}

bool operator!=(const char* num1, const Real& num2) {
  return num1 != num2.real_park_;
}

bool operator<(const char* num1, const Real& num2) {
  return num1 < num2.real_park_;
}

bool operator>(const char* num1, const Real& num2) {
  return num1 > num2.real_park_;
}

bool operator<=(const char* num1, const Real& num2) {
  return num1 <= num2.real_park_;
}

bool operator>=(const char* num1, const Real& num2) {
  return num1 >= num2.real_park_;
}

// 逻辑运算符
bool operator||(const Real& num1, const Real& num2) {
  return num1.real_park_ || num2.real_park_;
}

bool operator&&(const Real& num1, const Real& num2) {
  return num1.real_park_ && num2.real_park_;
}

bool operator!(const Real& num1) {
  return !num1.real_park_;
}

bool operator||(const Real& num1, const char* num2) {
  return num1.real_park_ || num2;
}

bool operator&&(const Real& num1, const char* num2) {
  return num1.real_park_ && num2;
}

bool operator||(const char* num1, const Real& num2) {
  return num1 || num2.real_park_;
}

bool operator&&(const char* num1, const Real& num2) {
  return num1 && num2.real_park_;
}

// 位运算符
Real operator~(const Real& num1) {
  Real res;
  res.real_park_ = ~num1.real_park_;
  return res;
}

Real operator|(const Real& num1, const Real& num2) {
  Real res;
  res.real_park_ = num1.real_park_ | num2.real_park_;
  return res;
}

Real operator&(const Real& num1, const Real& num2) {
  Real res;
  res.real_park_ = num1.real_park_ & num2.real_park_;
  return res;
}

Real operator^(const Real& num1, const Real& num2) {
  Real res;
  res.real_park_ = num1.real_park_ ^ num2.real_park_;
  return res;
}

Real operator<<(const Real& num1, const Real& bits) {
  Real res;
  res.real_park_ = num1.real_park_ << bits.real_park_;
  return res;
}

Real operator>>(const Real& num1, const Real& bits) {
  Real res;
  res.real_park_ = num1.real_park_ >> bits.real_park_;
  return res;
}

Real operator|(const Real& num1, const char* num2) {
  Real res;
  res.real_park_ = num1.real_park_ | num2;
  return res;
}

Real operator&(const Real& num1, const char* num2) {
  Real res;
  res.real_park_ = num1.real_park_ & num2;
  return res;
}

Real operator^(const Real& num1, const char* num2) {
  Real res;
  res.real_park_ = num1.real_park_ ^ num2;
  return res;
}

Real operator<<(const Real& num1, const char* bits) {
  Real res;
  res.real_park_ = num1.real_park_ << bits;
  return res;
}

Real operator>>(const Real& num1, const char* bits) {
  Real res;
  res.real_park_ = num1.real_park_ >> bits;
  return res;
}

Real operator|(const char* num1, const Real& num2) {
  Real res;
  res.real_park_ = num1 | num2.real_park_;
  return res;
}

Real operator&(const char* num1, const Real& num2) {
  Real res;
  res.real_park_ = num1 & num2.real_park_;
  return res;
}

Real operator^(const char* num1, const Real& num2) {
  Real res;
  res.real_park_ = num1 ^ num2.real_park_;
  return res;
}

Real operator<<(const char* num1, const Real& bits) {
  Real res;
  res.real_park_ = num1 << bits.real_park_;
  return res;
}

Real operator>>(const char* num1, const Real& bits) {
  Real res;
  res.real_park_ = num1 >> bits.real_park_;
  return res;
}

} // namespace number
} // namespace mynum