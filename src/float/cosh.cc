#include <mynum/mynum.h>

namespace mynum
{
  namespace f
  {
    float_t cosh(const float_t &x, const float_t &epsilon, size_t precision)
    {
      float_t y = mympf::create(1);
      float_t numerator, denominator, item, p;
      float_t n = mympf::create(2);
      const float_t const_2 = n;

      do
      {
        p = y;
        numerator = pow(x, n, epsilon, precision);
        denominator = factorial(n);
        item = mympf::div(numerator, denominator);
        y = mympf::add(y, item);
        n = mympf::add(n, const_2);
      } while (!diff_eps(y, p, epsilon));
      return check_result_on_precision(y, precision);
    }
  }

} // namespace mynum