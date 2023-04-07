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
        return {mympf::integer_part(x).number, const_1};
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
      y.neg = 0;  // 这里将符号位清除
      numerator = mympz::add(numerator, mympz::mul(y, denominator));
      numerator.neg = x.neg();
      return {numerator, denominator};
    }

    fraction_t reduction(const fraction_t &x)
    {
      integer_t xn = x.first, xd = x.second;
      integer_t g = z::gcd(xn, xd);
      if (mympz::cmp(g, mympz::create(1)) == 0)
        return x;
      return {mympz::div(xn, g).first, mympz::div(xd, g).first};
    }

    std::pair<fraction_t, fraction_t> common_denominator(const fraction_t &x, const fraction_t &y)
    {
      fraction_t _x = reduction(x);
      fraction_t _y = reduction(y);

      integer_t xn = _x.first, xd = _x.second;
      integer_t yn = _y.first, yd = _y.second;

      // 相等则退出
      if (mympz::cmp(xd, yd) == 0)
        return {_x, _y};

      integer_t l = z::lcm(xd, yd);
      integer_t xk = mympz::div(l, xd).first, yk = mympz::div(l, yd).first;
      xn = mympz::mul(xn, xk);
      yn = mympz::mul(yn, yk);
      return {{xn, l}, {yn,l}};
    }

    fraction_t add(const fraction_t &x, const fraction_t &y)
    {
      std::pair<fraction_t, fraction_t> xy = common_denominator(x, y);
      fraction_t _x = xy.first, _y = xy.second;
      integer_t n = mympz::add(_x.first, _y.first);
      fraction_t z = {n, _x.second};
      return reduction(z);
    }

    fraction_t sub(const fraction_t &x, const fraction_t &y)
    {
      std::pair<fraction_t, fraction_t> xy = common_denominator(x, y);
      fraction_t _x = xy.first, _y = xy.second;
      integer_t n = mympz::sub(_x.first, _y.first);
      fraction_t z = {n, _x.second};
      return reduction(z);
    }

    fraction_t mul(const fraction_t &x, const fraction_t &y)
    {
      integer_t xn = x.first, xd = x.second;
      integer_t yn = y.first, yd = y.second;
      integer_t zn = mympz::mul(xn, yn);
      integer_t zd = mympz::mul(xd, yd);
      zn.neg = zn.neg == zd.neg ? 0 : 1;
      zd.neg = 0;
      fraction_t z = {zn, zd};
      return reduction(z);
    }

    fraction_t div(const fraction_t &x, const fraction_t &y)
    {
      integer_t xn = x.first, xd = x.second;
      integer_t yn = y.first, yd = y.second;
      integer_t zn = mympz::mul(xn, yd);
      integer_t zd = mympz::mul(xd, yn);
      zn.neg = zn.neg == zd.neg ? 0 : 1;
      zd.neg = 0;
      fraction_t z = {zn, zd};
      return reduction(z);
    }
  }
} // namespace mynum