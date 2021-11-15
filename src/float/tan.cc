#include <mynum/float.h>
#include <mynum/constant.h>
namespace mynum {

extern std::vector<Float> __bernoulli_numbers;

Float tan(const Float& x, const char* epsilon) {
  //
  // 保证 |x| < pi/2
  //
  if ((abs(x) > __half_pi) || (__half_pi - (abs(x)) <= epsilon)) {
    operand_value_is_invalid_exception(
      "|x| < PI/2, x = %s", x.str().c_str()
    );
  }

  size_t i = 0, j = __bernoulli_numbers.size();
  Float res = "0";
  Float numerator, denominator, item, exponent = "0", p;
  Float n = "1", b; //, p;
  Float m = "0.0333333333333333";
  do {
    if (i >= j) break;      // 超过表大小
    p = res;
    std::cout << "n = " << n.str() << std::endl;
    exponent = n * "2";
    std::cout << "exponent = " << exponent.str() << std::endl;
    b = __bernoulli_numbers[i];
    std::cout << "b = " << b.str() << std::endl;
    numerator = pow("2", exponent) * (pow("2", exponent) - "1");
    std::cout << "constant = " << numerator.str() << std::endl;
    numerator *= b;
    // numerator *= pow("-1", sub(n, "1"));
    std::cout << "numerator = " << numerator.str() << std::endl;
    denominator = factorial(exponent);
    std::cout << "denominator = " << denominator.str() << std::endl;
    item = div(numerator, denominator);
    std::cout << "fraction = " << item.str() << std::endl;
    --exponent;
    // p = pow(x, exponent);
    std::cout << "pow = " << p.str() << std::endl;
    // item *= p;
    item *= pow(x, exponent);
    std::cout << "item = " << item.str() << std::endl;
    res += item;
    ++n;
    ++i;
    std::cout << "res = " << res.str() << std::endl << std::endl;
  } while (abs(res - p) > epsilon);
  return res;
}

} // namespace mynum