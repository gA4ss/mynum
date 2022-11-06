#include <mynum/mynum.h>

namespace mynum
{
  namespace f
  {
    fraction_t fraction(const float_t &x)
    {
      const integer_t const_0 = mympz::create(0);
      const integer_t const_1 = mympz::create(1);
      const integer_t const_10 = mympz::create(10);

      if (is_one(x))
        return {const_1, const_1};
      if (is_zero(x))
        return {const_0, const_1};
      if (is_integer(x))
        return {mympf::integer_part(x).number, const_1};

      //
      // 这里保证了，x的尾数部分不为0。
      //
      integer_t numerator = mympf::decimal_part(x).number;
      size_t i = x.precision;
      integer_t denominator = mympz::exp(const_10, mympz::create(i));
      integer_t g = mympz::gcd(numerator, denominator);
      numerator = mympz::idiv(numerator, g);
      denominator = mympz::idiv(denominator, g);

      integer_t y = mympf::integer_part(x).number;
      numerator = mympz::add(numerator, mympz::mul(y, denominator));
      numerator.neg = x.neg();
      return {numerator, denominator};
    }
  }
} // namespace mynum