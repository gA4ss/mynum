#include <mynum/float.h>
#include <mynum/constant.h>

namespace mynum {

Float arccot(const Float& x, const char* epsilon) {
  Float at = arctan(x, epsilon);
  Float res = __half_pi - at;
  return res;
}

} // namespace mynum