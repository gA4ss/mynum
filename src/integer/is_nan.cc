#include <mynum/integer.h>

namespace mynum {

bool is_nan(const Integer& num1) {
  if (num1.infinite()) return false;
  return is_nan(num1.integer_park());
}

} // namespace mynum