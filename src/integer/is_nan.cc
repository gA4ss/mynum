#include <mynum/integer.h>

namespace mynum {

bool is_nan(const Integer& num1) {
  if (num1.infinite()) return false;
  return (num1.integer_park().size() == 0);
}

} // namespace mynum