#include <mynum/integer.h>

namespace mynum {

/*
 * Euclid(a = q_0b + r_0)
 */
Integer gcd(const Integer& num1, const Integer& num2) {
  Integer a,b,r;
  if (abs(num1) > abs(num2)) {
    a = abs(num1); b = abs(num2);
  } else if (abs(num1) < abs(num2))  {
    a = abs(num2); b = abs(num1);
  } else {
    return abs(num1);
  }

  while(true) {
    r = mod(a, b);
    if (r == "0")
      break;
    a = b;
    b = r;
  };
  return b;
}

} // namespace mynum