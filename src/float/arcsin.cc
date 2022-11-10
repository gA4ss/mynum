#include <mynum/mynum.h>
namespace mynum
{
  namespace f
  {
    float_t arcsin(const float_t &x, size_t precision)
    {
      //
      // 保证 |x| < 1
      //
      const float_t epsilon = epsilon_from_precision(precision);
      const float_t const_0 = mympf::create(0);
      const float_t const_1 = mympf::create(1);

      if (mympf::ucmp(x, const_1) >= 0)
      {
        mynum_operand_value_is_invalid_exception(
            "|x| < 1, x = %s", mympf::print_string(x).c_str());
      }

      float_t y = x, n = mympf::create(3), item = const_0, coeff = const_1, p;
      float_t numerator = mympf::create("-1"), denominator = const_0;
      const float_t const_2 = mympf::create(2);
      do
      {
        p = y;
        item = mympf::div(pow(x, n, precision), n);
        numerator = mympf::add(numerator, const_2);
        denominator = mympf::add(denominator, const_2);
        coeff = mympf::mul(coeff, div(numerator, denominator));
        item = mympf::mul(item, coeff);
        y = mympf::add(y, item);
        n = mympf::add(n, const_2);
      } while (!diff_eps(y, p, epsilon));
      return check_result_on_precision(y, precision);
    }
  }
} // namespace mynum