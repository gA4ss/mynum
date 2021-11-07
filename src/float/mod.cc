#include <mynum/float.h>

namespace mynum {

Float mod(const Float& num1, const Float& num2) {
  Float res("0");
  if (num1 < num2) return num1;
  if (num1 == num2) return res;

  // division_result_t div_result = div(num1, num2);
  // bignum_t r = div_result.second;
  // if (is_zero(div_result.second)) return res;

  // bignum_t decimal_park = 

  return res;
}

} // namespace mynum