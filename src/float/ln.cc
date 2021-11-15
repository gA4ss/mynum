#include <mynum/float.h>

namespace mynum {

static Float __ln_1(const Float& x, const char* epsilon) {
  if (x < "0.5") {
    operand_value_is_invalid_exception(
      "x >= 1/2, x = %s", x.str().c_str()
    );
  }

  Float res = "0", n = "1", p;
  Float item = div(sub(x, "1"), x), y;
  // std::cout << "item = " << item.str() << std::endl;

  do {
    p = res;
    y = pow(item, n);
    // std::cout << "pow(item, n) = " << y.str() << std::endl;
    y = div(y, n);
    // std::cout << "y = " << y.str() << std::endl;
    res += y;
    // std::cout << "res = " << res.str() << std::endl;
    ++n;
  } while (abs(res - p) > epsilon);
  return res;
}

static Float __ln_2(const Float& x, const char* epsilon) {
  // 这里蕴含了 x > 0
  if (x < "0") {
    operand_value_is_invalid_exception(
      "x > 0, x = %s", x.str().c_str()
    );
  }

  Float res = "0", n = "1", t = "2", p;
  Float item = div(sub(x, "1"), add(x, "1"));
  do {
    p = res;
    res += div(pow(item, n), n);
    n += t;
  } while (abs(res - p) > epsilon);
  res *= t;
  return res;
}

Float ln(const Float& x, const char* epsilon) {
  // x > 0
  if (x < "0") {
    operand_value_is_invalid_exception(
      "x > 0, x = %s", x.str().c_str()
    );
  }
  if (is_one(x)) return Float("0");

  Float res;
  if (x >= "0.5")
    res = __ln_1(x, epsilon);
  else
    res = __ln_2(x, epsilon);
  return res;
}

} // namespace mynum