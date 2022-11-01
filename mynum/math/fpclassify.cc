/* Classify floating-point value
 * Returns a value of type int that matches one of the classification macro constants, 
 * depending on the value of x:
 *
 * value        description
 * FP_INFINITE  Positive or negative infinity (overflow)
 * FP_NAN       Not-A-Number
 * FP_ZERO      Value of zero
 * FP_SUBNORMAL Sub-normal value (underflow)
 * FP_NORMAL    Normal value (none of the above)
 */
#include <mynum/math.h>

namespace mynum {
namespace math {

Integer fpclassify(const Float& x) {
  if (mynum::is_infinite(x)) return Integer(FP_INFINITE);
  else if (mynum::is_nan(x)) return Integer(static_cast<my::integer_t>(FP_NAN));
  else if (mynum::is_zero(x)) return Integer(FP_ZERO);
  else if (mynum::is_subnormal(x)) return Integer(FP_SUBNORMAL);
  return Integer(FP_NORMAL);
}

} // namespace math
} // namespace mynum