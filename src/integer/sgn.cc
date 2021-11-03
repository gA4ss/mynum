#include <mynum/integer.h>
namespace mynum {

int sgn(const Integer& num1) {
  if (is_zero(num1)) return 0;
  return num1.sign();
}

} // namespace mynum