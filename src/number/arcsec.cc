#include <mynum/mynum.h>
#include <cmath>

namespace mynum
{
  number_t arcsec(const number_t &x, size_t precision)
  {
    number_t y;
    int type = x.type();
    if (type == kNumTypeInteger)
    {
      y.set_flt_value(std::acos(1 / x.num_integer));
    }
    else if (type == kNumTypeFloat)
    {
      y.set_flt_value(std::acos(1 / x.num_float));
    }
    else if (type == kNumTypeMpz)
    {
      float_t fx = mympf::create(x.num_mpz, 0);
      y.set_mpf_value(f::arcsec(fx, precision));
    }
    else if (type == kNumTypeMpf)
    {
      y.set_mpf_value(f::arcsec(x.num_mpf, precision));
    }
    else if (type == kNumTypeFraction)
    {
      float_t fx = f::to_float(x.num_fraction);
      y.set_mpf_value(f::arcsec(fx, precision));
    }
    return y;
  }
} // namespace mynum