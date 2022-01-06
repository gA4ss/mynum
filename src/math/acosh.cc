/* Compute area hyperbolic cosine
 * Returns the nonnegative area hyperbolic cosine of x.
 *
 * The area hyperbolic cosine is the inverse operation of the hyperbolic cosine.
 */
#include <mynum/math.h>

namespace mynum {
namespace math {

Float acosh(const Float& x) {
  return arccosh(x);
}

Float acoshf(const Float& x) {
  return acosh(x);
}

Float acoshl(const Float& x) {
  return acosh(x);
}

} // namespace math
} // namespace mynum