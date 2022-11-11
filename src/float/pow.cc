#include <mynum/mynum.h>

namespace mynum
{
  namespace f
  {

#if defined(FULL_COMPUTE_IN_CORE)
#define __pow(a, x) mympf::exp(a, x)
#else
#define __pow(a, x, p) mympf::round(mympf::exp(a, x), p)
#endif

    float_t pow(const float_t &a, const float_t &x, size_t precision)
    {
      if (f::is_one(a) || f::is_zero(x))
        return mympf::create(1);

      //
      // 只有在x为整数是，a才可以小于0。
      //
      if (is_float(x))
      {
        if (mympf::cmp(a, mympf::create(0)) < 0)
        {
          mynum_operand_value_is_invalid_exception(
              "a > 0 in x is float, a = %s", mympf::print_string(a).c_str());
        }
      }

      float_t y;
      if (is_integer(x))
      {
#if defined(FULL_COMPUTE_IN_CORE)
        y = __pow(a, x);
#else
        // 如果x是整数，小数部分为0
        y = __pow(a, x, precision); // 求a^x次方
#endif
      }
      else
      {
        float_t lna = ln(a, precision);
        // mynum_dbgprint_fmt("lna = %s.\n", mympf::print_string(lna).c_str());
        y = f::exp(mympf::mul(x, lna), precision); // 求e^{ln(x*lna)}
      }

#if defined(FULL_COMPUTE_IN_CORE)
      return y;
#else
      return check_result_on_precision(y, precision);
#endif
      // return y;
    }
  }

} // namespace mynum