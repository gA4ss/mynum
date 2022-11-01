#include <mynum/float.h>
namespace mynum {

Float floor(const Float& num1) {
  if (is_nan(num1)) return Float();
  if (is_infinite(num1)) return Float("inf");
  if (is_integer(num1)) return num1;

  Float res = num1;
  res.set_decimal_park_zero();
  if (num1.sign() == kNegative) {
    res.set_sign(kPositive);
    res = add(res, Float("1"));
    res.set_sign(kNegative);
  }
  return res;
}

} // namespace mynum