/* Is Not-A-Number
 * Returns whether x is a NaN (Not-A-Number) value.
 *
 * The NaN values are used to identify undefined or non-representable values for floating-point elements, such as the square root of negative numbers or the result of 0/0.
 */
#include <mynum/math.h>

namespace mynum {
namespace math {

bool isnan(const Float& x) {
  return mynum::is_nan(x);
}

} // namespace math
} // namespace mynum