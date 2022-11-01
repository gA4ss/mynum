/* Compute common logarithm
 * Returns the common (base-10) logarithm of x.
 */
#include <mynum/math.h>

namespace mynum {
namespace math {

Float log10(const Float& x) {
  return mynum::log(Float(10), x);
}

} // namespace math
} // namespace mynum