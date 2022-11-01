/* Compute gamma function
 * gamma functionReturns the gamma function of x.
 */
#include <mynum/math.h>

namespace mynum {
namespace math {

Float tgamma(const Float& x) {
  return mynum::gamma(x);
}

Float tgammaf(const Float& x) {
  return tgamma(x);
}

Float tgammal(const Float& x) {
  return tgamma(x);
}

} // namespace math
} // namespace mynum