/* Compute absolute value
 * Returns the absolute value of x: |x|.
 */
#include <mynum/math.h>

namespace mynum {
namespace math {

Float fabs(const Float& x) {
  return mynum::abs(x);
}

} // namespace math
} // namespace mynum