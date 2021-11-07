#include <mynum/bignum.h>

namespace mynum {

division_result_t div2(const bignum_t& a, const bignum_t& b, uinteger_t precision) {
  if (a.empty() || b.empty()) {
    operand_value_is_invalid_exception(
      "%s", "operand a or b is nan."
    );
  }
  if (is_zero(b)) divisor_is_zero_exception("%s", "b is zero.");
  division_result_t res = div(a, b);
  shrink_zero(res.first, true); shrink_zero(res.second, true);
  if (is_zero(res.second)) return res;    // 余数为0

  //
  // 如果不整除则开始计算
  //
  bignum_t quotient = {0}, integer_park = res.first,
           dividend = res.second,
           divisor = b;
  int cr = 0;

  while (1) {
    //
    // 如果精度达到要求则停止
    // quotient.size() 初始值为 1
    //
    if (quotient.size() > precision)
      break;

    //
    // 借位
    //
    // 第一次借位商不压入0，从第二次开始才要压入。
    //
    cr = cmp(dividend, divisor);
    if (cr == -1) { \
      dividend.push_front(0);  // 压入一个0
      while (cmp(dividend, divisor) == -1) {
        dividend.push_front(0);
        quotient.push_front(0);
      }
    }
    res = div(dividend, divisor);
    shrink_zero(res.first, true); shrink_zero(res.second, true);
    quotient.insert(quotient.begin(), res.first.begin(), res.first.end());
    //
    // 如果余数为0，说明除法完毕。
    //
    if (is_zero(res.second)) {
      break;
    }

    //
    // 更新被除数
    //
    dividend = res.second;
  } // end while

  return division_result_t(integer_park, quotient);
}

} // namespace mynum