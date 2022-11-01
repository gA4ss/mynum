#include <mynum/float.h>
namespace mynum {

Float arccoth(const Float& x, const char* epsilon) {
  // x > 1, x < -1
  if ((x >= "-1") && (x <= "1")) {
    operand_value_is_invalid_exception(
      "x > 1 or x < -1, x = %s", x.str().c_str()
    );
  }
  Float y = ln(div(add(x, "1"), sub(x, "1")), epsilon);
  return div(y, "2");
}

} // namespace mynum