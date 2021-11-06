#include <mynum/float.h>

namespace mynum {

bool is_nan(const Float& num1) {
  if (num1.infinite()) return false;
  return (num1.integer_park().empty() || 
          num1.decimal_park().empty()) && 
         (num1.sign() == kPositive);

}

} // namespace mynum