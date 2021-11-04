#include <mynum/integer.h>

namespace mynum {

Integer not_bits(const Integer& num1) {
  if (is_nan(num1)) return Integer();
  if (is_infinite(num1)) operand_value_is_invalid_exception("%s", "num1 is infinite");
  if (is_zero(num1)) return Integer("1");
  if (is_one(abs(num1))) return Integer("0");

  Integer res = num1;
  bignum_t integer_park = res.integer_park();
  size_t n = integer_park.size();
  for (size_t i = 0; i < n; i++)
    integer_park[i] = ~integer_park[i];

  res.set_integer_park(integer_park);
  if (res.sign() == kPositive) res.set_sign(kNegative);
  else res.set_sign(kPositive);
  return res;
}

} // namespace mynum