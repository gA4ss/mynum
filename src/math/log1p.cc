/* Compute logarithm plus one
 * Returns the natural logarithm of one plus x.
 *
 * For small magnitude values of x, logp1 may be more accurate than log(1+x).
 */
#include <mynum/math.h>

namespace mynum {
namespace math {

Float log1p(const Float& x) {
  return mynum::ln(x+1);
}

Float log1pf(const Float& x) {
  return log1p(x);
}

Float log1pl(const Float& x) {
  return log1p(x);
}

} // namespace math
} // namespace mynum