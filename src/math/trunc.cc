/* Truncate value
 * Rounds x toward zero, returning the nearest integral value that is not larger in magnitude than x.
 */
#include <mynum/math.h>

namespace mynum {
namespace math {

Float trunc(const Float& x) {
  return mynum::integer(x);
}

Float truncf(const Float& x) {
  return trunc(x);
}

Float truncl(const Float& x) {
  return trunc(x);
}

} // namespace math
} // namespace mynum