/* Round to nearest and cast to long long integer
 * Returns the integer value that is nearest in value to x, with halfway cases rounded away from zero.
 *
 * The rounded value is returned as a value of type long long int. See lround for an equivalent function that returns a long int instead.
 */
#include <mynum/math.h>

namespace mynum {
namespace math {

Integer llround(const Float& x) {
  return Integer(mynum::round(x).integer_park());
}

Integer llroundf(const Float& x) {
  return llround(x);
}

Integer llroundl(const Float& x) {
  return llround(x);
}

} // namespace math
} // namespace mynum