#include <mynum/integer.h>

namespace mynum {

bool is_one(const Integer& num1) {
  bignum_t x = string_to_bignum("1");
  return (cmp(num1.integer_park(), x) == 0) && (num1.sign() == kPositive);
}

} // namespace mynum