/* Compute cubic root
 * Returns the cubic root of x.
 */
#include <mynum/math.h>

namespace mynum {
namespace math {

Float cbrt(const Float& x) {
  return mynum::pow(x, Float("0.333333333333333333333333333333333333333"));
}

} // namespace math
} // namespace mynum