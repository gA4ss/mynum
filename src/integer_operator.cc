#include <mynum/integer.h>
#include <cstring>

namespace mynum {

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
  return quo(num1, num2);
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
  return quo(num1, Integer(num2));
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
  return quo(Integer(num1), num2);
}

Integer operator%(const char* num1, const Integer& num2) {
  return mod(Integer(num1), num2);
}

bool operator==(const Integer& num1, const Integer& num2) {
  return equ(num1, num2);
}

bool operator!=(const Integer& num1, const Integer& num2) {
  return !equ(num1, num2);
}

bool operator<(const Integer& num1, const Integer& num2) {
  return lt(num1, num2);
}

bool operator>(const Integer& num1, const Integer& num2) {
  return gt(num1, num2);
}

bool operator<=(const Integer& num1, const Integer& num2) {
  return le(num1, num2);
}

bool operator>=(const Integer& num1, const Integer& num2) {
  return ge(num1, num2);
}

bool operator==(const Integer& num1, const char* num2) {
  return equ(num1, Integer(num2));
}

bool operator!=(const Integer& num1, const char* num2) {
  return !equ(num1, Integer(num2));
}

bool operator<(const Integer& num1, const char* num2) {
  return lt(num1, Integer(num2));
}

bool operator>(const Integer& num1, const char* num2) {
  return gt(num1, Integer(num2));
}

bool operator<=(const Integer& num1, const char* num2) {
  return le(num1, Integer(num2));
}

bool operator>=(const Integer& num1, const char* num2) {
  return ge(num1, Integer(num2));
}

bool operator==(const char* num1, const Integer& num2) {
  return equ(Integer(num1), num2);
}

bool operator!=(const char* num1, const Integer& num2) {
  return !equ(Integer(num1), num2);
}

bool operator<(const char* num1, const Integer& num2) {
  return lt(Integer(num1), num2);
}

bool operator>(const char* num1, const Integer& num2) {
  return gt(Integer(num1), num2);
}

bool operator<=(const char* num1, const Integer& num2) {
  return le(Integer(num1), num2);
}

bool operator>=(const char* num1, const Integer& num2) {
  return ge(Integer(num1), num2);
}

bool operator||(const Integer& num1, const Integer& num2) {
  if (is_nan(num1) || is_nan(num2)) return false;
  if (!is_zero(num1) || !is_zero(num2)) return true;
  return false;
}

bool operator&&(const Integer& num1, const Integer& num2) {
  if (is_nan(num1) || is_nan(num2)) return false;
  if (!is_zero(num1) && !is_zero(num2)) return true;
  return false;
}

bool operator||(const Integer& num1, const char* num2) {
  Integer num2_(num2);
  if (is_nan(num1) || is_nan(num2_)) return false;
  if (!is_zero(num1) || !is_zero(num2_)) return true;
  return false;
}

bool operator&&(const Integer& num1, const char* num2) {
  Integer num2_(num2);
  if (is_nan(num1) || is_nan(num2_)) return false;
  if (!is_zero(num1) && !is_zero(num2_)) return true;
  return false;
}

bool operator||(const char* num1, const Integer& num2) {
  Integer num1_(num1);
  if (is_nan(num1_) || is_nan(num2)) return false;
  if (!is_zero(num1_) || !is_zero(num2)) return true;
  return false;
}

bool operator&&(const char* num1, const Integer& num2) {
  Integer num1_(num1);
  if (is_nan(num1_) || is_nan(num2)) return false;
  if (!is_zero(num1_) && !is_zero(num2)) return true;
  return false;
}

bool operator!(const Integer& num1) {
  if (is_nan(num1)) return false;
  return is_zero(num1);
}

Integer operator~(const Integer& num1) {
  return not_bits(num1);
}

Integer operator|(const Integer& num1, const Integer& num2) {
  return or_bits(num1, num2);
}

Integer operator&(const Integer& num1, const Integer& num2) {
  return and_bits(num1, num2);
}

Integer operator^(const Integer& num1, const Integer& num2) {
  return xor_bits(num1, num2);
}

Integer operator<<(const Integer& num1, const Integer& bits) {
  return lshift_bits(num1, bits);
}

Integer operator>>(const Integer& num1, const Integer& bits) {
  return rshift_bits(num1, bits);
}

Integer operator|(const Integer& num1, const char* num2) {
  return or_bits(num1, Integer(num2));
}

Integer operator&(const Integer& num1, const char* num2) {
  return and_bits(num1, Integer(num2));
}

Integer operator^(const Integer& num1, const char* num2) {
  return xor_bits(num1, Integer(num2));
}

Integer operator<<(const Integer& num1, const char* bits) {
  return lshift_bits(num1, Integer(bits));
}

Integer operator>>(const Integer& num1, const char* bits) {
  return rshift_bits(num1, Integer(bits));
}

Integer operator|(const char* num1, const Integer& num2) {
  return or_bits(Integer(num1), num2);
}

Integer operator&(const char* num1, const Integer& num2) {
  return and_bits(Integer(num1), num2);
}

Integer operator^(const char* num1, const Integer& num2) {
  return xor_bits(Integer(num1), num2);
}

Integer operator<<(const char* num1, const Integer& bits) {
  return lshift_bits(Integer(num1), bits);
}

Integer operator>>(const char* num1, const Integer& bits) {
  return rshift_bits(Integer(num1), bits);
}

// ----------------------------------------------------------------------
Integer& Integer::operator+() {
  return *this;
}

Integer& Integer::operator-() {
  if (sign_ == kNegative) sign_ = kPositive;
  else sign_ = kNegative;
  return *this;
}

Integer& Integer::operator++() {
  *this = add(*this, Integer("1"));
  return *this;
}

Integer Integer::operator++(int) {
  Integer res;
  copy(res, *this);
  *this = add(*this, Integer("1"));
  return res;
}

Integer& Integer::operator--() {
  *this = sub(*this, Integer("1"));
  return *this;
}

Integer Integer::operator--(int) {
  Integer res;
  copy(res, *this);
  *this = sub(*this, Integer("1"));
  return res;
}

void Integer::operator=(const Integer& num2) {
  assign(num2);
}

void Integer::operator=(const char* num2) {
  assign(Integer(num2));
}

void Integer::operator+=(const Integer& num2) {
  *this = add(*this, num2);
}

void Integer::operator+=(const char* num2) {
  *this = add(*this, Integer(num2));
}

void Integer::operator-=(const Integer& num2) {
  *this = sub(*this, num2);
}

void Integer::operator-=(const char* num2) {
  *this = sub(*this, Integer(num2));
}

void Integer::operator*=(const Integer& num2) {
  *this = mul(*this, num2);
}

void Integer::operator*=(const char* num2) {
  *this = mul(*this, Integer(num2));
}

void Integer::operator/=(const Integer& num2) {
  *this = div(*this, num2);
}

void Integer::operator/=(const char* num2) {
  *this = div(*this, Integer(num2));
}

void Integer::operator%=(const Integer& num2) {
  *this = mod(*this, num2);
}

void Integer::operator%=(const char* num2) {
  *this = mod(*this, Integer(num2));
}

void Integer::operator&=(const Integer& num2) {
  *this = and_bits(*this, num2);
}

void Integer::operator&=(const char* num2) {
  *this = and_bits(*this, Integer(num2));
}

void Integer::operator|=(const Integer& num2) {
  *this = or_bits(*this, num2);
}

void Integer::operator|=(const char* num2) {
  *this = or_bits(*this, Integer(num2));
}

void Integer::operator^=(const Integer& num2) {
  *this = xor_bits(*this, num2);
}

void Integer::operator^=(const char* num2) {
  *this = xor_bits(*this, Integer(num2));
}

void Integer::operator<<=(const Integer& bits) {
  *this = lshift_bits(*this, bits);
}

void Integer::operator>>=(const Integer& bits) {
  *this = rshift_bits(*this, bits);
}

char Integer::operator[](uinteger_t i) {
  std::string res = str();
  if (i >= res.size()) out_of_range_exception("i = %d", i);
  return res[i];
}

} // namespace mynum