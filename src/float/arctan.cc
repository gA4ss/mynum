#include <mynum/mynum.h>

namespace mynum
{
  namespace f
  {
    static float_t __arctan_1(const float_t &x, const float_t &epsilon, size_t precision)
    {
      const float_t const_0 = mympf::create(0);
      const float_t const_1 = mympf::create(1);

      if (mympf::ucmp(x, const_1) >= 0)
      {
        mynum_operand_value_is_invalid_exception(
            "|x| < 1, x = %s", mympf::print_string(x).c_str());
      }

      float_t y = const_0, n = const_1, item, p;
      const float_t const_2 = mympf::create(2);
      size_t i = 1;
      do
      {
        p = y;
        item = mympf::div(pow(x, n, epsilon, precision), n);
        if (i % 2 == 0)
          y = mympf::sub(y, item);
        else
          y = mympf::add(y, item);
        n = mympf::add(n, const_2);
        ++i;
      } while (!diff_eps(y, p, epsilon));
      return y;
    }

    static float_t __arctan_2(const float_t &x, const float_t &epsilon, size_t precision)
    {
      const float_t const_0 = mympf::create(0);
      const float_t const_1 = mympf::create(1);

      if (mympf::ucmp(x, const_1) < 0)
      {
        mynum_operand_value_is_invalid_exception(
            "x >= 1 or x <= -1, x = %s", mympf::print_string(x).c_str());
      }

      float_t y = const_0, n = const_1, item, p;
      const float_t const_2 = mympf::create(2);
      const float_t const_m1 = mympf::create("-1");
      size_t i = 1;
      do
      {
        p = y;
        item = mympf::div(const_1, mympf::mul(n, pow(x, n, epsilon, precision)));
        if (i % 2 == 0)
          y = mympf::add(y, item);
        else
          y = mympf::sub(y, item);
        n = mympf::add(n, const_2);
        ++i;
      } while (!diff_eps(y, p, epsilon));

      float_t half_pi = mympf::create(M_PI_2);
      if (mympf::cmp(x, const_m1) <= 0)
        half_pi.set_neg(!!!(half_pi.neg()));  // half_pi = half_pi * -1
      y = mympf::add(half_pi, y);
      return y;
    }

    float_t arctan(const float_t &x, const float_t &epsilon, size_t precision)
    {
      float_t y = mympf::create(0);
      if (mympf::ucmp(x, mympf::create(1)) < 0)
      {
        y = __arctan_1(x, epsilon, precision);
      }
      else
      {
        y = __arctan_2(x, epsilon, precision);
      }
      return check_result_on_precision(y, precision);
    }
  }

} // namespace mynum