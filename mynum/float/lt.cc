#include <mynum/float.h>

namespace mynum {

bool lt(const Float& num1, const Float& num2) {
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
  my_assert(
    num1.sign() == num2.sign(), "\'%d\' != \'%d\'", 
    num1.sign(), num2.sign()
  );

  //
  // 比较同号与数值
  //
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

} // namespace mynum