#include <mynum/integer.h>

namespace mynum {

Integer pow(const Integer& num1, const Integer& exp) {
  if (is_nan(num1)) return Integer();
  if (is_infinite(num1)) operand_value_is_invalid_exception("%s", "num1 is infinite");
  if (is_zero(exp)) return Integer("1");

  Integer res = "1", i = "0";
  while (i < exp) {
    res *= num1;
    ++i;
  }
  return res;
}

} // namespace mynum