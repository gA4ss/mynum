#include <mynum/float.h>
#include <mynum/constant.h>
namespace mynum {

extern std::vector<Float> __bernoulli_numbers;

Float csch(const Float& x, const char* epsilon) {
  //
  // 保证 0< |x| < pi
  //
  if ((is_zero(x)) || (abs(x) > __pi) || 
      (__pi - (abs(x)) <= epsilon)) {
    operand_value_is_invalid_exception(
      "0 < |x| < PI, x = %s", x.str().c_str()
    );
  }

  size_t i = 1, j = __bernoulli_numbers.size();
  Float res = div("1", x), p;
  Float numerator, denominator, item, exponent = "0", sign = "-1";
  Float n = "1", k = "-1", l = "2", o = "1", b;
  do {
    p = res;
    // std::cout << "n = " << n.str() << std::endl;
    exponent = sub(mul(n, l), o);   //  2n-1
    // std::cout << "exponent = " << exponent.str() << std::endl;
    if (i < j) {
      b = __bernoulli_numbers[i];
    } else {
      // 超过表大小，则重新计算。
    }
    // std::cout << "b = " << b.str() << std::endl;
    item = sub(pow(l, exponent), o);
    numerator = mul(l, item);
    // std::cout << "constant = " << numerator.str() << std::endl;
    numerator *= b;
    // std::cout << "numerator = " << numerator.str() << std::endl;
    denominator = factorial(add(exponent, o));
    // std::cout << "denominator = " << denominator.str() << std::endl;
    item = div(numerator, denominator);
    item *= pow(x, exponent);
    sign = pow(k, n);
    item *= sign;
    // std::cout << "item = " << item.str() << std::endl;
    res += item;
    // std::cout << "res = " << res.str() << std::endl << std::endl;
    ++n;
    ++i;
  } while (abs(res - p) > epsilon);
  return res;
}

} // namespace mynum