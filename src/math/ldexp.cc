/* Generate value from significand and exponent
 * Returns the result of multiplying x (the significand) by 2 raised to the power of exp (the exponent).
 */
#include <mynum/math.h>

namespace mynum {
namespace math {

Float ldexp(const Float& x, const Integer& exp) {
  return mynum::mul(x, mynum::pow(Float("2"), Float(exp)));
}

} // namespace math
} // namespace mynum