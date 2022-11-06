#include <mynum/mynum.h>
namespace mynum
{
  namespace f
  {
    float_t arcsec(const float_t &x, const float_t &epsilon, size_t precision)
    {
      const float_t const_1 = mympf::create(1);
      if (mympf::ucmp(x, const_1) <= 0)
      {
        mynum_operand_value_is_invalid_exception(
            "|x| > 1, x = %s", mympf::print_string(x).c_str());
      }
      float_t y = arccos(mympf::div(const_1, x), epsilon, precision);
      return check_result_on_precision(y, precision);
    }
  }

} // namespace mynum