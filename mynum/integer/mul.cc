#include <mynum/integer.h>

namespace mynum {

/* 提取整数与小数部分合成一个大数，然后两个大数相乘最后
 * 结果取两个大数精度相加。
 */
Integer mul(const Integer& num1, const Integer& num2) {
  Integer res;
  if (is_nan(num1) || is_nan(num2)) return res;
  if ((is_zero(num1) || is_zero(num2)) && (!is_infinite(num1) && !is_infinite(num2))) {
    res.zero();
    return res;
  }
  if (is_one(num1)) return num2;
  if (is_one(num2)) return num1;

  int inf = __mul_infinite(num1, num2);
  res = __infinite_operation_result(inf);
  if (!is_none(res))
    return res;

  bignum_t integer_park_1 = num1.integer_park();
  bignum_t integer_park_2 = num2.integer_park();
  bignum_t product = mul(integer_park_1, integer_park_2);
  shrink_zero(product, true);

  int sign = kPositive;
  if (num1.sign() != num2.sign()) sign = kNegative;

  res.set_integer_park(product);
  res.set_sign(sign);

  return res;
}

} // namespace mynum