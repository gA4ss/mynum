#include <mynum/float.h>
#include <mynum/constant.h>

namespace mynum {

extern std::vector<Float> __bernoulli_numbers;

Float coth(const Float& x, const char* epsilon) {
  //
  // 保证 0< |x| < pi
  //
  if ((is_zero(x)) || (abs(x) > __pi) || (__pi - (abs(x)) <= epsilon)) {
    operand_value_is_invalid_exception(
      "0 < x < PI, x = %s", x.str().c_str()
    );
  }

  size_t i = 0, j = __bernoulli_numbers.size();
  Float res = "1", sign = "-1";
  Float numerator, denominator, exponent, item;
  Float n = "1", b, p;
  Float o = "1", l = "2";
  do {
    p = res;
    if (i == 0) {
      res /= x;
      ++i;
      continue;
    }
    exponent = mul(n, l);   // 2n
    // std::cout << "exponent = " << exponent.str() << std::endl;
    if (i < j) {
      b = __bernoulli_numbers[i];
    } else {
      // 超过表大小，则重新计算。
    }
    // std::cout << "b = " << b.str() << std::endl;
    numerator = pow(l, exponent);
    // std::cout << "p = " << numerator.str() << std::endl;
    numerator *= b;
    // std::cout << "numerator = " << numerator.str() << std::endl;
    denominator = factorial(exponent);
    // std::cout << "denominator = " << denominator.str() << std::endl;
    item = div(numerator, denominator);
    // std::cout << "fraction = " << item.str() << std::endl;
    --exponent;
    item *= pow(x, exponent);
    item *= pow(sign, sub(n, o));
    // std::cout << "item = " << item.str() << std::endl;
    res += item;
    // std::cout << "res = " << res.str() << std::endl << std::endl;
    ++n;
    ++i;
  } while (abs(res - p) > epsilon);
  return res;
}

} // namespace mynum