#include <mynum/float.h>

namespace mynum {

Float abs(const Float& num1) {
  Float res(num1);
  res.set_sign(kPositive);
  return res;
}

} // namespace mynum