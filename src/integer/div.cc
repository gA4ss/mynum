#include <mynum/integer.h>
#include <mynum/integer/__infinity.h>

namespace mynum {

/* 这里认定num1是数字而num2是无穷。 */
static Integer __mod_infinite_operation(const Integer& num1, const Integer& num2) {
  my_assert(is_infinite(num2), "%s", "num2 is not infinite.");

  Integer res;
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
std::pair<Integer, Integer> div(const Integer& num1, const Integer& num2) {
  Integer q, r;
  if (is_zero(num2)) divisor_is_zero_exception("num2 = %s", num2.str().c_str());
  if (is_nan(num1) || is_nan(num2)) {
    q = Integer("nan"); r = Integer("nan");
    return std::pair<Integer, Integer>(q, r);
  }
  if (is_zero(num1)) { 
    q = Integer("0"); r = Integer("0");
    return std::pair<Integer, Integer>(q, r);
  }
  if (is_one(abs(num2))) {
    q = num1;
    if (num2.sign() != num1.sign()) q.set_sign(kNegative);
    r = Integer("0");
    return std::pair<Integer, Integer>(q, r);
  }

  //
  // 处理与无穷的运算。
  //
  int div_inf = __div_infinite(num1, num2);
  int mod_inf = __mod_infinite(num1, num2);
  if ((div_inf != kOperandInfIndeterminacy) && (mod_inf != kOperandInfIndeterminacy)) {
    q = __infinite_operation_result(div_inf);
    r = __infinite_operation_result(mod_inf);
    return std::pair<Integer, Integer>(q, r);
  } else if ((div_inf == kOperandInfZero) && (mod_inf == kOperandInfIndeterminacy)) {
    //
    // 出现商为0的情况，只有a/inf。但是模并不确定。
    //
    q = __infinite_operation_result(div_inf);
    r = __mod_infinite_operation(num1, num2);
    return std::pair<Integer, Integer>(q, r);
  }

  my_assert((div_inf == kOperandInfIndeterminacy) && (mod_inf == kOperandInfIndeterminacy), \
            "%d != %d", div_inf, mod_inf);

  //
  // 这里是快速计算部分，将相等以及
  // 被除数小于除数的情况进行快速计算。
  //

  if (equ(abs(num1), abs(num2))) {
    if (num1.sign() == num2.sign()) q = "1";
    else q = "-1";
    r = "0";
    return std::pair<Integer, Integer>(q, r);
  } else if (lt(abs(num1), abs(num2))) {
    if (num1.sign() == num2.sign()) {
      q = "0";
      if (num1.sign() == kPositive) r = num1;
      else r = num1;
      return std::pair<Integer, Integer>(q, r);
    } else {
      q = "-1";
      r = sub(abs(num2), abs(num1));
      r.set_sign(num2.sign());
      return std::pair<Integer, Integer>(q, r);
    }
  }

  //
  // 这里必然 abs(num1) > abs(num2)
  //
  q = quo(num1, num2);
  r = sub(num1, mul(num2, q));
  return std::pair<Integer, Integer>(q, r);
}

} // namespace mynum