#include <mynum/float.h>

namespace mynum {

Float pow(const Float& num1, const Float& exp) {
  if (is_nan(num1)) return Float();
  if (is_infinite(num1)) operand_value_is_invalid_exception("%s", "num1 is infinite");

  Float res = "1", i = "0";
  while (i < exp) {
    res *= num1;
    ++i;
  }
  return res;
}

} // namespace mynum