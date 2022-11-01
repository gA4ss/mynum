#include <mynum/float.h>

namespace mynum {

bool is_one(const Float& num1) {
  bignum_t x = string_to_bignum("1");
  return (cmp(num1.integer_park(), x) == 0) &&
         (cmp(num1.decimal_park(), x) == 0) &&
         (num1.sign() == kPositive);
}

} // namespace mynum