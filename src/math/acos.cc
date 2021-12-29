/* Compute arc cosine
 * Returns the principal value of the arc cosine of x, expressed in radians.
 *
 * In trigonometrics, arc cosine is the inverse operation of cosine.
 */
#include <mynum/math.hpp>

namespace mynum {

Float acos(const Float& x) {
  return arccos(x);
}

} // namespace mynum
