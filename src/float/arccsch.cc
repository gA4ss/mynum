#include <mynum/mynum.h>
namespace mynum
{
  namespace f
  {
    float_t arccsch(const float_t &x, const float_t &epsilon, size_t precision)
    {
      // x != 0
      if (is_zero(x))
      {
        mynum_operand_value_is_invalid_exception(
            "x != 0, x = %s", mympf::print_string(x).c_str());
      }

      const float_t const_1 = mympf::create(1);
      const float_t const_2 = mympf::create(2);
      float_t y = sqrt(mympf::add(mympf::div(const_1, pow(x, const_2, epsilon, precision)), const_1), 
                       epsilon, precision);
      y = ln(mympf::add(mympf::div(const_1, x), y), epsilon, precision);
      return check_result_on_precision(y, precision);
    }
  }
} // namespace mynum