#include <mynum/float.h>
#include <mynum/constant.h>

namespace mynum {

static Float __arctan_1(const Float& x, const char* epsilon) { 
  if (abs(x) >= "1") {
    operand_value_is_invalid_exception(
      "|x| < 1, x = %s", x.str().c_str()
    );
  }

  Float res = "0", n = "1", item, p;
  my::uinteger_t i = 1;
  do {
    p = res;
    item = div(pow(x, n), n);
    if (i % 2 == 0)
      res -= item;
    else
      res += item;
    n += "2";
    ++i;
  } while (abs(res - p) > epsilon);
  return res;
}

static Float __arctan_2(const Float& x, const char* epsilon) {
  if (abs(x) < "1") {
    operand_value_is_invalid_exception(
      "x >= 1 or x <= -1, x = %s", x.str().c_str()
    );
  }

  Float res = "0", n = "1", item, p;
  size_t i = 1;
  do {
    p = res;
    item = div("1", mul(n, pow(x, n)));
    if (i % 2 == 0)
      res += item;
    else
      res -= item;
    n += "2";
    ++i;
  } while (abs(res - p) > epsilon);

  Float half_pi = __half_pi;
  if (x <= "-1") half_pi = __half_pi * "-1";
  res = half_pi + res;
  return res;
}

Float arctan(const Float& x, const char* epsilon) {
  Float res = "0";
  if (abs(x) < "1") {
    res = __arctan_1(x, epsilon);
  } else {
    res = __arctan_2(x, epsilon);
  }
  return res;
}

} // namespace mynum