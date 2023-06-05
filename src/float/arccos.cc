#include <mynum/mynum.h>

namespace mynum
{
  namespace f
  {
    float_t arccos(const float_t &x, size_t precision)
    {
      //
      // 保证 |x| < 1
      //
      if (mympf::ucmp(x, mympf::create(1)) >= 0)
      {
        mynum_operand_value_is_invalid_exception(
            "|x| < 1, x = %s", mympf::print_string(x).c_str());
      }
      // float_t y = mympf::sub(mympf::create(M_PI_2), arcsin(x, precision));
      float_t y = mympf::sub(approximate_pi(precision), arcsin(x, precision));
      return check_result_on_precision(y, precision);
    }
  }

} // namespace mynum