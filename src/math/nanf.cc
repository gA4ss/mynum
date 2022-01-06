/* Generate quiet NaN (float)
 * Returns a quiet NaN (Not-A-Number) value of type float.
 *
 * The NaN values are used to identify undefined or non-representable values for floating-point elements, such as the square root of negative numbers or the result of 0/0.
 * 
 * The argument can be used by library implementations to distinguish different NaN values in a implementation-specific manner.
 * Similarly, nan and nanl return NaN values of type double and long double, respectively.
 */
#include <mynum/math.h>

namespace mynum {
namespace math {

Float nanf(const char* tagp) {
  return nan(tagp);
}

} // namespace math
} // namespace mynum