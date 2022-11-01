/* Copy sign
 * Returns a value with the magnitude of x and the sign of y.
 */
#include <mynum/math.h>

namespace mynum {
namespace math {

Float copysign(const Float& x, const Float& y) {
  Float z = x;
  z.set_sign(y.sign());
  return z;
}

} // namespace math
} // namespace mynum