/* Compute floating-point base logarithm
 * Returns the logarithm of |x|, using FLT_RADIX as base for the logarithm.
 *
 * On most platforms, FLT_RADIX is 2, and thus this function is equivalent to log2 for positive values.
 */
#include <mynum/math.h>

namespace mynum {
namespace math {

Float logb(const Float& x) {
  return log(Float(FLT_RADIX), x);
}

Float logbf(const Float& x) {
  return logb(x);
}

Float logbl(const Float& x) {
  return logb(x);
}

} // namespace math
} // namespace mynum