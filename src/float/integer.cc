#include <mynum/float.h>
namespace mynum {

Float integer(const Float& num1) {
  if (is_nan(num1)) return Float();
  if (is_infinite(num1)) operand_value_is_invalid_exception("%s", "num1 is infinite");

  Float res = num1;
  res.set_decimal_park_zero();
  return res;
}

} // namespace mynum