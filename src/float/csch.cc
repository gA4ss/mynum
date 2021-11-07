#include <mynum/float.h>
namespace mynum {

Float csch(const Float& x) {
  Float res = "0";
  // uinteger_t taylor_expansion = Float::config_.taylor_expansion;
  // Float numerator, denominator = "1", item;
  // for (uinteger_t i = 1; i <= taylor_expansion; i++) {
  //   numerator = pow(x, denominator);
  //   // std::cout << taylor_expansion << std::endl;
  //   // std::cout << "numerator = " << numerator.str() << std::endl;
  //   // std::cout << "factorial(denominator) = " << factorial(denominator).str() << std::endl;
  //   item = div(numerator, factorial(denominator));
  //   // std::cout << "item = " << item.str() << std::endl;
  //   if (i % 2 == 0) {
  //     res -= item;
  //   } else {
  //     res += item;
  //   }
  //   denominator += "2";
  //   // std::cout << "res = " << res.str() << std::endl;
  // }
  // return round(res, Float::config_.precision);
  return res;
}

} // namespace mynum