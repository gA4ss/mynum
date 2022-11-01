/* Sign bit
 * Returns whether the sign of x is negative.
 *
 * This can be also applied to infinites, NaNs and zeroes (if zero is unsigned, it is considered positive).
 */
#include <mynum/math.h>

namespace mynum {
namespace math {

Integer signbit(const Float& x) {
  return x.sign() == kPositive ? 1 : 0;
}

} // namespace math
} // namespace mynum