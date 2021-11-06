#include <mynum/integer.h>

namespace mynum {

Integer and_bits(const Integer& num1, const Integer& num2) {
  if (is_nan(num1) || is_nan(num2)) return Integer();
  if (is_infinite(num1) || is_infinite(num2)) 
    operand_value_is_invalid_exception("%s", "num1 or num2 is infinite");
  if (is_zero(num1) || is_zero(num2)) return Integer("0");

  Integer a = num1, b = num2;
  bignum_t integer_park_3, decimal_park_3;
  same_digits(a, b);
  bignum_t integer_park_1 = a.integer_park();
  bignum_t integer_park_2 = b.integer_park();
  size_t n = integer_park_1.size();
  for (size_t i = 0; i < n; i++)
    integer_park_3.push_front(integer_park_1[i] & integer_park_2[i]);

  Integer c;
  shrink_zero(integer_park_3, true);
  c.set_integer_park(integer_park_3);
  c.set_sign(num1.sign() * num2.sign());
  return c;
}

} // namespace mynum