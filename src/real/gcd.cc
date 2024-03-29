#include <mynum/real.h>
#include <cmath>
#include <numeric>

namespace mynum
{

  #include "__gcd.cc"
  
  real_t gcd(const real_t &x, const real_t &y)
  {
    std::pair<real_t, real_t> xy = same_type(x, y);
    real_t _x = xy.first, _y = xy.second;

    real_t z;
    int type = _x.type();
    if (type == kRealTypeInteger)
    {
      z.set_int_value(__gcd(_x.num_integer, _y.num_integer));
    }
    else if (type == kRealTypeFloat)
    {
      z.set_int_value(__gcd(static_cast<myint_t>(_x.num_float), 
                            static_cast<myint_t>(_y.num_float)));
    }
    else if (type == kRealTypeMpz)
    {
      z.set_mpz_value(z::gcd(_x.num_mpz, _y.num_mpz));
    }
    else if (type == kRealTypeMpf)
    {
      integer_t __x = float_to_integer(_x).num_mpz, __y = float_to_integer(_y).num_mpz;
      z.set_mpz_value(z::gcd(__x, __y));
    }
    else if (type == kRealTypeFraction)
    {
      z.set_frac_value({z::gcd(_x.num_fraction.first, _y.num_fraction.first), 
                        z::gcd(_x.num_fraction.second, _y.num_fraction.second)});
    }
    return z;
  }
} // namespace mynum