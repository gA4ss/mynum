#include <mynum/float.h>
#include <mynum/float/__infinity.h>

namespace mynum {

/* 余数在数学中的定义是始终大于等于0的。
 * 这里的整除运算都是在取floor后进行运算。
 */
Float div(const Float& num1, const Float& num2, uinteger_t significant_digits) {
  Float res;
  if (is_nan(num1) || is_nan(num2)) return res;
  if (is_zero(num2)) divisor_is_zero_exception("num2 = %s", num2.str().c_str());
  if (is_zero(num1)) { res.zero(); return res; }
  if (is_one(num2)) return num1;

  int inf = __div_infinite(num1, num2);
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

  // __div除法，前边不能存在0。
  shrink_zero(bignum1, true); shrink_zero(bignum2, true);

  //
  // 真正的运算，这里将小数部分也当作整数运算。完后一并
  // 计算精度，多算一位四舍五入。
  //
  division_result_t div_result = div2(bignum1, bignum2, significant_digits+1);
  shrink_zero(div_result.first, true); shrink_zero(div_result.second, false);
  
  //
  // 分割整数部分与小数部分
  //
  bignum_t integer_park = div_result.first, decimal_park = div_result.second;


  size_t numerator_precision = decimal_park_1.size(),
         denominator_precision = decimal_park_2.size();
  
  //
  // 分子扩大，计算结果扩大，所以真实结果要缩小；
  // 分母扩大，计算结果缩小，所以真实结果要扩大。
  // 取分子与分母扩大位数之差。谁的精度大按谁的。
  //
  if (numerator_precision != denominator_precision) {
    size_t precision = 0, fill_zero = 0;
    bignum_t combine_park;
    combine_park.insert(combine_park.begin(), decimal_park.begin(), decimal_park.end());
    combine_park.insert(combine_park.end(), integer_park.begin(), integer_park.end());

    if (numerator_precision > denominator_precision) {            // 结果缩小
      precision = numerator_precision - denominator_precision;
      //
      // 计算结果前边填充0
      //
      if (precision > combine_park.size()) {
        fill_zero = precision - combine_park.size();
        while (fill_zero--) combine_park.push_back(0);
      }
      integer_park.clear(); decimal_park.clear();
      decimal_park.insert(decimal_park.begin(), combine_park.begin(), combine_park.begin()+precision);
      integer_park.insert(integer_park.begin(), combine_park.begin()+precision, combine_park.end());
    } else if (numerator_precision < denominator_precision) {     // 结果扩大
      precision = denominator_precision - numerator_precision;
      //
      // 计算结果后边填充0
      //
      if (precision > combine_park.size()) {
        fill_zero = precision;
        while (fill_zero--) combine_park.push_front(0);
      }
      integer_park.clear(); decimal_park.clear();
      decimal_park.insert(decimal_park.begin(), combine_park.begin(), combine_park.begin()+precision);
      integer_park.insert(integer_park.begin(), combine_park.begin()+precision, combine_park.end());
    }

    if (integer_park.empty()) integer_park.push_back(0);
    shrink_zero(decimal_park, false);   // 删除小数末尾的0
    shrink_zero(integer_park, true);    // 删除整数末尾的0
  }

  int sign = kPositive;
  if (num1.sign() == num2.sign()) sign = kPositive;
  else sign = kNegative;

  res.set_integer_park(integer_park);
  res.set_decimal_park(decimal_park);
  res.set_sign(sign);

  return round(res, significant_digits);
}

} // namespace mynum