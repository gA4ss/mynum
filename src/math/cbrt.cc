/* Compute cubic root
 * Returns the cubic root of x.
 */
#include <mynum/math.hpp>

namespace mynum {

Float cbrt(const Float& x) {
  return pow(x, Float("0.333333333333333333333333333333333333333"));
}

} // namespace mynum