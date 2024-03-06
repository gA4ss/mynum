#include <mynum/real.h>
#include <cmath>

namespace mynum
{
  real_t abs(const real_t &x)
  {
    int type = x.type();
    real_t _x;
    if (type == kRealTypeInteger)
    {
      _x.set_int_value(std::abs(x.num_integer));
    }
    else if (type == kRealTypeFloat)
    {
      _x.set_flt_value(std::abs(x.num_float));
    }
    else if (type == kRealTypeMpz)
    {
      _x.set_mpz_value(z::abs(x.num_mpz));
    }
    else if (type == kRealTypeMpf)
    {
      _x.set_mpf_value(f::abs(x.num_mpf));
    }
    else if (type == kRealTypeFraction)
    {
      _x.set_frac_value({z::abs(x.num_fraction.first), z::abs(x.num_fraction.second)});
    }
    return _x;
  }
} // namespace mynum