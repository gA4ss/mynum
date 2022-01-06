/* Is less or greater
 * Returns whether x is less than or greater than y.
 *
 * If one or both arguments are NaN, the function returns false, but no FE_INVALID exception is raised (note that the expression x<y||x>y may raise such an exception in this case).
 */
#include <mynum/math.h>

namespace mynum {
namespace math {

bool islessgreater(const Float& x, const Float& y) {
  return ((x < y) || (x > y));
}

} // namespace math
} // namespace mynum