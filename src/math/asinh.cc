/* Compute area hyperbolic sine
 * Returns the area hyperbolic sine of x.
 *
 * The area hyperbolic sine is the inverse operation of the hyperbolic sine.
 */
#include <mynum/math.hpp>

namespace mynum {

Float asinh(const Float& x) {
  return arcsinh(x);
}

Float asinhf(const Float& x) {
  return asinh(x);
}

Float asinhl(const Float& x) {
  return asinh(x);
}

} // namespace mynum