#include <mynum/mynum.h>
namespace mynum
{
  namespace f
  {
    float_t arcsech(const float_t &x, const float_t &epsilon, size_t precision)
    {
      const float_t const_0 = mympf::create(0);
      const float_t const_1 = mympf::create(1);

      // 0 < x <= 1
      if ((mympf::cmp(x, const_0) <= 0) || (mympf::cmp(x, const_1) > 0))
      {
        mynum_operand_value_is_invalid_exception(
            "0 < x <= 1, x = %s", mympf::print_string(x).c_str());
      }
      const float_t const_2 = mympf::create(2);
      float_t y = mympf::add(sqrt(mympf::sub(const_1, 
                                             pow(x, const_2, epsilon, precision)), 
                                  epsilon, precision), 
                             const_1);
      y = ln(mympf::div(y, x), epsilon, precision);
      return check_result_on_precision(y, precision);
    }
  }
} // namespace mynum