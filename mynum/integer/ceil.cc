#include <mynum/integer.h>

namespace mynum {

Integer ceil(const Integer& num1) {
  if (is_nan(num1)) return Integer();
  if (is_infinite(num1)) return Integer("inf");
  
  Integer res = num1;
  if (num1.sign() == kPositive) {
    res = add(res, Integer("1"));
  }
  return res;
}

} // namespace mynum