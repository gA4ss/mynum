#include <mynum/integer.h>

namespace mynum {

bool is_odd(const Integer& num1) {
  if (num1.integer_park().size() == 0) return false;
  unit_t x = *(num1.integer_park().begin());
  return (x%2 != 0);
}

} // namespace mynum