#include <mynum/integer.h>

namespace mynum {

Integer mod(const Integer& num1, const Integer& num2) {
  std::pair<Integer, Integer> res = div(num1, num2);
  return res.second;
}

} // namespace mynum