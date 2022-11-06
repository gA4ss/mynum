#include <mynum/mynum.h>

namespace mynum
{

  namespace f
  {
    float_t sqrt(const float_t &x, const float_t &epsilon, size_t precision)
    {
      if (x.neg())
      {
        mynum_operand_value_is_invalid_exception(
            "%s", "operand must be positive.");
      }

      const float_t const_0 = mympf::create(0);
      const float_t const_1 = mympf::create(1);
      const float_t const_2 = mympf::create(2);

      if (is_zero(x))
        return const_0;
      else if (is_one(x))
        return const_1;

      float_t pre = const_0, cur = const_1, t = const_2, e = epsilon, tt;
      while (mympf::ucmp(mympf::usub(cur, pre), e) > 0)
      {
        pre = cur;
        tt = mympf::div(x, cur);
        tt = mympf::add(tt, cur);
        cur = mympf::div(tt, t);
      }
      return check_result_on_precision(cur, precision);
    }
  }

} // namespace mynum