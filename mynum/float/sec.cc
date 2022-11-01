#include <mynum/float.h>
#include <mynum/constant.h>

namespace mynum {

extern std::vector<Float> __euler_numbers;

Float sec(const Float& x, const char* epsilon) {
  //
  // 保证 |x| < pi/2
  //
  if ((abs(x) > __half_pi) || (__half_pi - (abs(x)) <= epsilon)) {
    operand_value_is_invalid_exception(
      "|x| < PI/2, x = %s", x.str().c_str()
    );
  }

  size_t i = 1, j = __euler_numbers.size();
  Float res = "1", n = "1", p, e;
  Float numerator, denominator, exponent, item;
  do {
    p = res;
    exponent = n * "2";
    // std::cout << "exponent = " << exponent.str() << std::endl;
    if (i < j) {
      e = __euler_numbers[i];
    } else {

    }
    numerator = abs(e);
    // std::cout << "numerator = " << numerator.str() << std::endl;
    denominator = factorial(exponent);
    // std::cout << "denominator = " << denominator.str() << std::endl;
    item = div(numerator, denominator);
    // std::cout << "fraction = " << item.str() << std::endl;
    item *= pow(x, exponent);
    // std::cout << "item = " << item.str() << std::endl;
    res += item;
    // std::cout << "res = " << res.str() << std::endl << std::endl;
    ++n;
    ++i;
  } while (abs(res - p) > epsilon);
  return res;
}

} // namespace mynum