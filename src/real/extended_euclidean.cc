#include <mynum/mynum.h>
#include <cmath>
#include <numeric>

namespace mynum
{
  static myint_t __extended_euclidean(myint_t x, myint_t y, myint_t &s, myint_t &t)
  {
    if (y == 0)
    {
      s = 1, t = 0;
      return x;
    }

    myint_t d = __extended_euclidean(y, x % y, t, s);
    t -= x / y * s;
    return d;
  }

  real_t extended_euclidean(const number_t &x, const number_t &y,
                              real_t &s, number_t &t)
  {
    std::pair<real_t, number_t> xy = same_type(x, y);
    real_t _x = xy.first, _y = xy.second;

    real_t d;
    int type = _x.type();
    if (type == kNumTypeInteger)
    {
      myint_t _s = 0, _t = 0;
      myint_t _d = __extended_euclidean(_x.num_integer, _y.num_integer, _s, _t);
      s.set_int_value(_s);
      t.set_int_value(_t);
      d.set_int_value(_d);
    }
    else if (type == kNumTypeFloat)
    {
      myint_t _s = 0, _t = 0;
      myint_t _d = __extended_euclidean(static_cast<myint_t>(_x.num_float), 
                                        static_cast<myint_t>(_y.num_float), 
                                        _s, _t);
      s.set_int_value(_s);
      t.set_int_value(_t);
      d.set_int_value(_d);
    }
    else if (type == kNumTypeMpz)
    {
      std::pair<integer_t, integer_t> st = z::extended_euclidean(_x.num_mpz, _y.num_mpz);
      s.set_mpz_value(st.first);
      t.set_mpz_value(st.second);
      d.set_mpz_value(z::gcd(_x.num_mpz, _y.num_mpz));
    }
    else if (type == kNumTypeMpf)
    {
      integer_t __x = float_to_integer(_x).num_mpz, __y = float_to_integer(_y).num_mpz;
      std::pair<integer_t, integer_t> st = z::extended_euclidean(__x, __y);
      s.set_mpz_value(st.first);
      t.set_mpz_value(st.second);
      d.set_mpz_value(z::gcd(__x, __y));
    }
    else if (type == kNumTypeFraction)
    {
      // 首先通分
      std::pair<fraction_t, fraction_t> __xy = f::common_denominator(_x.num_fraction, _y.num_fraction);
      // 这里 __xy.first.second 与 __xy.second.second 应该相同。
      integer_t den = __xy.first.second;
      integer_t a = __xy.first.first, b = __xy.second.first;

      std::pair<integer_t, integer_t> _st = z::extended_euclidean(a, b);
      integer_t _d = z::gcd(a, b);
      s.set_frac_value(f::fraction(_st.first, den));
      t.set_frac_value(f::fraction(_st.second, den));
      d.set_frac_value(f::fraction(_d, den));
    }
    return d;
  }
} // namespace mynum