#include <mynum/float.h>

namespace mynum {

Float log10(const Float& x, const char* epsilon) {
  // x > 0
  if (x <= "0") {
    operand_value_is_invalid_exception(
      "x > 0, x = %s", x.str().c_str()
    );
  }
  return ln(x, epsilon) / ln("10", epsilon);
}

} // namespace mynum