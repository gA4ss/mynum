/* Compute absolute value
 * Returns the absolute value of x: |x|.
 *
 * These convenience abs overloads are exclusive of C++. In C, abs is only declared in <stdlib.h> (and operates on int values).
 *
 * Since C++11, additional overloads are provided in this header (<cmath>) for the integral types: These overloads effectively cast x to a double before calculations (defined for T being any integral type).
 */
#include <mynum/math.h>

namespace mynum {
namespace math {

Float abs(const Float& x) {
  return mynum::abs(x);
}

} // namespace math
} // namespace mynum