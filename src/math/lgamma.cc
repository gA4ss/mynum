/* Compute log-gamma function
 * log-gamma functionReturns the natural logarithm of the absolute value of the gamma function of x.template <class T>
 */
#include <mynum/math.h>

namespace mynum {
namespace math {

Float lgamma(const Float& x) {
  return mynum::ln(mynum::gamma(x));
}

Float lgammaf(const Float& x) {
  return lgamma(x);
}

Float lgammal(const Float& x) {
  return lgamma(x);
}

} // namespace math
} // namespace mynum