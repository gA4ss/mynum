#include <mynum/integer.h>

namespace mynum {

/* 将num1下取整后进行运算。 */
Integer rshift_bits(const Integer& num1, const Integer& bits) {
  if (is_nan(num1)) return Integer();
  if (is_nan(bits)) operand_value_is_invalid_exception("%s", "bits is nan");
  if (is_infinite(num1) || is_infinite(bits))
    operand_value_is_invalid_exception("%s", "num1 or bits is infinite");
  if (is_zero(num1)) return Integer("0");

  Integer res = num1, one("1"), two("2");
  Integer i("0");
  while(lt(i, bits)) {
    res = quo(res, two);
    i = add(i, one);
  }
  return res;
}

} // namespace mynum