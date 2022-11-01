/* Compute arc tangent with two parameters
 * Returns the principal value of the arc tangent of y/x, expressed in radians. 
 * 
 * To compute the value, the function takes into account the sign of both arguments in order to determine the quadrant.
 *
 * In C++, this function is overloaded in <valarray> (see valarray atan2).
 */
#include <mynum/math.h>

namespace mynum {
namespace math {

Float atan2(const Float& y, const Float& x) {
  return mynum::arctan(y / x);
}

} // namespace math
} // namespace mynum