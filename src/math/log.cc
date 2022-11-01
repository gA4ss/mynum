/* Compute natural logarithm
 * Returns the natural logarithm of x.
 *
 * The natural logarithm is the base-e logarithm: the inverse of the natural exponential function (exp). For common (base-10) logarithms, see log10.
 */
#include <mynum/math.h>

namespace mynum {
namespace math {

Float log(const Float& x) {
  return mynum::ln(x);
}

} // namespace math
} // namespace mynum