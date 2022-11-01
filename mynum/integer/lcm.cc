#include <mynum/integer.h>

namespace mynum {

Integer lcm(const Integer& num1, const Integer& num2) {
  Integer res, g;
  g = gcd(num1, num2);
  res = mul(num1, num2);
  res = res / g;
  return res;
}

} // namespace mynum