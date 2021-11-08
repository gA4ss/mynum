#include <mynum/float.h>

namespace mynum {

Float sub(const Float& num1, const Float& num2) {
  Float res;
  if (is_nan(num1) || is_nan(num2)) return res;
  if (is_zero(num1)) { res = num2; res.set_sign(kNegative); return res; }
  if (is_zero(num2)) return num1;
  
  int inf = __sub_infinite(num1, num2);
  res = __infinite_operation_result(inf, 0);
  if (!is_none(res))
    return res;

  bignum_t decimal_park_1 = num1.decimal_park(), decimal_park_2 = num2.decimal_park();
  bignum_t decimal_park;
  bignum_t integer_park_1 = num1.integer_park(), integer_park_2 = num2.integer_park();
  bignum_t integer_park;
  int sign = kPositive;
  bool t = false;

  int cmp = __cmp(num1, num2);
  if ((num1.sign() == kPositive) && (num2.sign() == kPositive)) {
    // a - b
    if ((cmp == 1) || (cmp == 0)) {
      // a >= b
      decimal_park = sub2(decimal_park_1, decimal_park_2, &t);
      integer_park = sub(integer_park_1, integer_park_2, t);
      sign = kPositive;
    } else {
      // a < b
      decimal_park = sub2(decimal_park_2, decimal_park_1, &t);
      integer_park = sub(integer_park_2, integer_park_1, t);
      sign = kNegative;
    }
  } else if ((num1.sign() == kPositive) && (num2.sign() == kNegative)) {
    // a - (-b)
    decimal_park = add2(decimal_park_1, decimal_park_2, &t);
    integer_park = add(integer_park_1, integer_park_2, t);
    sign = kPositive;
  } else if ((num1.sign() == kNegative) && (num2.sign() == kPositive)) {
    // -a - b
    decimal_park = add2(decimal_park_1, decimal_park_2, &t);
    integer_park = add(integer_park_1, integer_park_2, t);
    sign = kNegative;
  } else if ((num1.sign() == kNegative) && (num2.sign() == kNegative)) {
    // -a - (-b)
    if (cmp == 1) {
      // a > b
      decimal_park = sub2(decimal_park_1, decimal_park_2, &t);
      integer_park = sub(integer_park_1, integer_park_2, t);
      sign = kNegative;
    } else { // cmp == -1 || cmp == 0
      // a <= b
      decimal_park = sub2(decimal_park_2, decimal_park_1, &t);
      integer_park = sub(integer_park_2, integer_park_1, t);
      sign = kPositive;
    }
  }/* end if */

  res.set_sign(sign);
  res.set_integer_park(integer_park);
  res.set_decimal_park(decimal_park);
  return res;
}

} // namespace mynum