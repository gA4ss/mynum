#include <mynum/integer.h>

namespace mynum {

bool le(const Integer& num1, const Integer& num2) {
  if (is_nan(num1) || is_nan(num2)) return false;
  return lt(num1, num2) || equ(num1, num2);
}

} // namespace mynum