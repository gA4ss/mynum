#include <mynum/float.h>

namespace mynum {

bool is_zero(const Float& num1) {
  if (is_infinite(num1)) return false;
  return is_zero(num1.integer_park()) && is_zero(num1.decimal_park());
}

} // namespace mynum