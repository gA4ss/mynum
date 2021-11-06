#include <mynum/integer.h>

namespace mynum {

bool is_none(const Integer& num1) {
  if (num1.infinite()) return false;
  return (num1.integer_park().empty() || 
          num1.decimal_park().empty()) && 
         (num1.sign() == kNegative);
}

} // namespace mynum