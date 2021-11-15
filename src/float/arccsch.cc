#include <mynum/float.h>
namespace mynum {

Float arccsch(const Float& x, const char* epsilon) {
  // x != 0
  if (is_zero(x)) {
    operand_value_is_invalid_exception(
      "x != 0, x = %s", x.str().c_str()
    );
  }

  Float y = sqrt(add(div("1", pow(x, "2")), "1"), epsilon);
  return ln(add(div("1", x), y), epsilon);
}

} // namespace mynum