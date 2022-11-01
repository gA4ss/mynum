/* Compute arc sine
 * Returns the principal value of the arc sine of x, expressed in radians.
 *
 * In trigonometrics, arc sine is the inverse operation of sine.
 */

#include <mynum/math.h>

namespace mynum {
namespace math {

Float asin(const Float& x) {
  return mynum::arcsin(x);
}

} // namespace math
} // namespace mynum