#include <mynum/mynum.h>
#include <cmath>

namespace mynum
{
  real_t coth(const number_t &x, size_t precision)
  {
    real_t y;
    int type = x.type();
    if (type == kNumTypeInteger)
    {
      y.set_flt_value(std::cosh(x.num_integer) / std::sinh(x.num_integer));
    }
    else if (type == kNumTypeFloat)
    {
      y.set_flt_value(std::cosh(x.num_float) / std::sinh(x.num_float));
    }
    else if (type == kNumTypeMpz)
    {
      float_t fx = mympf::create(x.num_mpz, 0);
      y.set_mpf_value(f::coth(fx, precision));
    }
    else if (type == kNumTypeMpf)
    {
      y.set_mpf_value(f::coth(x.num_mpf, precision));
    }
    else if (type == kNumTypeFraction)
    {
      float_t fx = f::to_float(x.num_fraction);
      y.set_mpf_value(f::coth(fx, precision));
    }
    return y;
  }
} // namespace mynum