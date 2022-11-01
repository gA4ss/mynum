/* Next representable value toward precise value
 * Returns the next representable value after x in the direction of y.
 *
 * This function behaves as nextafter, but with a potentially more precise y.
 */
#include <mynum/math.h>

namespace mynum {
namespace math {

Float nexttoward(const Float& x, const Float& y) {
  return nextafter(x, y);
}

Float nexttowardf(const Float& x, const Float& y) {
  return nexttoward(x, y);
}

Float nexttowardl(const Float& x, const Float& y) {
  return nexttoward(x, y);
}

} // namespace math
} // namespace mynum