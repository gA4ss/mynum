#include <mynum/float.h>
namespace mynum {

Float sinh(const Float& x, const char* epsilon) {
  Float res = x;
  Float numerator, denominator, item, p;
  Float n = "3";
  do {
    p = res;
    numerator = pow(x, n);
    denominator = factorial(n);
    item = div(numerator, denominator);
    res += item;
    n += "2";
  } while (abs(res - p) > epsilon);
  return res;
}

} // namespace mynum