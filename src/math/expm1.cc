/* Compute exponential minus one
 * Returns e raised to the power x minus one: ex-1.
 *
 * For small magnitude values of x, expm1 may be more accurate than exp(x)-1.
 */
#include <mynum/math.h>

namespace mynum {
namespace math {

Float expm1(const Float& x) {
  return mynum::sub(mynum::exp(x), Float("1"));
}

Float expm1f(const Float& x) {
  return expm1(x);
}

Float expm1l(const Float& x) {
  return expm1(x);
}

} // namespae math
} // namespace mynum