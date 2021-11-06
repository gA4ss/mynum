#include <mynum/float.h>

namespace mynum {

bool is_integer(const Float& num1) {
  return is_zero(num1.decimal_park());
}

} // namespace mynum