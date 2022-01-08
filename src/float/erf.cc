#include <mynum/float.h>
#include <mynum/constant.h>

namespace mynum {

Float erf(const Float& x, const char* epsilon) {
  Float res = "0";
  uinteger_t n = 0;
  Float c = div(Float("2"), sqrt(__pi));
  Float numerator, denominator = "1", item, p, e;
  do {
    p = res;
    e = add(mul("2", Float(n)), "1");
    numerator = pow(x, e);
    denominator = mul(factorial(Float(n)), e);
    item = div(numerator, denominator);
    // std::cout << "item = " << item.str() << std::endl;
    if (n % 2 == 0) {
      res += item;
    } else {
      res -= item;
    }
    ++n;
    // std::cout << "res = " << res.str() << std::endl << std::endl;
  } while (abs(res - p) > epsilon);
  return mul(c, res);
}

} // namespace mynum