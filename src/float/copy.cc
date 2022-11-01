#include <mynum/float.h>

namespace mynum {

void copy(Float& to, const Float& from) {
  to.set_sign(from.sign());
  to.set_infinite(from.infinite());
  to.set_integer_park(from.integer_park());
  to.set_decimal_park(from.decimal_park());
}

} // namespace mynum