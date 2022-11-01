/* Compute hypotenuse
 * Returns the hypotenuse of a right-angled triangle whose legs are x and y.
 * 
 * The function returns what would be the square root of the sum of the squares 
 * of x and y (as per the Pythagorean theorem), but without incurring in undue 
 * overflow or underflow of intermediate values.
 */
#include <mynum/math.h>

namespace mynum {
namespace math {

Float hypot(const Float& x, const Float& y) {
  return add((x * x), (y * y));
}

Float hypotf(const Float& x, const Float& y) {
  return hypot(x, y);
}

Float hypotl(const Float& x, const Float& y) {
  return hypot(x, y);
}

} // namespace math
} // namespace mynum