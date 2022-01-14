#include <mynum/float.h>

namespace mynum {

Float mod(const Float& num1, const Float& num2, my::uinteger_t significant_digits) {
  Float quo, rem;
  div2(num1, num2, quo, rem, significant_digits);
  return rem;
}

} // namespace mynum