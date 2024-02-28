#include <mynum/mynum.h>
#include <cmath>
#include <numeric>

namespace mynum
{

  #include "__gcd.cc"

  static inline myint_t __lcm(myint_t x, myint_t y)
  {
    return (x * y) / __gcd(x, y);
  }

  real_t lcm(const number_t &x, const number_t &y)
  {
    std::pair<real_t, number_t> xy = same_type(x, y);
    real_t _x = xy.first, _y = xy.second;

    real_t z;
    int type = _x.type();
    if (type == kNumTypeInteger)
    {
      z.set_int_value(__lcm(_x.num_integer, _y.num_integer));
    }
    else if (type == kNumTypeFloat)
    {
      z.set_int_value(__lcm(static_cast<myint_t>(_x.num_float),
                            static_cast<myint_t>(_y.num_float)));
    }
    else if (type == kNumTypeMpz)
    {
      z.set_mpz_value(z::lcm(_x.num_mpz, _y.num_mpz));
    }
    else if (type == kNumTypeMpf)
    {
      integer_t __x = float_to_integer(_x).num_mpz, __y = float_to_integer(_y).num_mpz;
      z.set_mpz_value(z::lcm(__x, __y));
    }
    else if (type == kNumTypeFraction)
    {
      z.set_frac_value({z::lcm(_x.num_fraction.first, _y.num_fraction.first),
                        z::lcm(_x.num_fraction.second, _y.num_fraction.second)});
    }
    return z;
  }
} // namespace mynum