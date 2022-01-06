/* Integer binary logarithm
 * Returns the integral part of the logarithm of |x|, using FLT_RADIX as base for the logarithm.
 *
 * This is the exponent used internally by the machine to express the floating-point value x, when it uses a significand between 1.0 and FLT_RADIX, so that, for a positive x:
 *
 * x = significand * FLT_RADIX ^ exponent
 *
 * Generally, FLT_RADIX is 2, and the value returned by this function is one less than the exponent obtained with frexp (because of the different significand normalization as [1.0,2.0) instead of [0.5,1.0)).
 */
template <class T>
T ilogb(const T& x) {
  T l;
  return l;
}

#include <mynum/math.h>

namespace mynum {
namespace math {

Integer ilogb(const Float& x) {
  return Integer();
}

Integer ilogbf(const Float& x) {
  return Integer();
}

Integer ilogbl(const Float& x) {
  return Integer();
}

} // namespace math
} // namespace mynum