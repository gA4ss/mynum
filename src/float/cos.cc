#include <mynum/mynum.h>

namespace mynum
{
  namespace f
  {

    float_t cos(const float_t &x, size_t precision)
    {
      const float_t const_0 = mympf::create(0);
      const float_t const_1 = mympf::create(1);
      const float_t const_2 = mympf::create(2);

      float_t y = const_1;
      size_t i = 1;
      float_t numerator, denominator = const_0, item = const_1, p = const_0;
      const float_t epsilon = epsilon_from_precision(precision);

      do
      {
        if (i != 1)
        {
          p = y;
          numerator = pow(x, denominator, precision);
          item = mympf::div(numerator, factorial(denominator));
          if (i % 2 == 0)
          {
            y = mympf::sub(y, item);
          }
          else
          {
            y = mympf::add(y, item);
          }
        }
        denominator = mympf::add(denominator, const_2);
        ++i;
      } while (!diff_eps(y, p, epsilon));
      return check_result_on_precision(y, precision);
    }
  }

} // namespace mynum