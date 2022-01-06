/* Break into fractional and integral parts
 * Breaks x into an integral and a fractional part.
 *
 * The integer part is stored in the object pointed by intpart, and the fractional part is returned by the function.
 *
 * Both parts have the same sign as x.
 */
#include <mynum/math.h>

namespace mynum {
namespace math {

Float modf(const Float& x, Integer* intpart) {
  Float decimal = Float(x.decimal_park());
  if (!mynum::is_zero(decimal))
    decimal.set_sign(x.sign());

  if (intpart) {
    *intpart = Integer(x.integer_park());
    if (!mynum::is_zero(*intpart))
      (*intpart).set_sign(x.sign());
  }

  return decimal;
}

} // namespace math
} // namespace mynum