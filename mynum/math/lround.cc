/* Round to nearest and cast to long integer
 * Returns the integer value that is nearest in value to x, with halfway cases rounded away from zero.
 *
 * The rounded value is returned as a value of type long int. See llround for an equivalent function that returns a long long int instead.
 */
#include <mynum/math.h>

namespace mynum {
namespace math {

Integer lround(const Float& x) {
  return llround(x);
}

Integer lroundf(const Float& x) {
  return lround(x);
}

Integer lroundl(const Float& x) {
  return lround(x);
}

} // namespace math
} // namespace mynum