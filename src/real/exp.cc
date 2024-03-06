#include <mynum/real.h>
#include <cmath>

namespace mynum
{
  real_t exp(const real_t &x, size_t precision)
  {
    int type = x.type();
    real_t _x;
    if (type == kRealTypeInteger)
    {
      _x.set_int_value(std::exp(x.num_integer));
    }
    else if (type == kRealTypeFloat)
    {
      _x.set_flt_value(std::exp(x.num_float));
    }
    else if (type == kRealTypeMpz)
    {
      _x.set_mpf_value(f::exp(mympf::create(x.num_mpz, 0), precision));
    }
    else if (type == kRealTypeMpf)
    {
      _x.set_mpf_value(f::exp(x.num_mpf, precision));
    }
    else if (type == kRealTypeFraction)
    {
      float_t a = f::to_float(x.num_fraction);
      _x.set_mpf_value(f::exp(a, precision));
    }
    return _x;
  }
} // namespace mynum