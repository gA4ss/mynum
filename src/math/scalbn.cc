/* Scale significand using floating-point base exponent
 * Scales x by FLT_RADIX raised to the power of n, returning the same as:
 *
 * scalbn(x,n) = x * FLT_RADIX ^ n
 * 
 * Presumably, x and n are the components of a floating-point number in the system; In such a case, this function may be optimized to be more efficient than the theoretical operations to compute the value explicitly.
 * 
 * On most platforms, FLT_RADIX is 2, making this function equivalent to ldexp.
 */
#include <mynum/math.h>

namespace mynum {
namespace math {

Float scalbn(const Float& x, const Integer& n) {
  return scalbln(x, n);
}

Float scalbnf(const Float& x, const Integer& n) {
  return scalbln(x, n);
}

Float scalbnl(const Float& x, const Integer& n) {
  return scalbln(x, n);
}

} // namespace math
} // namespace mynum