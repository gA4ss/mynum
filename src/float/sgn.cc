#include <mynum/float.h>
namespace mynum {

int sgn(const Float& num1) {
  if (is_zero(num1)) return 0;
  return num1.sign();
}

} // namespace mynum