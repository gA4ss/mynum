#include <mynum/mynum.h>

namespace mynum
{

  namespace f
  {
    float_t sin(const float_t &x, const float_t &epsilon, size_t precision)
    {
      const float_t const_0 = mympf::create(0);
      const float_t const_1 = mympf::create(1);
      const float_t const_2 = mympf::create(2);

      size_t i = 1;
      float_t y = const_0;
      float_t numerator, denominator = const_1, item, p;
      do
      {
        p = y;
        // mynum_dbgprint_fmt("p = %s.\n", mympf::print_string(p).c_str());
        numerator = pow(x, denominator, epsilon, precision);
        // mynum_dbgprint_fmt("numerator = %s.\n", mympf::print_string(numerator).c_str());
        item = mympf::div(numerator, factorial(denominator));
        // mynum_dbgprint_fmt("item = %s.\n", mympf::print_string(item).c_str());
        if (i % 2 == 0)
        {
          y = mympf::sub(y, item);
        }
        else
        {
          y = mympf::add(y, item);
        }
        // mynum_dbgprint_fmt("y = %s.\n", mympf::print_string(y).c_str());
        denominator = mympf::add(denominator, const_2);
        // mynum_dbgprint_fmt("denominator = %s.\n", mympf::print_string(denominator).c_str());
        ++i;
      } while (!diff_eps(y, p, epsilon));
      return check_result_on_precision(y, precision);
      // return y;
    }
  }

} // namespace mynum