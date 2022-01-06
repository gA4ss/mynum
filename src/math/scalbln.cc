/* Scale significand using floating-point base exponent (long)
 * Scales x by FLT_RADIX raised to the power of n, returning the result of computing:
 *
 * scalbn(x,n) = x * FLT_RADIX ^ n
 *
 * Presumably, x and n are the components of a floating-point number in the system; In such a case, this function may be optimized to be more efficient than the theoretical operations to compute the value explicitly.
 *
 * There also exists another version of this function: scalbn, which is identical, except that it takes an int as second argument.
 */
#include <mynum/math.h>

namespace mynum {
namespace math {

Float scalbln(const Float& x, const Integer& n) {
  return x * mynum::pow(Float(FLT_RADIX), n);
}

Float scalblnf(const Float& x, const Integer& n) {
  return scalbln(x, n);
}

Float scalblnl(const Float& x, const Integer& n) {
  return scalbln(x, n);
}

} // namespace math
} // namespace mynum