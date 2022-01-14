#include <mynum/float.h>
#include <cstring>

namespace mynum {

Float operator+(const Float& num1, const Float& num2) {
  return add(num1, num2);
}

Float operator-(const Float& num1, const Float& num2) {
  return sub(num1, num2);
}

Float operator*(const Float& num1, const Float& num2) {
  return mul(num1, num2);
}

Float operator/(const Float& num1, const Float& num2) {
  return div(num1, num2);
}

Float operator%(const Float& num1, const Float& num2) {
  return mod(num1, num2);
}

Float operator+(const Float& num1, const char* num2) {
  return add(num1, num2);
}

Float operator-(const Float& num1, const char* num2) {
  return sub(num1, num2);
}

Float operator*(const Float& num1, const char* num2) {
  return mul(num1, num2);
}

Float operator/(const Float& num1, const char* num2) {
  return div(num1, num2);
}

Float operator%(const Float& num1, const char* num2) {
  return mod(num1, num2);
}

Float operator+(const char* num1, const Float& num2) {
  return add(num1, num2);
}

Float operator-(const char* num1, const Float& num2) {
  return sub(num1, num2);
}

Float operator*(const char* num1, const Float& num2) {
  return mul(num1, num2);
}

Float operator/(const char* num1, const Float& num2) {
  return div(num1, num2);
}

Float operator%(const char* num1, const Float& num2) {
  return mod(num1, num2);
}

Float operator+(const Float& num1, const my::float_t& num2) {
  return add(num1, num2);
}

Float operator-(const Float& num1, const my::float_t& num2) {
  return sub(num1, num2);
}

Float operator*(const Float& num1, const my::float_t& num2) {
  return mul(num1, num2);
}

Float operator/(const Float& num1, const my::float_t& num2) {
  return div(num1, num2);
}

Float operator%(const Float& num1, const my::float_t& num2) {
  return mod(num1, num2);
}

Float operator+(const my::float_t& num1, const Float& num2) {
  return add(num1, num2);
}

Float operator-(const my::float_t& num1, const Float& num2) {
  return sub(num1, num2);
}

Float operator*(const my::float_t& num1, const Float& num2) {
  return mul(num1, num2);
}

Float operator/(const my::float_t& num1, const Float& num2) {
  return div(num1, num2);
}

Float operator%(const my::float_t& num1, const Float& num2) {
  return mod(num1, num2);
}

bool operator==(const Float& num1, const Float& num2) {
  return equ(num1, num2);
}

bool operator!=(const Float& num1, const Float& num2) {
  return !equ(num1, num2);
}

bool operator<(const Float& num1, const Float& num2) {
  return lt(num1, num2);
}

bool operator>(const Float& num1, const Float& num2) {
  return gt(num1, num2);
}

bool operator<=(const Float& num1, const Float& num2) {
  return le(num1, num2);
}

bool operator>=(const Float& num1, const Float& num2) {
  return ge(num1, num2);
}

bool operator==(const Float& num1, const char* num2) {
  return equ(num1, num2);
}

bool operator!=(const Float& num1, const char* num2) {
  return !equ(num1, num2);
}

bool operator<(const Float& num1, const char* num2) {
  return lt(num1, num2);
}

bool operator>(const Float& num1, const char* num2) {
  return gt(num1, num2);
}

bool operator<=(const Float& num1, const char* num2) {
  return le(num1, num2);
}

bool operator>=(const Float& num1, const char* num2) {
  return ge(num1, num2);
}

bool operator==(const char* num1, const Float& num2) {
  return equ(num1, num2);
}

bool operator!=(const char* num1, const Float& num2) {
  return !equ(num1, num2);
}

bool operator<(const char* num1, const Float& num2) {
  return lt(num1, num2);
}

bool operator>(const char* num1, const Float& num2) {
  return gt(num1, num2);
}

bool operator<=(const char* num1, const Float& num2) {
  return le(num1, num2);
}

bool operator>=(const char* num1, const Float& num2) {
  return ge(num1, num2);
}

bool operator==(const Float& num1, const my::float_t& num2) {
  return equ(num1, num2);
}

bool operator!=(const Float& num1, const my::float_t& num2) {
  return !equ(num1, num2);
}

bool operator<(const Float& num1, const my::float_t& num2) {
  return lt(num1, num2);
}

bool operator>(const Float& num1, const my::float_t& num2) {
  return gt(num1, num2);
}

bool operator<=(const Float& num1, const my::float_t& num2) {
  return le(num1, num2);
}

bool operator>=(const Float& num1, const my::float_t& num2) {
  return ge(num1, num2);
}

bool operator==(const my::float_t& num1, const Float& num2) {
  return equ(num1, num2);
}

bool operator!=(const my::float_t& num1, const Float& num2) {
  return !equ(num1, num2);
}

bool operator<(const my::float_t& num1, const Float& num2) {
  return lt(num1, num2);
}

bool operator>(const my::float_t& num1, const Float& num2) {
  return gt(num1, num2);
}

bool operator<=(const my::float_t& num1, const Float& num2) {
  return le(num1, num2);
}

bool operator>=(const my::float_t& num1, const Float& num2) {
  return ge(num1, num2);
}

bool operator||(const Float& num1, const Float& num2) {
  if (is_nan(num1) || is_nan(num2)) return false;
  if (!is_zero(num1) || !is_zero(num2)) return true;
  return false;
}

bool operator&&(const Float& num1, const Float& num2) {
  if (is_nan(num1) || is_nan(num2)) return false;
  if (!is_zero(num1) && !is_zero(num2)) return true;
  return false;
}

bool operator||(const Float& num1, const char* num2) {
  Float num2_(num2);
  if (is_nan(num1) || is_nan(num2_)) return false;
  if (!is_zero(num1) || !is_zero(num2_)) return true;
  return false;
}

bool operator&&(const Float& num1, const char* num2) {
  Float num2_(num2);
  if (is_nan(num1) || is_nan(num2_)) return false;
  if (!is_zero(num1) && !is_zero(num2_)) return true;
  return false;
}

bool operator||(const char* num1, const Float& num2) {
  Float num1_(num1);
  if (is_nan(num1_) || is_nan(num2)) return false;
  if (!is_zero(num1_) || !is_zero(num2)) return true;
  return false;
}

bool operator&&(const char* num1, const Float& num2) {
  Float num1_(num1);
  if (is_nan(num1_) || is_nan(num2)) return false;
  if (!is_zero(num1_) && !is_zero(num2)) return true;
  return false;
}

bool operator||(const Float& num1, const my::float_t& num2) {
  Float num2_(num2);
  if (is_nan(num1) || is_nan(num2_)) return false;
  if (!is_zero(num1) || !is_zero(num2_)) return true;
  return false;
}

bool operator&&(const Float& num1, const my::float_t& num2) {
  Float num2_(num2);
  if (is_nan(num1) || is_nan(num2_)) return false;
  if (!is_zero(num1) && !is_zero(num2_)) return true;
  return false;
}

bool operator||(const my::float_t& num1, const Float& num2) {
  Float num1_(num1);
  if (is_nan(num1_) || is_nan(num2)) return false;
  if (!is_zero(num1_) || !is_zero(num2)) return true;
  return false;
}

bool operator&&(const my::float_t& num1, const Float& num2) {
  Float num1_(num1);
  if (is_nan(num1_) || is_nan(num2)) return false;
  if (!is_zero(num1_) && !is_zero(num2)) return true;
  return false;
}

bool operator!(const Float& num1) {
  if (is_nan(num1)) return false;
  return is_zero(num1);
}

std::ostream& operator << (std::ostream& out, const Float& num) {
  out << num.str();
  return out;
}

std::istream& operator >> (std::istream& in, Float& num) {
  std::string ss;
  in >> ss;
  num = Float(ss);
  return in;
}

// ----------------------------------------------------------------------
Float& Float::operator+() {
  return *this;
}

Float& Float::operator-() {
  if (sign_ == kNegative) sign_ = kPositive;
  else sign_ = kNegative;
  return *this;
}

Float& Float::operator++() {
  *this = add(*this, Float("1"));
  return *this;
}

Float Float::operator++(int) {
  Float res;
  copy(res, *this);
  *this = add(*this, Float("1"));
  return res;
}

Float& Float::operator--() {
  *this = sub(*this, Float("1"));
  return *this;
}

Float Float::operator--(int) {
  Float res;
  copy(res, *this);
  *this = sub(*this, Float("1"));
  return res;
}

void Float::operator=(const Float& num2) {
  assign(num2);
}

void Float::operator=(const char* num2) {
  assign(num2);
}

void Float::operator=(const my::float_t& num2) {
  assign(num2);
}

void Float::operator+=(const Float& num2) {
  *this = add(*this, num2);
}

void Float::operator+=(const char* num2) {
  *this = add(*this, num2);
}

void Float::operator+=(const my::float_t& num2) {
  *this = add(*this, num2);
}

void Float::operator-=(const Float& num2) {
  *this = sub(*this, num2);
}

void Float::operator-=(const char* num2) {
  *this = sub(*this, num2);
}

void Float::operator-=(const my::float_t& num2) {
  *this = sub(*this, num2);
}

void Float::operator*=(const Float& num2) {
  *this = mul(*this, num2);
}

void Float::operator*=(const char* num2) {
  *this = mul(*this, num2);
}

void Float::operator*=(const my::float_t& num2) {
  *this = mul(*this, num2);
}

void Float::operator/=(const Float& num2) {
  *this = div(*this, num2);
}

void Float::operator/=(const char* num2) {
  *this = div(*this, num2);
}

void Float::operator/=(const my::float_t& num2) {
  *this = div(*this, num2);
}

void Float::operator%=(const Float& num2) {
  *this = mod(*this, num2);
}

void Float::operator%=(const char* num2) {
  *this = mod(*this, num2);
}

void Float::operator%=(const my::float_t& num2) {
  *this = mod(*this, num2);
}

char Float::operator[](my::uinteger_t i) {
  std::string res = str();
  if (i >= res.size()) out_of_range_exception("i = %d", i);
  return res[i];
}

} // namespace mynum