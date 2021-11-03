#include <mynum/integer.h>

namespace mynum {

void copy(Integer& to, const Integer& from) {
  to.set_sign(from.sign());
  to.set_infinite(from.infinite());
  to.set_integer_park(from.integer_park());
}

} // namespace mynum