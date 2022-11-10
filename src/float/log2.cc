#include <mynum/mynum.h>

namespace mynum
{

  namespace f
  {
    float_t log2(const float_t &x, size_t precision)
    {
      // x > 0
      if (mympf::cmp(x, mympf::create(0)) <= 0)
      {
        mynum_operand_value_is_invalid_exception(
            "x > 0, x = %s", mympf::print_string(x).c_str());
      }
      float_t y = mympf::div(ln(x, precision), ln(mympf::create(2), precision));
      return check_result_on_precision(y, precision);
    }
  }

} // namespace mynum