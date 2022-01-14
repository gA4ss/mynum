#include <mynum/float.h>
#include <mynum/float/__infinity.h>

namespace mynum {

/* 余数在数学中的定义是始终大于等于0的。
 * 这里的整除运算都是在取floor后进行运算。
 */
Float div(const Float& num1, const Float& num2, my::uinteger_t significant_digits) {
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
  if (integer_park.empty()) integer_park.push_back(0);
  if (decimal_park.empty()) decimal_park.push_back(0);

  size_t numerator_precision = decimal_park_1.size(),
         denominator_precision = decimal_park_2.size();
  
  //
  // 分子扩大，计算结果扩大，所以真实结果要缩小；
  // 分母扩大，计算结果缩小，所以真实结果要扩大。
  // 取分子与分母扩大位数之差。谁的精度大按谁的。
  //
  if (numerator_precision != denominator_precision) {
    size_t precision = 0, fill_zero = 0;
    if (numerator_precision > denominator_precision) {            // 结果缩小
      precision = numerator_precision - denominator_precision;
      //
      // 计算结果前边填充0，如果结果存在尾数则尾数不参与
      // 直接在整数部分进行修正。
      //
      if (precision > integer_park.size()) {
        fill_zero = precision - integer_park.size();
        while (fill_zero--) integer_park.push_back(0);
      }
      decimal_park.insert(decimal_park.end(), integer_park.begin(), integer_park.begin()+precision);
      integer_park.erase(integer_park.begin(), integer_park.begin()+precision);
      if (integer_park.empty()) integer_park.push_back(0);
    } else if (numerator_precision < denominator_precision) {     // 结果扩大
      precision = denominator_precision - numerator_precision;
      //
      // 计算结果后边填充0，这里直接在尾数部分进行操作。
      //
      if (precision > decimal_park.size()) {
        fill_zero = precision;
        while (fill_zero--) decimal_park.push_front(0);
      }
      precision = decimal_park.size() - precision;
      integer_park.insert(integer_park.begin(), decimal_park.begin()+precision, decimal_park.end());
      decimal_park.erase(decimal_park.begin()+precision, decimal_park.end());
      if (decimal_park.empty()) decimal_park.push_back(0);
    }
    shrink_zero(decimal_park, false); if (decimal_park.empty()) decimal_park.push_back(0);
    shrink_zero(integer_park, true); if (integer_park.empty()) integer_park.push_back(0);
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