#include <mynum/float.h>
namespace mynum {

Float arcsin(const Float& x, const char* epsilon) {
  //
  // 保证 |x| < 1
  //
  if (abs(x) >= "1") {
    operand_value_is_invalid_exception(
      "|x| < 1, x = %s", x.str().c_str()
    );
  }

  Float res = x, n = "3", item = "0", coeff = "1", p;
  Float numerator = "-1", denominator = "0";
  do {
    p = res;
    item = div(pow(x, n), n);
    numerator += "2"; denominator += "2";
    // std::cout << "numerator = " << numerator.str() << std::endl;
    // std::cout << "denominator = " << denominator.str() << std::endl;
    coeff *= div(numerator, denominator);
    // std::cout << "coeff = " << coeff.str() << std::endl;
    item *= coeff;
    // std::cout << "item = " << item.str() << std::endl;
    res += item;
    // std::cout << "res = " << res.str() << std::endl;
    // std::cout << "abs(res - p) = " << abs(res - p).str() << std::endl << std::endl;
    n += "2";
  } while (abs(res - p) > epsilon);
  return res;
}

} // namespace mynum