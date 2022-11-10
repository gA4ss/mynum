#include <mynum/mynum.h>

namespace mynum
{
  namespace f
  {
    float_t sinh(const float_t &x, size_t precision)
    {
      float_t y = x;
      float_t numerator, denominator, item, p;
      float_t n = mympf::create(3);
      const float_t const_2 = mympf::create(2);
      const float_t epsilon = epsilon_from_precision(precision);
      do
      {
        p = y;
        numerator = pow(x, n, precision);
        denominator = factorial(n);
        item = mympf::div(numerator, denominator);
        y = mympf::add(y, item);
        n = mympf::add(n, const_2);
      } while (!diff_eps(y, p, epsilon));
      return check_result_on_precision(y, precision);
    }
  }
} // namespace mynum