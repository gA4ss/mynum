#include <mynum/integer.h>
#include <cstring>

namespace mynum {

bool equ(const Integer& num1, const Integer& num2) {
  if (is_nan(num1) || is_nan(num2)) return false;
  if (is_zero(num1) && is_zero(num2)) return true;

  int c = __cmp_infinite(num1, num2);
  if (c == 0) return true;
  if (c != -2) return false;

  my_assert(c == -2, "c = %d", c);
  c = __cmp(num1, num2);
  if (num1.sign() == num2.sign() && c == 0)
    return true;
  return false;
}

bool gt(const Integer& num1, const Integer& num2) {
  if (is_nan(num1) || is_nan(num2)) return false;
  if (is_zero(num1) && is_zero(num2)) return false;

  int c = __cmp_infinite(num1, num2);
  if (c == 1) return true;
  if (c != -2) return false;

  my_assert(c == -2, "c = %d", c);
  if (num1.sign() > num2.sign())
    return true;
  else if (num1.sign() < num2.sign())
    return false;

  //
  // 这里表示同号
  //
  my_assert(num1.sign() == num2.sign(), "\'%d\' != \'%d\'", num1.sign(), num2.sign());
  c = __cmp(num1, num2);
  if (c == 0) {
    return false;
  } else if (c == 1) {
    if (num1.sign() == kNegative)
      return false;
  } else if (c == -1) {
    if (num1.sign() == kPositive)
      return false;
  }
  return true;
}

bool lt(const Integer& num1, const Integer& num2) {
  if (is_nan(num1) || is_nan(num2)) return false;
  if (is_zero(num1) && is_zero(num2)) return false;

  int c = __cmp_infinite(num1, num2);
  if (c == -1) return true;
  if (c != -2) return false;

  my_assert(c == -2, "c = %d", c);
  if (num1.sign() > num2.sign())
    return false;
  else if (num1.sign() < num2.sign())
    return true;

  //
  // 这里表示同号
  //
  my_assert(num1.sign() == num2.sign(), "\'%d\' != \'%d\'", num1.sign(), num2.sign());
  c = __cmp(num1, num2);
  if (c == 0) {
    return false;
  } else if (c == 1) {
    if (num1.sign() == kNegative)
      return true;
  } else if (c == -1) {
    if (num1.sign() == kPositive)
      return true;
  }
  return false;
}

bool ge(const Integer& num1, const Integer& num2) {
  if (is_nan(num1) || is_nan(num2)) return false;
  return gt(num1, num2) || equ(num1, num2);
}

bool le(const Integer& num1, const Integer& num2) {
  if (is_nan(num1) || is_nan(num2)) return false;
  return lt(num1, num2) || equ(num1, num2);
}

} // namespace mynum