/* Minimum value
 * Returns the smaller of its arguments: either x or y.
 * 
 * If one of the arguments in a NaN, the other is returned.
 */
#include <mynum/math.h>

namespace mynum {
namespace math {

Float fmin(const Float& x, const Float& y) {
  return (x < y) ? x : y;
}

Float fminf(const Float& x, const Float& y) {
  return fmin(x, y);
}

Float fminl(const Float& x, const Float& y) {
  return fmin(x, y);
}

} // namespace math
} // namespace mynum