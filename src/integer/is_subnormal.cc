#include <mynum/integer.h>

namespace mynum {

bool is_subnormal(const Integer& num1) {
  return le(abs(num1), __config.epsilon);
}

} // namespace mynum