/* Compute remainder and quotient
 * Returns the same as remainder, but it additionally stores the quotient internally used to determine its result in the object pointed by quot.
 *
 * The value pointed by quot contains the congruent modulo with at least 3 bits of the integral quotient numer/denom.
 */

#include <mynum/math.h>

namespace mynum {
namespace math {

Float remquo(const Float& numer, const Float& denom, Integer* quot) {
  Float quo, rem;
  mynum::div2(numer, denom, quo, rem);
  if (quot) *quot = Integer(quo.integer_park());
  return rem;
}

Float remquof(const Float& numer, const Float& denom, Integer* quot) {
  return remquo(numer, denom, quot);
}

Float remquol(const Float& numer, const Float& denom, Integer* quot) {
  return remquo(numer, denom, quot);
}

} // namespace math
} // namespace mynum