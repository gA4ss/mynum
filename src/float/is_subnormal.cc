#include <mynum/float.h>

namespace mynum {

bool is_subnormal(const Float& num1) {
  return le(abs(num1), __config.epsilon);
}

} // namespace mynum