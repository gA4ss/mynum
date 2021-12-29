/* Compute binary exponential function
 * Returns the base-2 exponential function of x, which is 2 raised to the power x: 2x.
 */
#include <mynum/math.hpp>

namespace mynum {

Float exp2(const Float& x) {
  return pow(Float(2), x);
}

Float exp2f(const Float& x) {
  return exp2(x);
}

Float exp2l(const Float& x) {
  return exp2(x);
}

} // namespace mynum