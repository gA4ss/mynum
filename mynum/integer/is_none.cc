#include <mynum/integer.h>

namespace mynum {

bool is_none(const Integer& num1) {
  return ((is_nan(num1)) && (num1.sign() == kNegative));
}

} // namespace mynum