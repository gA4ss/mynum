#include <mynum/integer.h>

namespace mynum {

Integer add(const Integer& num1, const Integer& num2) {
  Integer res;
  if (is_nan(num1) || is_nan(num2)) return res;
  if (is_zero(num1)) return num2;
  if (is_zero(num2)) return num1;

  int inf = __add_infinite(num1, num2);
  res = __infinite_operation_result(inf);
  if (!is_none(res))
    return res;

  // num1与num2同号
  if (num1.sign() == num2.sign()) {
    bool o = false;
    bignum_t integer_park_1 = num1.integer_park(), integer_park_2 = num2.integer_park();
    bignum_t integer_park = add(integer_park_1, integer_park_2, o);
    shrink_zero(integer_park, true);
    res.set_integer_park(integer_park);
    res.set_sign(num1.sign());
  } else { // 异号
    if (num1.sign() > num2.sign()) {
      Integer _num2(num2);
      res = sub(num1, -_num2);
    } else {
      Integer _num1(num1);
      res = sub(num2, -_num1);
    }
  }
  return res;
}

} // namespace mynum