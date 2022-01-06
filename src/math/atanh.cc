/* Compute area hyperbolic tangent
 * Returns the area hyperbolic tangent of x.
 *
 * The area hyperbolic tangent is the inverse operation of the hyperbolic tangent.
 * template <class T>
 */
#include <mynum/math.h>

namespace mynum {
namespace math {

Float atanh(const Float& x) {
  return mynum::arctanh(x);
}

Float atanhf(const Float& x) {
  return atanh(x);
}

Float atanhl(const Float& x) {
  return atanh(x);
}

} // namespace math
} // namespace mynum