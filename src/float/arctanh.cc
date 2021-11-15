#include <mynum/float.h>
namespace mynum {

Float arctanh(const Float& x, const char* epsilon) {
  // -1 < x < 1
  if (abs(x) >= "1") {
    operand_value_is_invalid_exception(
      "|x| < 1, x = %s", x.str().c_str()
    );
  }
  Float y = ln(div(add("1", x), sub("1", x)), epsilon);
  return div(y, "2");
}

} // namespace mynum