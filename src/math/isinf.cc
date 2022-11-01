/* Is infinity
 * Returns whether x is an infinity value (either positive infinity or negative infinity).template <class T>
 */
#include <mynum/math.h>

namespace mynum {
namespace math {

bool isinf(const Float& x) {
  return static_cast<bool>(mynum::is_infinite(x));
}

} // namespace math
} // namespace mynum