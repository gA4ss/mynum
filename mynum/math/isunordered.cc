/* Is unordered
 * Returns whether x or y are unordered values:
 *
 * If one or both arguments are NaN, the arguments are unordered and the function returns true. In no case the function raises a FE_INVALID exception.
 */
#include <mynum/math.h>

namespace mynum {
namespace math {

bool isunordered(const Float& x, const Float& y) {
  return (mynum::is_nan(x) || mynum::is_nan(y));
}

} // namespace math
} // namespace mynum