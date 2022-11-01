#include <mynum/float.h>

namespace mynum {

Float exp(const Float& x, const char* epsilon) {
  Float res = x, n = "2", p;
  do {
    p = res;
    res += div(pow(x, n), factorial(n));
    ++n;
  } while (abs(res - p) > epsilon);
  ++res;
  return res;
}

} // namespace mynum