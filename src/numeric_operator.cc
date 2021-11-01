#include <mynum/numeric.h>
#include <cstring>

namespace mynum {

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

} // namespace mynum