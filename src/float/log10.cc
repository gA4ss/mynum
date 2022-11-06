#include <mynum/mynum.h>

namespace mynum
{

  namespace f
  {
    float_t log10(const float_t &x, const float_t &epsilon, size_t precision)
    {
      // x > 0
      if (mympf::cmp(x, mympf::create(0)) <= 0)
      {
        mynum_operand_value_is_invalid_exception(
            "x > 0, x = %s", mympf::print_string(x).c_str());
      }
      float_t y = mympf::div(ln(x, epsilon, precision), ln(mympf::create(10), epsilon, precision));
      return check_result_on_precision(y, precision);
    }
  }

} // namespace mynum