#include <mynum/float.h>

namespace mynum {

/* 提取整数与小数部分合成一个大数，然后两个大数相乘最后
 * 结果取两个大数精度相加。
 */
Float mul(const Float& num1, const Float& num2) {
  Float res;
  if (is_nan(num1) || is_nan(num2)) return res;
  if ((is_zero(num1) || is_zero(num2)) && (!is_infinite(num1) && !is_infinite(num2))) {
    res.zero();
    return res;
  }
  if (is_one(num1)) return num2;
  if (is_one(num2)) return num1;

  int inf = __mul_infinite(num1, num2);
  res = __infinite_operation_result(inf, 0);
  if (!is_none(res))
    return res;

  bignum_t integer_park_1 = num1.integer_park(), decimal_park_1 = num1.decimal_park();
  bignum_t integer_park_2 = num2.integer_park(), decimal_park_2 = num2.decimal_park();
  bignum_t bignum1, bignum2;

  bignum1.insert(bignum1.end(), decimal_park_1.begin(), decimal_park_1.end());
  bignum1.insert(bignum1.end(), integer_park_1.begin(), integer_park_1.end());
  bignum2.insert(bignum2.end(), decimal_park_2.begin(), decimal_park_2.end());
  bignum2.insert(bignum2.end(), integer_park_2.begin(), integer_park_2.end());
  bignum_t product = mul(bignum1, bignum2);
  shrink_zero(product, true);

  int sign = kPositive;
  if (num1.sign() == num2.sign()) sign = kPositive;
  else sign = kNegative;

  bignum_t integer_park, decimal_park;
  my::uinteger_t precision = num1.precision() + num2.precision(), fill_zero = 0;

  //
  // 扩大几倍缩小几倍
  //
  if (precision > product.size()) {
    fill_zero = precision - product.size();
    while (fill_zero--) product.push_back(0);
  }
  decimal_park.insert(decimal_park.end(), product.begin(), product.begin()+precision);
  integer_park.insert(integer_park.end(), product.begin()+precision, product.end());
  if (integer_park.empty()) integer_park.push_back(0);
  else if (integer_park.back() == 0) shrink_zero(integer_park, true);
  if (decimal_park.front() == 0) shrink_zero(decimal_park, false);
  if (decimal_park.empty()) decimal_park.push_front(0);

  res.set_integer_park(integer_park);
  res.set_decimal_park(decimal_park);
  res.set_sign(sign);

  return res;
}

} // namespace mynum