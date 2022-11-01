/* Compute binary exponential function
 * Returns the base-2 exponential function of x, which is 2 raised to the power x: 2x.
 */
#include <mynum/math.h>

namespace mynum {
namespace math {

Float exp2(const Float& x) {
  return mynum::pow(Float("2"), x);
}

Float exp2f(const Float& x) {
  return exp2(x);
}

Float exp2l(const Float& x) {
  return exp2(x);
}

} // namespace math
} // namespace mynum