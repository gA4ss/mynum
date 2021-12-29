/* Compute arc sine
 * Returns the principal value of the arc sine of x, expressed in radians.
 *
 * In trigonometrics, arc sine is the inverse operation of sine.
 */

#include <mynum/math.hpp>

namespace mynum {

Float asin(const Float& x) {
  return arcsin(x);
}

} // namespace mynum