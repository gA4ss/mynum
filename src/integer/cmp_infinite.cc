#include <mynum/integer.h>

namespace mynum {

/* 对比无穷，考虑符号。
 * 返回值:
 * 1 : num1 > num2
 * 0 : num1 == num2
 * -1 : num1 < num2
 * -2 : num1 与 num2 关系不确定
 */
int cmp_infinite(const Numeric& num1, const Numeric& num2) {
  if (is_infinite(num1) && is_infinite(num2)) {
    if (num1.sign() == num2.sign()) return 0;
    else if (num1.sign() > num2.sign()) return 1;
    return -1;
  } else if (is_infinite(num1) && !is_infinite(num2)) {
    if (num1.sign() == kNegative) return -1;
    return 1;
  } else if (!is_infinite(num1) && is_infinite(num2)) {
    if (num2.sign() == kNegative) return 1;
    return -1;
  }
  return -2;
}

} // namespace mynum