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
  c = cmp(num1.integer_park(), num2.integer_park());
  if (num1.sign() == num2.sign() && c == 0)
    return true;
  return false;
}

} // namespace mynum