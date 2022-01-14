/* 误差函数（也称之为高斯误差函数，error function or Gauss error function）
 * 是一个非基本函数（即不是初等函数），
 * 其在概率论、统计学以及偏微分方程和半导体物理中都有广泛的应用。
 * 
 * 以下是使用泰勒展开公式逼近。
 */
#include <cmath>
#include <mynum/float.h>
#include <mynum/constant.h>

namespace mynum {

Float erf(const Float& x, const char* epsilon) {
  Float res = "0";
  Float c = div(Float("2"), sqrt(__pi));
  // Float c = Float(2.0 / std::sqrt(M_PI));
  Float numerator, denominator = "1", item, p, e;
  my::uinteger_t n = 0;
  do {
    p = res;
    e = add(mul("2", Float(n)), "1");
    numerator = pow(x, e);
    denominator = mul(factorial(Float(n)), e);
    item = div(numerator, denominator);
    // std::cout << "item = " << item.str() << std::endl;
    if (n % 2 == 0) {
      res += item;
    } else {
      res -= item;
    }
    ++n;
    // std::cout << "res = " << res.str() << std::endl << std::endl;
  } while (abs(res - p) > epsilon);
  return mul(c, res);
}

} // namespace mynum