/* Round and cast to long long integer
 * Rounds x to an integral value, using the rounding direction specified by fegetround, and returns it as a value of type long long int.
 *
 * See lrint for an equivalent function that returns a long int.template <class T>
 */
#include <mynum/math.h>

namespace mynum {
namespace math {

Integer llrint(const Float& x) {
  Integer ret;
  int fe = fegetround();
  if (fe == FE_TONEAREST) {
    ret = Integer(mynum::round(x).integer_park());
  } else if (fe == FE_TOWARDZERO) {
    if (x.sign() == kNegative)
      ret = Integer(mynum::ceil(x).integer_park());
    else
      ret = Integer(mynum::floor(x).integer_park());
  } else if (fe == FE_UPWARD) {
    ret = Integer(mynum::ceil(x).integer_park());
  } else { // FE_DOWNWARD
    ret = Integer(mynum::floor(x).integer_park());
  }
  return ret;
}

Integer llrintf(const Float& x) {
  return llrint(x);
}

Integer llrintl(const Float& x) {
  return llrint(x);
}

} // namespace math
} // namespace mynum