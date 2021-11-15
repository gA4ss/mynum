#include <mynum/float.h>
namespace mynum {

Float arccsc(const Float& x, const char* epsilon) {
  if (abs(x) <= "1") {
    operand_value_is_invalid_exception(
      "|x| > 1, x = %s", x.str().c_str()
    );
  }
  return arcsin(div("1", x), epsilon);
}

} // namespace mynum