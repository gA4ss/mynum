#include <mynum/float.h>
#include <mynum/constant.h>

namespace mynum {

Float arccos(const Float& x, const char* epsilon) {
  //
  // 保证 |x| < 1
  //
  if (abs(x) >= "1") {
    operand_value_is_invalid_exception(
      "|x| < 1, x = %s", x.str().c_str()
    );
  }
  Float res = __half_pi - arcsin(x, epsilon);
  return res;
}

} // namespace mynum