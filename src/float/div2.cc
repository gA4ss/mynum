#include <mynum/float.h>
#include <mynum/float/__infinity.h>

namespace mynum {

// /* 这里认定num1是数字而num2是无穷。 */
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

void div2(const Float& num1, const Float& num2, Float& quo, Float& rem, my::uinteger_t significant_digits) {  
  if (is_zero(num2)) divisor_is_zero_exception("num2 = %s", num2.str().c_str());
  if (is_nan(num1) || is_nan(num2)) {
    quo = Float("nan"); rem = Float("nan");
    return;
  }
  if (is_zero(num1)) { 
    quo = Float("0"); rem = Float("0"); 
    return;
  }
  if (is_one(abs(num2))) {
    quo = floor(num1);
    if (num2.sign() != num1.sign()) quo.set_sign(kNegative);
    rem = Float("0");
    return;
  }

  //
  // 处理与无穷的运算。
  //
  int div_inf = __div_infinite(num1, num2);
  int mod_inf = __mod_infinite(num1, num2);
  if ((div_inf != kOperandInfIndeterminacy) && (mod_inf != kOperandInfIndeterminacy)) {
    quo = __infinite_operation_result(div_inf, 0);
    rem = __infinite_operation_result(mod_inf, 0);
    return;
  } else if ((div_inf == kOperandInfZero) && (mod_inf == kOperandInfIndeterminacy)) {
    //
    // 出现商为0的情况，只有a/inf。但是模并不确定。
    //
    quo = __infinite_operation_result(div_inf, 0);
    rem = __mod_infinite_operation(num1, num2);
    return;
  }

  my_assert((div_inf == kOperandInfIndeterminacy) && (mod_inf == kOperandInfIndeterminacy), \
            "%d != %d", div_inf, mod_inf);

  //
  // 这里是快速计算部分，将相等以及
  // 被除数小于除数的情况进行快速计算。
  //

  if (equ(abs(num1), abs(num2))) {
    if (num1.sign() == num2.sign()) quo = Float("1");
    else quo = Float("-1");
    rem = Float("0");
    return;
  } else if (lt(abs(num1), abs(num2))) {
    if (num1.sign() == num2.sign()) {   // 同号
      quo = Float("0");
      rem = num1;
      return;
    } else {                            // 异号
      quo = Float("-1");
      rem = sub(abs(num2), abs(num1));
      rem.set_sign(num2.sign());
      return;
    }
  }

  //
  // 这里必然 abs(num1) > abs(num2)
  //
  quo = div(num1, num2, significant_digits);
  quo = floor(quo);
  rem = sub(num1, mul(num2, quo));
  return;
}

} // namespace mynum