/* Is normal
 * Returns whether x is a normal value: i.e., whether it is neither infinity, NaN, zero or subnormal.
 */
#include <mynum/math.h>

namespace mynum {
namespace math {

bool isnormal(const Float& x) {
  return (fpclassify(x) == FP_NORMAL);
}

} // namespace math
} // namespace mynum