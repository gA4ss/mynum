#include <mynum/real.h>
#include <cmath>

namespace mynum
{
  real_t tan(const real_t &x, size_t precision)
  {
    real_t y;
    int type = x.type();
    if (type == kRealTypeInteger)
    {
      y.set_flt_value(std::tan(x.num_integer));
    }
    else if (type == kRealTypeFloat)
    {
      y.set_flt_value(std::tan(x.num_float));
    }
    else if (type == kRealTypeMpz)
    {
      float_t fx = mympf::create(x.num_mpz, 0);
      y.set_mpf_value(f::tan(fx, precision));
    }
    else if (type == kRealTypeMpf)
    {
      y.set_mpf_value(f::tan(x.num_mpf, precision));
    }
    else if (type == kRealTypeFraction)
    {
      float_t fx = f::to_float(x.num_fraction);
      y.set_mpf_value(f::tan(fx, precision));
    }
    return y;
  }
} // namespace mynum