/* Generate quier NaN (long double)
 * Returns a quiet NaN (Not-A-Number) value of type long double.
 *
 * The NaN values are used to identify undefined or non-representable values for floating-point elements, such as the square root of negative numbers or the result of 0/0.
 *
 * The argument can be used by library implementations to distinguish different NaN values in a implementation-specific manner.
 *
 * Similarly, nan and nanf return NaN values of type double and float, respectively.
 */
#include <mynum/math.h>

namespace mynum {
namespace math {

Float nanl(const char* tagp) {
  return nan(tagp);
}

} // namespace math
} // namespace mynum