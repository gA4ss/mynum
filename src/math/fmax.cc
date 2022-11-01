/* Maximum value
 * Returns the larger of its arguments: either x or y.
 *
 * If one of the arguments in a NaN, the other is returned.
 */
#include <mynum/math.h>

namespace mynum {
namespace math {

Float fmax(const Float& x, const Float& y) {
  return (x > y) ? x : y;
}

Float fmaxf(const Float& x, const Float& y) {
  return fmax(x, y);
}

Float fmaxl(const Float& x, const Float& y) {
  return fmax(x, y);
}

} // namespace math
} // namespace mynum