#include <mynum/integer.h>

namespace mynum {

Integer quo(const Integer& num1, const Integer& num2) {
  Integer res;
  if (is_nan(num1) || is_nan(num2)) return res;
  if (is_zero(num2)) divisor_is_zero_exception("num2 = %s", num2.str().c_str());
  if (is_zero(num1)) { res.zero(); return res; }
  if (is_one(num2)) return num1;

  int inf = __div_infinite(num1, num2);
  res = __infinite_operation_result(inf);
  if (!is_none(res))
    return res;

  bignum_t integer_park_1 = num1.integer_park();
  bignum_t integer_park_2 = num2.integer_park();
  shrink_zero(integer_park_1, true); shrink_zero(integer_park_2, true);   // __div除法，前边不能存在0。

  //
  // 真正的运算
  //
  division_result_t div_result = div(integer_park_1, integer_park_2);
  bignum_t quotient = div_result.first;

  //
  // 如果是异号，并且没有整除的情况下，存在向下取整的问题。
  //
  int sign = kPositive;
  if (num1.sign() != num2.sign()) {
    sign = kNegative;
    if (!is_zero(div_result.second)) {
      bignum_t b = {1};
      quotient = add(quotient, b);
    }
  }

  shrink_zero(quotient, true);
  res.set_integer_park(quotient);
  res.set_sign(sign);
  return res;
}

} // namespace mynum