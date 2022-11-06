#include <mynum/mynum.h>

namespace mynum
{
  namespace f
  {
#define __pow(a, x, p) mympf::round(mympf::exp(a, x), p)
    float_t pow(const float_t &a, const float_t &x, const float_t &epsilon, size_t precision)
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
        // 如果x是整数，小数部分为0
        y = __pow(a, x, precision); // 求a^x次方
      }
      else
      {
        float_t lna = ln(a, epsilon, precision);
        // mynum_dbgprint_fmt("lna = %s.\n", mympf::print_string(lna).c_str());
        y = f::exp(mympf::mul(x, lna), epsilon, precision); // 求e^{ln(x*lna)}
      }
      return y;
    }
  }

} // namespace mynum