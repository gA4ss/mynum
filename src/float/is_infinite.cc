#include <mynum/float.h>

namespace mynum {

bool is_infinite(const Float& num1) {
  return num1.infinite();
}

} // namespace mynum