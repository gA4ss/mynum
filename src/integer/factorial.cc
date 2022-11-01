#include <mynum/integer.h>

namespace mynum {

Integer factorial(const Integer& num1) {
  if (num1.sign() == kNegative) operand_value_is_invalid_exception("%s", "num1 is negative");
  if (is_zero(num1) || is_one(num1)) return Integer("1");
  Integer a = num1, b = "1";
  while (a != "1") {
    b *= a;
    --a;
  }
  return b;
}

} // namespace mynum