#include <mynum/mynum.h>
namespace mynum
{
  namespace f
  {
    float_t arccoth(const float_t &x, const float_t &epsilon, size_t precision)
    {
      // x > 1, x < -1
      const float_t const_1 = mympf::create(1);
      if ((mympf::cmp(x, mympf::create("-1")) >= 0) && (mympf::cmp(x, const_1) <= 0))
      {
        mynum_operand_value_is_invalid_exception(
            "x > 1 or x < -1, x = %s", mympf::print_string(x).c_str());
      }
      float_t y = ln(mympf::div(mympf::add(x, const_1), mympf::sub(x, const_1)), epsilon, precision);
      y = mympf::div(y, mympf::create(2));
      return check_result_on_precision(y, precision);
    }
  }
} // namespace mynum