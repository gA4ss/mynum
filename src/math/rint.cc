/* Round to integral value
 * Rounds x to an integral value, using the rounding direction specified by fegetround.
 *
 * This function may raise an FE_INEXACT exception if the value returned differs in value from x. See nearbyint for an equivalent function that cannot raise such exception.
 */
#include <mynum/math.h>

namespace mynum {
namespace math {

Float rint(const Float& x) {
  return llrint(x);
}

Float rintf(const Float& x) {
  return rint(x);
}

Float rintl(const Float& x) {
  return rint(x);
}

} // namespace math
} // namespace mynum