#include <mynum/float.h>
#include <mynum/float/__infinity.h>

namespace mynum {

/* 这里认定num1是数字而num2是无穷。 */
static Float __mod_infinite_operation(const Float& num1, const Float& num2) {
  my_assert(is_infinite(num2), "%s", "num2 is not infinite.");

  Float res;
  if (is_zero(num1)) {
    res.zero();
  } else if (!is_infinite(num1)) {
    if (num1.sign() == num2.sign()) {
      res = num1;
    } else {
      res = num2;
    }
  }
  return res;
}

/* 余数在数学中的定义是始终大于等于0的。
 * 这里的整除运算都是在取floor后进行运算。
 */
Float div(const Float& num1, const Float& num2) {
  Float res;
  if (is_nan(num1) || is_nan(num2)) return res;
  if (is_zero(num2)) divisor_is_zero_exception("num2 = %s", num2.str().c_str());
  if (is_zero(num1)) { res.zero(); return res; }
  if (is_one(num2)) return num1;

  int inf = __div_infinite(num1, num2);
  res = __infinite_operation_result(inf);
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
  __shrink_zero(bignum1, true); __shrink_zero(bignum2, true);

  //
  // 真正的运算，这里将小数部分也当作整数运算。完后一并
  // 计算精度。
  //
  uinteger_t multiple = 0;
  bignum_t quotient = __div(bignum1, bignum2, Float::config_.max_quotient_borrow, &multiple);
  
  //
  // 分割整数部分与小数部分
  //
  bignum_t integer_park, decimal_park;
  uinteger_t precision = 0, fill_zero = 0;
  if (num1.precision() > num2.precision()) {
    precision = num1.precision() - num2.precision() + multiple;
    if (precision > quotient.size()) {
      fill_zero = precision - quotient.size();
      while (fill_zero--) quotient.push_back(0);
    }
    decimal_park.insert(decimal_park.end(), quotient.begin(), quotient.begin()+precision);
    integer_park.insert(integer_park.end(), quotient.begin()+precision, quotient.end());
  } else if (num1.precision() < num2.precision()) {
    precision = multiple;
    fill_zero = num2.precision() - num1.precision();
    while (fill_zero--) quotient.push_front(0);
    decimal_park.insert(decimal_park.end(), quotient.begin(), quotient.begin()+precision);
    integer_park.insert(integer_park.end(), quotient.begin()+precision, quotient.end());
  } else {
    precision = multiple;
    decimal_park.insert(decimal_park.end(), quotient.begin(), quotient.begin()+precision);
    integer_park.insert(integer_park.end(), quotient.begin()+precision, quotient.end());
  }
  if (integer_park.empty()) integer_park.push_back(0);  // 保证整数部分最少是0
  __shrink_zero(decimal_park, false); // 删除小数末尾的0
  __shrink_zero(integer_park, true); // 删除整数末尾的0

  int sign = kPositive;
  if (num1.sign() == num2.sign()) sign = kPositive;
  else sign = kNegative;

  res.__set_integer_park(integer_park);
  res.__set_decimal_park(decimal_park);
  res.__set_sign(sign);

  // return round(res, Float::config_.precision);
  return res;
}

} // namespace mynum