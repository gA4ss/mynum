#include <mynum/integer.h>

namespace mynum {

bool is_zero(const Integer& num1) {
  if (is_infinite(num1)) return false;

  bignum_t integer_park = num1.integer_park();
  // 两个队列没有值就是0。
  if (integer_park.empty())
    return true;
  
  for (size_t i = 0; i < integer_park.size(); i++) {
    if (integer_park[i] != 0)
      return false;
  }

  return true;
}

} // namespace mynum