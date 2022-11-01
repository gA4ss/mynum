/* Compute arc tangent
 * Returns the principal value of the arc tangent of x, expressed in radians.
 *
 * In trigonometrics, arc tangent is the inverse operation of tangent.
 *
 * Notice that because of the sign ambiguity, the function cannot determine with certainty in which quadrant the angle falls only by its tangent value. See atan2 for an alternative that takes a fractional argument instead.
 */
#include <mynum/math.h>

namespace mynum {
namespace math {

Float atan(const Float& x) {
  return mynum::arctan(x);
}

} // namespace math
} // namespace mynum