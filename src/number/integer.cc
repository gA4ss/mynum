#include <mynum/number/integer.h>

namespace mynum {
namespace number {

bool equ(const Integer& num1, const Integer& num2) {
  return equ(num1.integer_park(), num2.integer_park());
}

bool gt(const Integer& num1, const Integer& num2) {
  return gt(num1.integer_park(), num2.integer_park());
}

bool lt(const Integer& num1, const Integer& num2) {
  return lt(num1.integer_park(), num2.integer_park());
}

bool ge(const Integer& num1, const Integer& num2) {
  return ge(num1.integer_park(), num2.integer_park());
}

bool le(const Integer& num1, const Integer& num2) {
  return le(num1.integer_park(), num2.integer_park());
}

bool is_zero(const Integer& num1) {
  return is_zero(num1.integer_park());
}

bool is_one(const Integer& num1) {
  return is_one(num1.integer_park());
}

bool is_nan(const Integer& num1) {
  return is_nan(num1.integer_park());
}

bool is_infinite(const Integer& num1) {
  return is_infinite(num1.integer_park());
}

bool is_none(const Integer& num1) {
  return is_none(num1.integer_park());
}

bool is_integer(const Integer& num1) {
  return is_integer(num1.integer_park());
}

bool is_float(const Integer& num1) {
  return is_float(num1.integer_park());
}

bool is_odd(const Integer& num1) {
  return is_odd(num1.integer_park());
}

bool is_even(const Integer& num1) {
  return is_even(num1.integer_park());
}

Integer add(const Integer& num1, const Integer& num2) {
  Integer res;
  res.real_park_ = add(num1.integer_park(), num2.integer_park());
  return res;
}

Integer sub(const Integer& num1, const Integer& num2) {
  Integer res;
  res.real_park_ = sub(num1.integer_park(), num2.integer_park());
  return res;
}
Integer mul(const Integer& num1, const Integer& num2) {
  Integer res;
  res.real_park_ = mul(num1.integer_park(), num2.integer_park());
  return res;
}

Integer div(const Integer& num1, const Integer& num2) {
  Integer res;
  res.real_park_ = div(num1.integer_park(), num2.integer_park());
  return res;
}

Integer quo(const Integer& num1, const Integer& num2) {
  Integer res;
  res.real_park_ = quo(num1.integer_park(), num2.integer_park());
  return res;
}

Integer rem(const Integer& num1, const Integer& num2) {
  Integer res;
  res.real_park_ = rem(num1.integer_park(), num2.integer_park());
  return res;
}

Integer mod(const Integer& num1, const Integer& num2) {
  Integer res;
  res.real_park_ = mod(num1.integer_park(), num2.integer_park());
  return res;
}

Integer or_bits(const Integer& num1, const Integer& num2) {
  Integer res;
  res.real_park_ = or_bits(num1.integer_park(), num2.integer_park());
  return res;
}

Integer and_bits(const Integer& num1, const Integer& num2) {
  Integer res;
  res.real_park_ = and_bits(num1.integer_park(), num2.integer_park());
  return res;
}

Integer xor_bits(const Integer& num1, const Integer& num2) {
  Integer res;
  res.real_park_ = xor_bits(num1.integer_park(), num2.integer_park());
  return res;
}

Integer not_bits(const Integer& num1) {
  Integer res;
  res.real_park_ = not_bits(num1.integer_park());
  return res;
}

Integer lshift_bits(const Integer& num1, const Integer& bits) {
  Integer res;
  res.real_park_ = lshift_bits(num1.integer_park(), bits.integer_park());
  return res;
}

Integer rshift_bits(const Integer& num1, const Integer& bits) {
  Integer res;
  res.real_park_ = rshift_bits(num1.integer_park(), bits.integer_park());
  return res;
}

Integer abs(const Integer& num1) {
  Integer res;
  res.real_park_ = abs(num1.integer_park());
  return res;
}

Integer floor(const Integer& num1) {
  Integer res;
  res.real_park_ = floor(num1.integer_park());
  return res;
}

Integer ceil(const Integer& num1) {
  Integer res;
  res.real_park_ = ceil(num1.integer_park());
  return res;
}

Integer round(const Integer& num1, uinteger_t precision) {
  Integer res;

  res.real_park_ = round(num1.integer_park(), precision);
  return res;
}

Integer pow(const Integer& num1, const Integer& exp) {
  Integer res;
  res.real_park_ = pow(num1.integer_park(), exp.integer_park());
  return res;
}

Integer rooting(const Integer& num1, const Integer& exp) {
  Integer res;
  res.real_park_ = rooting(num1.integer_park(), exp.integer_park());
  return res;
}

Integer log(const Integer& base, const Integer& n) {
  Integer res;
  res.real_park_ = log(base.integer_park(), n.integer_park());
  return res;
}

Integer log2(const Integer& log) {
  Integer res;
  res.real_park_ = log2(log.integer_park());
  return res;
}

Integer log10(const Integer& log) {
  Integer res;
  res.real_park_ = log10(log.integer_park());
  return res;
}

Integer ln(const Integer& log) {
  Integer res;
  res.real_park_ = ln(log.integer_park());
  return res;
}

Integer factorial(const Integer& num1) {
  Integer res;
  res.real_park_ = factorial(num1.integer_park());
  return res;
}

std::pair<Integer, Integer> extended_euclidean(const Integer& num1, const Integer& num2) {
  Integer res1, res2;
  std::pair<Numeric, Numeric> num = 
    extended_euclidean(num1.integer_park(), num2.integer_park());
  res1.real_park_ = num.first;
  res2.real_park_ = num.second;
  return {res1, res2};
}

Integer gcd(const Integer& num1, const Integer& num2) {
  Integer res;
  res.real_park_ = gcd(num1.integer_park(), num2.integer_park());
  return res;
}

Integer lcm(const Integer& num1, const Integer& num2) {
  Integer res;
  res.real_park_ = lcm(num1.integer_park(), num2.integer_park());
  return res;
}

//
// 友元重载运算符
//

// 双目算术运算符
Integer operator+(const Integer& num1, const Integer& num2) {
  return add(num1, num2);
}

Integer operator-(const Integer& num1, const Integer& num2) {
  return sub(num1, num2);
}

Integer operator*(const Integer& num1, const Integer& num2) {
  return mul(num1, num2);
}

Integer operator/(const Integer& num1, const Integer& num2) {
  return div(num1, num2);
}

Integer operator%(const Integer& num1, const Integer& num2) {
  return mod(num1, num2);
}

Integer operator+(const Integer& num1, const char* num2) {
  return add(num1, Integer(num2));
}

Integer operator-(const Integer& num1, const char* num2) {
  return sub(num1, Integer(num2));
}

Integer operator*(const Integer& num1, const char* num2) {
  return mul(num1, Integer(num2));
}

Integer operator/(const Integer& num1, const char* num2) {
  return div(num1, Integer(num2));
}

Integer operator%(const Integer& num1, const char* num2) {
  return mod(num1, Integer(num2));
}

Integer operator+(const char* num1, const Integer& num2) {
  return add(Integer(num1), num2);
}

Integer operator-(const char* num1, const Integer& num2) {
  return sub(Integer(num1), num2);
}

Integer operator*(const char* num1, const Integer& num2) {
  return mul(Integer(num1), num2);
}

Integer operator/(const char* num1, const Integer& num2) {
  return div(Integer(num1), num2);
}

Integer operator%(const char* num1, const Integer& num2) {
  return mod(Integer(num1), num2);
}

// 关系运算符
bool operator==(const Integer& num1, const Integer& num2) {
  return num1.integer_park() == num2.integer_park();
}

bool operator!=(const Integer& num1, const Integer& num2) {
  return num1.integer_park() != num2.integer_park();
}

bool operator<(const Integer& num1, const Integer& num2) {
  return num1.integer_park() < num2.integer_park();
}

bool operator>(const Integer& num1, const Integer& num2) {
  return num1.integer_park() > num2.integer_park();
}

bool operator<=(const Integer& num1, const Integer& num2) {
  return num1.integer_park() <= num2.integer_park();
}

bool operator>=(const Integer& num1, const Integer& num2) {
  return num1.integer_park() >= num2.integer_park();
}

bool operator==(const Integer& num1, const char* num2) {
  return num1.integer_park() == num2;
}

bool operator!=(const Integer& num1, const char* num2) {
  return num1.integer_park() != num2;
}

bool operator<(const Integer& num1, const char* num2) {
  return num1.integer_park() < num2;
}

bool operator>(const Integer& num1, const char* num2) {
  return num1.integer_park() > num2;
}

bool operator<=(const Integer& num1, const char* num2) {
  return num1.integer_park() <= num2;
}

bool operator>=(const Integer& num1, const char* num2) {
  return num1.integer_park() >= num2;
}

bool operator==(const char* num1, const Integer& num2) {
  return num1 == num2.integer_park();
}

bool operator!=(const char* num1, const Integer& num2) {
  return num1 != num2.integer_park();
}

bool operator<(const char* num1, const Integer& num2) {
  return num1 < num2.integer_park();
}

bool operator>(const char* num1, const Integer& num2) {
  return num1 > num2.integer_park();
}

bool operator<=(const char* num1, const Integer& num2) {
  return num1 <= num2.integer_park();
}

bool operator>=(const char* num1, const Integer& num2) {
  return num1 >= num2.integer_park();
}

// 逻辑运算符
bool operator||(const Integer& num1, const Integer& num2) {
  return num1.integer_park() || num2.integer_park();
}

bool operator&&(const Integer& num1, const Integer& num2) {
  return num1.integer_park() && num2.integer_park();
}

bool operator!(const Integer& num1) {
  return !num1.integer_park();
}

bool operator||(const Integer& num1, const char* num2) {
  return num1.integer_park() || num2;
}

bool operator&&(const Integer& num1, const char* num2) {
  return num1.integer_park() && num2;
}

bool operator||(const char* num1, const Integer& num2) {
  return num1 || num2.integer_park();
}

bool operator&&(const char* num1, const Integer& num2) {
  return num1 && num2.integer_park();
}

// 位运算符
Integer operator~(const Integer& num1) {
  Integer res;
  res.real_park_ = ~num1.integer_park();
  return res;
}

Integer operator|(const Integer& num1, const Integer& num2) {
  Integer res;
  res.real_park_ = num1.integer_park() | num2.integer_park();
  return res;
}

Integer operator&(const Integer& num1, const Integer& num2) {
  Integer res;
  res.real_park_ = num1.integer_park() & num2.integer_park();
  return res;
}

Integer operator^(const Integer& num1, const Integer& num2) {
  Integer res;
  res.real_park_ = num1.integer_park() ^ num2.integer_park();
  return res;
}

Integer operator<<(const Integer& num1, const Integer& bits) {
  Integer res;
  res.real_park_ = num1.integer_park() << bits.real_park_;
  return res;
}

Integer operator>>(const Integer& num1, const Integer& bits) {
  Integer res;
  res.real_park_ = num1.integer_park() >> bits.real_park_;
  return res;
}

Integer operator|(const Integer& num1, const char* num2) {
  Integer res;
  res.real_park_ = num1.integer_park() | num2;
  return res;
}

Integer operator&(const Integer& num1, const char* num2) {
  Integer res;
  res.real_park_ = num1.integer_park() & num2;
  return res;
}

Integer operator^(const Integer& num1, const char* num2) {
  Integer res;
  res.real_park_ = num1.integer_park() ^ num2;
  return res;
}

Integer operator<<(const Integer& num1, const char* bits) {
  Integer res;
  res.real_park_ = num1.integer_park() << bits;
  return res;
}

Integer operator>>(const Integer& num1, const char* bits) {
  Integer res;
  res.real_park_ = num1.integer_park() >> bits;
  return res;
}

Integer operator|(const char* num1, const Integer& num2) {
  Integer res;
  res.real_park_ = num1 | num2.integer_park();
  return res;
}

Integer operator&(const char* num1, const Integer& num2) {
  Integer res;
  res.real_park_ = num1 & num2.integer_park();
  return res;
}

Integer operator^(const char* num1, const Integer& num2) {
  Integer res;
  res.real_park_ = num1 ^ num2.integer_park();
  return res;
}

Integer operator<<(const char* num1, const Integer& bits) {
  Integer res;
  res.real_park_ = num1 << bits.real_park_;
  return res;
}

Integer operator>>(const char* num1, const Integer& bits) {
  Integer res;
  res.real_park_ = num1 >> bits.real_park_;
  return res;
}

} // namespace number
} // namespace mynum