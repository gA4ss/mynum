#include <mynum/mynum.h>
namespace mynum
{

  namespace f
  {
    float_t factorial(const float_t &x)
    {
      if (x.neg())
        mynum_operand_value_is_invalid_exception("%s", "x is negative");
      if (is_zero(x) || is_one(x))
        return mympf::create(1);
      integer_t a = mympf::integer_part(x).number;
      float_t b = mympf::create(1);

      const integer_t const_1 = mympz::create(1);
      while (mympz::ucmp(a, const_1)) // a != 1
      {
        b.number = mympz::mul(b.number, a);
        a = mympz::sub(a, const_1);
      }
      return b;
    }
  }

} // namespace mynum