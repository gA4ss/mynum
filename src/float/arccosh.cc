#include <mynum/mynum.h>

namespace mynum
{
  namespace f
  {
    float_t arccosh(const float_t &x, const float_t &epsilon, size_t precision)
    {
      // x >= 1
      const float_t const_1 = mympf::create(1);
      if (mympf::cmp(x, const_1) < 0)
      {
        mynum_operand_value_is_invalid_exception(
            "x >= 1, x = %s", mympf::print_string(x).c_str());
      }
      const float_t const_2 = mympf::create(2);
      float_t y = mympf::sub(pow(x, const_2, epsilon, precision), const_1);
      y = ln(mympf::add(x, sqrt(y, epsilon, precision)), epsilon, precision);
      return check_result_on_precision(y, precision);
    }
  }

} // namespace mynum