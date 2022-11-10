#include <mynum/mynum.h>
namespace mynum
{
  namespace f
  {
    float_t arctanh(const float_t &x, size_t precision)
    {
      // -1 < x < 1
      const float_t const_1 = mympf::create(1);
      if (mympf::ucmp(x, const_1) >= 0)
      {
        mynum_operand_value_is_invalid_exception(
            "|x| < 1, x = %s", mympf::print_string(x).c_str());
      }
      const float_t const_2 = mympf::create(2);
      float_t y = ln(mympf::div(mympf::add(const_1, x), mympf::sub(const_1, x)), precision);
      y = mympf::div(y, const_2);
      return check_result_on_precision(y, precision);
    }
  }

} // namespace mynum