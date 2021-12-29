/* Copy sign
 * Returns a value with the magnitude of x and the sign of y.
 */
#include <mynum/math.hpp>

namespace mynum {

Float copysign(const Float& x, const Float& y) {
  Float z = x;
  z.set_sign(y.sign());
  return z;
}

} // namespace mynum