/* Round to nearby integral value
 * Rounds x to an integral value, using the rounding direction specified by fegetround.
 *
 * This function does not raise FE_INEXACT exceptions. See rint for an equivalent function that may do.
 */
#include <mynum/math.h>

namespace mynum {
namespace math {

Float nearbyint(const Float& x) {
  return mynum::round(x, 0);
}

Float nearbyintf(const Float& x) {
  return nearbyint(x);
}

Float nearbyintl(const Float& x) {
  return nearbyint(x);
}

} // namespace math
} // namespace mynum