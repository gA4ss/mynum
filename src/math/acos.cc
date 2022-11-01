/* Compute arc cosine
 * Returns the principal value of the arc cosine of x, expressed in radians.
 *
 * In trigonometrics, arc cosine is the inverse operation of cosine.
 */
#include <mynum/math.h>

namespace mynum {
namespace math {

Float acos(const Float& x) {
  return mynum::arccos(x);
}

} // namespace math
} // namespace mynum
