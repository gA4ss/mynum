#include <mynum/integer.h>

namespace mynum {

bool is_even(const Integer& num1) {
  if (is_nan(num1)) return false;
  unit_t x = *(num1.integer_park().begin());
  return (x%2 == 0);
}

} // namespace mynum