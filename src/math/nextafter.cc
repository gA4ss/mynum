/* Next representable value
 * Returns the next representable value after x in the direction of y.
 *
 * The similar function, nexttoward has the same behavior, but it takes a long double as second argument.
 */
#include <mynum/math.h>

namespace mynum {
namespace math {

Float nextafter(const Float& x, const Float& y) {
  operation_is_not_implement_exception("nextafter(%s, %s)", x.str().c_str(), y.str().c_str());
  return Float("nan");
}

Float nextafterf(const Float& x, const Float& y) {
  return nextafter(x, y);
}

Float nextafterl(const Float& x, const Float& y) {
  return nextafter(x, y);
}

} // namespace math
} // namespace mynum