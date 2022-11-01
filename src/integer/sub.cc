#include <mynum/integer.h>

namespace mynum {

Integer sub(const Integer& num1, const Integer& num2) {
  Integer res;
  if (is_nan(num1) || is_nan(num2)) return res;
  if (is_zero(num1)) { res = num2; res.set_sign(kNegative); return res; }
  if (is_zero(num2)) return num1;
  
  int inf = __sub_infinite(num1, num2);
  res = __infinite_operation_result(inf);
  if (!is_none(res))
    return res;

  bignum_t integer_park_1 = num1.integer_park(), integer_park_2 = num2.integer_park();
  bignum_t integer_park;
  int sign = kPositive;
  bool t = false;

  int cmp_result = cmp(integer_park_1, integer_park_2);
  if ((num1.sign() == kPositive) && (num2.sign() == kPositive)) {
    // a - b
    if ((cmp_result == 1) || (cmp_result == 0)) {
      // a >= b
      integer_park = sub(integer_park_1, integer_park_2, t);
      sign = kPositive;
    } else {
      // a < b
      integer_park = sub(integer_park_2, integer_park_1, t);
      sign = kNegative;
    }
  } else if ((num1.sign() == kPositive) && (num2.sign() == kNegative)) {
    // a - (-b)
    integer_park = add(integer_park_1, integer_park_2, t);
    sign = kPositive;
  } else if ((num1.sign() == kNegative) && (num2.sign() == kPositive)) {
    // -a - b
    integer_park = add(integer_park_1, integer_park_2, t);
    sign = kNegative;
  } else if ((num1.sign() == kNegative) && (num2.sign() == kNegative)) {
    // -a - (-b)
    if (cmp_result == 1) {
      // a > b
      integer_park = sub(integer_park_1, integer_park_2, t);
      sign = kNegative;
    } else { // cmp_result == -1 || cmp_result == 0
      // a <= b
      integer_park = sub(integer_park_2, integer_park_1, t);
      sign = kPositive;
    }
  }/* end if */

  shrink_zero(integer_park, true);
  res.set_sign(sign);
  res.set_integer_park(integer_park);
  return res;
}

} // namespace mynum