/* Positive difference
 * Returns the positive difference between x and y.
 *
 * The function returns x-y if x>y, and zero otherwise.
 */
#include <mynum/math.h>

namespace mynum {
namespace math {

Float fdim(const Float& x, const Float& y) {
  return (x > y) ? (x - y) : Float("0");
}

Float fdimf (const Float& x, const Float& y) {
  return fdim(x, y);
}

Float fdiml (const Float& x, const Float& y) {
  return fdim(x, y);
}

} // namespace math
} // namespace mynum

