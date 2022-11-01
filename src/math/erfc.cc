/* Compute complementary error function
 * complementary error functionReturns the complementary error function value for x.
 *
 * The complementary error function is equivalent to:
 * erfc(x) = 1-erf(x)
 */
#include <mynum/math.h>

namespace mynum {
namespace math {

Float erfc(const Float& x) {
  return mynum::erfc(x);
}

} // namespace math
} // namespace mynum
