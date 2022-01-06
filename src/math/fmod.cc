/* Compute remainder of division
 * Returns the floating-point remainder of numer/denom (rounded towards zero):
 *
 * fmod = numer - tquot * denom
 *
 * Where tquot is the truncated (i.e., rounded towards zero) result of: numer/denom.
 *
 * A similar function, remainder, returns the same but with the quotient rounded to the nearest integer (instead of truncated).
 */
#include <mynum/math.h>

namespace mynum {
namespace math {

Float fmod(const Float& numer, const Float& denom) {
  return mynum::mod(numer, denom);
}

} // namespace math
} // namespace mynum