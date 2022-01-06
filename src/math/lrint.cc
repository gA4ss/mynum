/* Round and cast to long integer
 * Rounds x to an integral value, using the rounding direction specified by fegetround, and returns it as a value of type long int.
 *
 * See llrint for an equivalent function that returns a long long int.
 */
#include <mynum/math.h>

namespace mynum {
namespace math {

Float lrint(const Float& x) {
  return llrint(x);
}

Float lrintf(const Float& x) {
  return lrint(x);
}

Float lrintl(const Float& x) {
  return lrint(x);
}

} // namespace math
} // namespace mynum