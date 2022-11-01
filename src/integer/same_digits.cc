#include <mynum/integer.h>

namespace mynum {

void same_digits(Integer& num1, Integer& num2) {
  bignum_t integer_park_1 = num1.integer_park();
  bignum_t integer_park_2 = num2.integer_park();
  bignum_t x, y;

  if (integer_park_1.size() > integer_park_2.size()) {
    size_t n = integer_park_1.size() - integer_park_2.size();
    for (size_t i = 0; i < n; i++) {
      integer_park_2.push_back(0);
    }
    num2.set_integer_park(integer_park_2);
  } else if (integer_park_1.size() < integer_park_2.size()) {
    size_t n = integer_park_2.size() - integer_park_1.size();
    for (size_t i = 0; i < n; i++) {
      integer_park_1.push_back(0);
    }
    num1.set_integer_park(integer_park_1);
  }
}

} // namespace mynum