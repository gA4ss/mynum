#include <mynum/integer.h>

namespace mynum {

bool is_zero(const Integer& num1) {
  if (is_infinite(num1)) return false;

  bignum_t integer_park = num1.integer_park();
  return is_zero(integer_park);
}

} // namespace mynum