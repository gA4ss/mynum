/* Is finite value
 * Returns whether x is a finite value.
 *
 * A finite value is any floating-point value that is neither infinite nor NaN (Not-A-Number).
 */
#include <mynum/math.h>

namespace mynum {
namespace math {

bool isfinite(const Float& x) {
  return static_cast<bool>(!mynum::is_infinite(x));
}

} // namespace math
} // namespace mynum