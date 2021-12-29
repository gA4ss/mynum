/* Compute area hyperbolic tangent
 * Returns the area hyperbolic tangent of x.
 *
 * The area hyperbolic tangent is the inverse operation of the hyperbolic tangent.
 * template <class T>
 */
#include <mynum/math.hpp>

namespace mynum {

Float atanh(const Float& x) {
  return arctanh(x);
}

Float atanhf(const Float& x) {
  return atanh(x);
}

Float atanhl(const Float& x) {
  return atanh(x);
}

} // namespace mynum