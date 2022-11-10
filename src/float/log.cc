#include <mynum/mynum.h>

namespace mynum
{

  namespace f
  {
    float_t log(const float_t &base, const float_t &x, size_t precision)
    {
      // base > 0，base != 1，x > 0
      const float_t const_0 = mympf::create(0);
      const float_t const_1 = mympf::create(1);
      if ((mympf::cmp(base, const_0) <= 0) || (mympf::cmp(base, const_1) == 0))
      {
        mynum_operand_value_is_invalid_exception(
            "base > 0 and base != 1, base = %s", mympf::print_string(base).c_str());
      }

      if (mympf::cmp(x, const_0) <= 0)
      {
        mynum_operand_value_is_invalid_exception(
            "x > 0, x = %s", mympf::print_string(x).c_str());
      }
      float_t y = mympf::div(ln(x, precision), ln(base, precision));
      return check_result_on_precision(y, precision);
    }
  }

} // namespace mynum