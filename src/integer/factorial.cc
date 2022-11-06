#include <mynum/mynum.h>

namespace mynum
{
  namespace z
  {
    integer_t factorial(const integer_t &x)
    {
      const integer_t const_1 = mympz::create(1);
      if (x.neg)
        mynum_operand_value_is_invalid_exception("%s", "x is negative");
      if (mympz::is_zero(x) || mympz::is_one(x))
        return const_1;

      integer_t t = x, y = const_1;
      while (mympz::ucmp(t, const_1))
      {
        y = mympz::mul(y, t);
        t = mympz::usub(t, const_1);
      }
      return y;
    }
  }

} // namespace mynum