#include <mynum/float.h>
namespace mynum {

Float cos(const Float& x, const char* epsilon) {
  Float res = "1";
  my::uinteger_t i = 1;
  Float numerator, denominator = "0", item = "1", p = "0";
  do {
    if (i != 1) {
      p = res;
      numerator = pow(x, denominator);
      // std::cout << i << std::endl;
      // std::cout << "numerator = " << numerator.str() << std::endl;
      // std::cout << "factorial(denominator) = " << factorial(denominator).str() << std::endl;
      item = div(numerator, factorial(denominator));
      // std::cout << "item = " << item.str() << std::endl;
      if (i % 2 == 0) {
        res -= item;
      } else {
        res += item;
      }
    }
    denominator += "2";
    ++i;
    // std::cout << "res = " << res.str() << std::endl << std::endl;
  } while (abs(res - p) > epsilon);
  return res;
}

} // namespace mynum