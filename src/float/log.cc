#include <mynum/float.h>

namespace mynum {

Float log(const Float& base, const Float& x, const char* epsilon) {
  // base > 0，base != 1，x > 0
  if ((base <= "0") || (is_one(base))) {
    operand_value_is_invalid_exception(
      "base > 0 and base != 1, base = %s", base.str().c_str()
    );
  }

  if (x <= "0") {
    operand_value_is_invalid_exception(
      "x > 0, x = %s", x.str().c_str()
    );
  }
  return ln(x, epsilon) / ln(base, epsilon);
}

} // namespace mynum