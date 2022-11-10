/* 误差函数（也称之为高斯误差函数，error function or Gauss error function）
 * 是一个非基本函数（即不是初等函数），
 * 其在概率论、统计学以及偏微分方程和半导体物理中都有广泛的应用。
 *
 * 以下是使用泰勒展开公式逼近。
 */
#include <cmath>
#include <mynum/mynum.h>

namespace mynum
{

  namespace f
  {
    float_t erf(const float_t &x, size_t precision)
    {
      const float_t const_0 = mympf::create(0);
      const float_t const_1 = mympf::create(1);
      const float_t const_2 = mympf::create(2);
      const float_t const_pi = mympf::create(M_PI);
      const float_t epsilon = epsilon_from_precision(precision);
      float_t y = const_0;
      float_t c = div(const_2, f::sqrt(const_pi, precision));
      float_t numerator, denominator = const_1, item, p, e;
      size_t n = 0;
      do
      {
        p = y;
        e = mympf::add(mympf::mul(const_2, mympf::create(n)), const_1);
        numerator = pow(x, e, precision);
        denominator = mympf::mul(factorial(mympf::create(n)), e);
        item = mympf::div(numerator, denominator);
        if (n % 2 == 0)
        {
          y = mympf::add(y, item);
        }
        else
        {
          y = mympf::sub(y, item);
        }
        ++n;
      } while (!diff_eps(y, p, epsilon));
      y = mympf::mul(c, y);
      return check_result_on_precision(y, precision);
    }
  }

} // namespace mynum