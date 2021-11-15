#include <mynum/float.h>

namespace mynum {

Float pow(const Float& a, const Float& x, const char* epsilon) {
  if (is_one(a)) return Float("1");
  if (is_nan(a)) return Float();
  if (is_infinite(a)) operand_value_is_invalid_exception("%s", "num1 is infinite");
  if (is_zero(x)) return Float("1");
  if (is_float(x)) {
    // 只有在x为整数是，a才可以小于0。
    if (a < "0") {
      operand_value_is_invalid_exception(
        "a > 0 in x is float, a = %s", a.str().c_str()
      );
    }
  }

  Float res;
  if (is_integer(x)) {
    res = "1";
    Float i = "0";
    while (i < x) {
      res *= a;
      ++i;
    }
  } else {
    Float lna = ln(a, epsilon);
    res = exp(mul(x, lna));
  }
  return res;
}

} // namespace mynum