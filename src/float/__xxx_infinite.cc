#include <mynum/float.h>
#include <mynum/float/__infinity.h>

namespace mynum {

/* 对比无穷，考虑符号。
 * 返回值:
 * 1 : num1 > num2
 * 0 : num1 == num2
 * -1 : num1 < num2
 * -2 : num1 与 num2 关系不确定
 */
int __cmp_infinite(const Float& num1, const Float& num2) {
  if (is_infinite(num1) && is_infinite(num2)) {
    if (num1.sign() == num2.sign()) return 0;
    else if (num1.sign() > num2.sign()) return 1;
    return -1;
  } else if (is_infinite(num1) && !is_infinite(num2)) {
    if (num1.sign() == kNegative) return -1;
    return 1;
  } else if (!is_infinite(num1) && is_infinite(num2)) {
    if (num2.sign() == kNegative) return 1;
    return -1;
  }
  return -2;
}

int __add_infinite(const Float& num1, const Float& num2) {
  int res = kOperandInfIndeterminacy;
  if (is_infinite(num1) && !is_infinite(num2)) {
    res = num1.sign();
  } else if (!is_infinite(num1) && is_infinite(num2)) {
    res = num2.sign();
  } else if (is_infinite(num1) && is_infinite(num2)) {
    if (num1.sign() == num2.sign()) {
      res = num1.sign();
    } else {
      res = kOperandInfNan;   // 正负无穷相加 = NAN
    }
  } else {  // !is_infinite(num1) && !is_infinite(num2)
    res = kOperandInfIndeterminacy;
  }
  return res;
}

int __sub_infinite(const Float& num1, const Float& num2) {
  int res = kOperandInfIndeterminacy;
  int num2_sign = num2.sign() == kPositive ? kNegative : kPositive;
  if (is_infinite(num1) && !is_infinite(num2)) {
    res = num1.sign();
  } else if (!is_infinite(num1) && is_infinite(num2)) {
    res = num2_sign;
  } else if (is_infinite(num1) && is_infinite(num2)) {
    if (num1.sign() == num2_sign) {
      res = num1.sign();
    } else {
      res = kOperandInfNan;   // 正负无穷相减 = NAN
    }
  } else { // (!is_infinite(num1) && !is_infinite(num2))
    res = kOperandInfIndeterminacy;
  }
  return res;
}

int __mul_infinite(const Float& num1, const Float& num2) {
  int sign = num1.sign() * num2.sign();
  int res = kOperandInfIndeterminacy;
  if (is_zero(num1) && is_infinite(num2)) {
    res = kOperandInfNan;     // 0与正负无穷相乘法 = NAN
  } else if (is_infinite(num1) && is_zero(num2)) {
    res = kOperandInfNan;     // 0与正负无穷相乘法 = NAN
  } else if (is_infinite(num1) && !is_infinite(num2)) {
    res = sign;
  } else if (!is_infinite(num1) && is_infinite(num2)) {
    res = sign;
  } else if (is_infinite(num1) && is_infinite(num2)) {
    res = sign;
  } else { // !is_infinite(num1) && !is_infinite(num2)
    res = kOperandInfIndeterminacy;
  }
  return res;
}

/* 这里保证除数不为0 */
int __div_infinite(const Float& num1, const Float& num2) {
  int sign = num1.sign() * num2.sign();
  int res = kOperandInfIndeterminacy;
  if (is_zero(num2)) {
    divisor_is_zero_exception("num2 = %s", num2.str().c_str());
  } else if (is_zero(num1)) {
    res = kOperandInfZero;
  } else if (is_infinite(num1) && !is_infinite(num2)) {
    res = sign;
  } else if (!is_infinite(num1) && is_infinite(num2)) {
    res = kOperandInfZero;
  } else if (is_infinite(num1) && is_infinite(num2)) {
    res = kOperandInfNan;       // 正负无穷相除 = NAN
  } else { // !is_infinite(num1) && !is_infinite(num2)
    res = kOperandInfIndeterminacy;
  }
  return res;
}

int __mod_infinite(const Float& num1, const Float& num2) {
  int res = kOperandInfIndeterminacy;
  if (is_zero(num2)) {
    divisor_is_zero_exception("num2 = %s", num2.str().c_str());
  } else if (is_zero(num1)) {
    res = kOperandInfZero;
  } else if (!is_infinite(num1) && !is_infinite(num2)) {
    res = kOperandInfIndeterminacy;
  } else if (is_infinite(num1) && !is_infinite(num2)) {
    res = kOperandInfNan;
  } else if (!is_infinite(num1) && is_infinite(num2)) {
    res = kOperandInfIndeterminacy;
  } else { // is_infinite(num1) && is_infinite(num2)
    res = kOperandInfNan;
  }
  return res;
}

Float __infinite_operation_result(int inf, int unused) {
  Float res;
  if (inf == kOperandInfNegInfinity) {
    res.set_sign(kNegative); res.set_infinite(true);
  } else if (inf == kOperandInfPosInfinity) {
    res.set_sign(kPositive); res.set_infinite(true);
  } else if (inf == kOperandInfZero) {
    res.zero();
  } else if (inf == kOperandInfOne) {
    res.set_sign(kPositive); res.one();
  } else if (inf == kOperandInfNegOne) {
    res.set_sign(kNegative); res.one();
  } else if (inf == kOperandInfNan) {
    res.nan();
  } else if (inf == kOperandInfIndeterminacy) {
    res.none();
  } else {
    invalid_arguments_exception("inf = %d", inf);
  }
  return res;
}

} // namespace mynum