#include <mynum/float.h>
namespace mynum {

Float arccosh(const Float& x, const char* epsilon) {
  // x >= 1
  if (x < "1") {
    operand_value_is_invalid_exception(
      "x >= 1, x = %s", x.str().c_str()
    );
  }
  Float y = sub(pow(x, "2"), "1");
  return ln(add(x, sqrt(y)), epsilon);
}

} // namespace mynum