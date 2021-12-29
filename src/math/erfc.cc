/* Compute complementary error function
 * complementary error functionReturns the complementary error function value for x.
 *
 * The complementary error function is equivalent to:
 * erfc(x) = 1-erf(x)
 */
#include <mynum/math.hpp>

namespace mynum {

Float erfc(const Float& x) {
  return 1 - erf(x);
}

} // namespace mynum
