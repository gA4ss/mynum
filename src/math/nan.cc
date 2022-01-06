/* Generate quiet NaN
 * Returns a quiet NaN (Not-A-Number) value of type double.
 *
 * The NaN values are used to identify undefined or non-representable values for floating-point elements, such as the square root of negative numbers or the result of 0/0.
 *
 * The argument can be used by library implementations to distinguish different NaN values in a implementation-specific manner.
 *
 * Similarly, nanf and nanl return NaN values of type float and long double, respectively.
 */
#include <mynum/math.h>

namespace mynum {
namespace math {

Float nan(const char* tagp) {
  return Float("nan");
}

} // namespace math
} // namespace mynum