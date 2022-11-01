#include <mynum/integer.h>

namespace mynum {

Integer abs(const Integer& num1) {
  Integer res(num1);
  res.set_sign(kPositive);
  return res;
}

} // namespace mynum