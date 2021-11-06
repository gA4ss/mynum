#include <mynum/float.h>

namespace mynum {

bool ge(const Float& num1, const Float& num2) {
  if (is_nan(num1) || is_nan(num2)) return false;
  return gt(num1, num2) || equ(num1, num2);
}

} // namespace mynum