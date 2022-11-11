#include <mynum/mynum.h>

namespace mynum
{

  namespace f
  {

    static float_t __ln_1(const float_t &x, size_t precision)
    {
      // mynum_dbgprint_fmt("ln(%s).\n", mympf::print_string(x).c_str());
      if (mympf::cmp(x, mympf::create("0.5")) < 0)
      {
        mynum_operand_value_is_invalid_exception(
            "x >= 1/2, x = %s", mympf::print_string(x).c_str());
      }

      const float_t const_0 = mympf::create(0);
      const float_t const_1 = mympf::create(1);
      float_t y = const_0, n = const_1, p;
      float_t item = mympf::div(mympf::sub(x, const_1), x), t;
      const float_t epsilon = epsilon_from_precision(precision);
      do
      {
        p = y;
        t = pow(item, n, precision);
        t = mympf::div(t, n);
        y = mympf::add(y, t);
        n = mympf::add(n, const_1);
        // mynum_dbgprint_fmt("p = %s.\n", mympf::print_string(p).c_str());
        // mynum_dbgprint_fmt("y = %s.\n", mympf::print_string(y).c_str());
        // mynum_dbgprint_fmt("diff = %s.\n", mympf::print_string(mympf::usub(y, p)).c_str());
      } while (!diff_eps(y, p, epsilon));
      return y;
    }

    static float_t __ln_2(const float_t &x, size_t precision)
    {
      // mynum_dbgprint_fmt("ln(%s).\n", mympf::print_string(x).c_str());
      const float_t const_0 = mympf::create(0);
      const float_t const_1 = mympf::create(1);
      // 这里蕴含了 x > 0
      if (mympf::cmp(x, const_0) < 0)
      {
        mynum_operand_value_is_invalid_exception(
            "x > 0, x = %s", mympf::print_string(x).c_str());
      }

      float_t y = const_0, n = const_1, t = mympf::create(2), p;
      /* (x-1)/(x+1) */
      float_t item = mympf::div(mympf::sub(x, const_1),
                                mympf::add(x, const_1));
      const float_t epsilon = epsilon_from_precision(precision);
      do
      {
        p = y;
        y = mympf::add(y, mympf::div(pow(item, n, precision), n));
        n = mympf::add(n, t);
        // mynum_dbgprint_fmt("p = %s.\n", mympf::print_string(p).c_str());
        // mynum_dbgprint_fmt("y = %s.\n", mympf::print_string(y).c_str());
        // mynum_dbgprint_fmt("diff = %s.\n", mympf::print_string(mympf::usub(y, p)).c_str());
      } while (!diff_eps(y, p, epsilon));
      y = mympf::mul(y, t);
      return y;
    }

    float_t ln(const float_t &x, size_t precision)
    {
      const float_t const_0 = mympf::create(0);
      const float_t const_1 = mympf::create(1);
      // x > 0
      if (mympf::cmp(x, const_0) < 0)
      {
        mynum_operand_value_is_invalid_exception(
            "x > 0, x = %s", print_string(x).c_str());
      }
      if (mympf::cmp(x, const_1) == 0)
        return const_0;

      float_t y;
      if (mympf::cmp(x, mympf::create("0.5")) >= 0)
        y = __ln_1(x, precision);
      else
        y = __ln_2(x, precision);

#if defined(FULL_COMPUTE_IN_CORE)
      return y;
#else
      return check_result_on_precision(y, precision);
#endif
      // return y;
    }
  }
} // namespace mynum