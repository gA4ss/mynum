#include <mynum/integer.h>
namespace mynum {

Integer floor(const Integer& num1) {
  if (is_nan(num1)) return Integer();
  if (is_infinite(num1)) return Integer("inf");

  Integer res = num1;
  if (num1.sign() == kNegative) {
    res.set_sign(kPositive);
    res = add(res, Integer("1"));
    res.set_sign(kNegative);
  }
  return res;
}

} // namespace mynum