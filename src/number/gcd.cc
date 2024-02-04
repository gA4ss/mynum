#include <mynum/mynum.h>
#include <cmath>
#include <numeric>

namespace mynum
{
  number_t gcd(const number_t &x, const number_t &y)
  {
    std::pair<number_t, number_t> xy = same_type(x, y);
    number_t _x = xy.first, _y = xy.second;

    number_t z;
    int type = _x.type();
    if (type == kNumTypeInteger)
    {
      z.set_int_value(std::__gcd(_x.num_integer, _y.num_integer));
    }
    else if (type == kNumTypeFloat)
    {
      z.set_int_value(std::__gcd(static_cast<myint_t>(_x.num_float), 
                               static_cast<myint_t>(_y.num_float)));
    }
    else if (type == kNumTypeMpz)
    {
      z.set_mpz_value(z::gcd(_x.num_mpz, _y.num_mpz));
    }
    else if (type == kNumTypeMpf)
    {
      integer_t __x = float_to_integer(_x).num_mpz, __y = float_to_integer(_y).num_mpz;
      z.set_mpz_value(z::gcd(__x, __y));
    }
    else if (type == kNumTypeFraction)
    {
      z.set_frac_value({z::gcd(_x.num_fraction.first, _y.num_fraction.first), 
                        z::gcd(_x.num_fraction.second, _y.num_fraction.second)});
    }
    return z;
  }
} // namespace mynum