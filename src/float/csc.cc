#include <mynum/float.h>
#include <mynum/constant.h>

namespace mynum {

extern std::vector<Float> __bernoulli_numbers;

Float csc(const Float& x, const char* epsilon) {
  //
  // 保证 0< |x| < pi
  //
  if ((is_zero(x)) || (abs(x) > __pi) || (__pi - (abs(x)) <= epsilon)) {
    operand_value_is_invalid_exception(
      "0 < x < PI, x = %s", x.str().c_str()
    );
  }

  size_t i = 1, j = __bernoulli_numbers.size();
  Float res = div("1", x);
  Float numerator, denominator, item, exponent = "0";
  Float n = "1", b, p;
  do {
    p = res;
    // std::cout << "n = " << n.str() << std::endl;
    exponent = n * "2";
    // std::cout << "exponent = " << exponent.str() << std::endl;
    denominator = factorial(exponent);
    // std::cout << "denominator = " << denominator.str() << std::endl;
    --exponent;   // 2n-1
    if (i < j) {
      b = __bernoulli_numbers[i];
    } else {
      // 超过表大小，则重新计算。
    }
    // std::cout << "b = " << b.str() << std::endl;
    numerator = "2" * sub(pow("2", exponent), "1");
    // std::cout << "constant = " << numerator.str() << std::endl;
    numerator *= b;
    // std::cout << "numerator = " << numerator.str() << std::endl;
    item = div(numerator, denominator);
    // std::cout << "div(numerator, denominator) = " << item.str() << std::endl;
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