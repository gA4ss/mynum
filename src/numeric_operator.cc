#include <mynum/numeric.h>
#include <cstring>

namespace mynum {

Numeric& Numeric::operator+() {
  sign_ = kPositive;
  return *this;
}

Numeric& Numeric::operator-() {
  sign_ = kNegative;
  return *this;
}

char Numeric::operator[](uinteger_t i) {
  std::string res = str();
  if (i >= res.size()) out_of_range_exception("i = %d", i);
  return res[i];
}

bool operator==(const Numeric& num1, const Numeric& num2) {
  return equ(num1, num2);
}

bool operator!=(const Numeric& num1, const Numeric& num2) {
  return !equ(num1, num2);
}

bool operator<(const Numeric& num1, const Numeric& num2) {
  return lt(num1, num2);
}

bool operator>(const Numeric& num1, const Numeric& num2) {
  return gt(num1, num2);
}

bool operator<=(const Numeric& num1, const Numeric& num2) {
  return le(num1, num2);
}

bool operator>=(const Numeric& num1, const Numeric& num2) {
  return ge(num1, num2);
}

bool operator==(const Numeric& num1, const char* num2) {
  return equ(num1, Numeric(num2));
}

bool operator!=(const Numeric& num1, const char* num2) {
  return !equ(num1, Numeric(num2));
}

bool operator<(const Numeric& num1, const char* num2) {
  return lt(num1, Numeric(num2));
}

bool operator>(const Numeric& num1, const char* num2) {
  return gt(num1, Numeric(num2));
}

bool operator<=(const Numeric& num1, const char* num2) {
  return le(num1, Numeric(num2));
}

bool operator>=(const Numeric& num1, const char* num2) {
  return ge(num1, Numeric(num2));
}

bool operator==(const char* num1, const Numeric& num2) {
  return equ(Numeric(num1), num2);
}

bool operator!=(const char* num1, const Numeric& num2) {
  return !equ(Numeric(num1), num2);
}

bool operator<(const char* num1, const Numeric& num2) {
  return lt(Numeric(num1), num2);
}

bool operator>(const char* num1, const Numeric& num2) {
  return gt(Numeric(num1), num2);
}

bool operator<=(const char* num1, const Numeric& num2) {
  return le(Numeric(num1), num2);
}

bool operator>=(const char* num1, const Numeric& num2) {
  return ge(Numeric(num1), num2);
}

bool operator||(const Numeric& num1, const Numeric& num2) {
  if (is_nan(num1) || is_nan(num2)) return false;
  if (!is_zero(num1) || !is_zero(num2)) return true;
  return false;
}

bool operator&&(const Numeric& num1, const Numeric& num2) {
  if (is_nan(num1) || is_nan(num2)) return false;
  if (!is_zero(num1) && !is_zero(num2)) return true;
  return false;
}

bool operator||(const Numeric& num1, const char* num2) {
  Numeric num2_(num2);
  if (is_nan(num1) || is_nan(num2_)) return false;
  if (!is_zero(num1) || !is_zero(num2_)) return true;
  return false;
}

bool operator&&(const Numeric& num1, const char* num2) {
  Numeric num2_(num2);
  if (is_nan(num1) || is_nan(num2_)) return false;
  if (!is_zero(num1) && !is_zero(num2_)) return true;
  return false;
}

bool operator||(const char* num1, const Numeric& num2) {
  Numeric num1_(num1);
  if (is_nan(num1_) || is_nan(num2)) return false;
  if (!is_zero(num1_) || !is_zero(num2)) return true;
  return false;
}

bool operator&&(const char* num1, const Numeric& num2) {
  Numeric num1_(num1);
  if (is_nan(num1_) || is_nan(num2)) return false;
  if (!is_zero(num1_) && !is_zero(num2)) return true;
  return false;
}

bool operator!(const Numeric& num1) {
  if (is_nan(num1)) return false;
  return is_zero(num1);
}

} // namespace mynum