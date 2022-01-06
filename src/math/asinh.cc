/* Compute area hyperbolic sine
 * Returns the area hyperbolic sine of x.
 *
 * The area hyperbolic sine is the inverse operation of the hyperbolic sine.
 */
#include <mynum/math.h>

namespace mynum {
namespace math {

Float asinh(const Float& x) {
  return mynum::arcsinh(x);
}

Float asinhf(const Float& x) {
  return asinh(x);
}

Float asinhl(const Float& x) {
  return asinh(x);
}

} // namespace math
} // namespace mynum