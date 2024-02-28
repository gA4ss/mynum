#include <mynum/mynum.h>
#include <cmath>

namespace mynum
{
  real_t ln(const number_t &x, size_t precision)
  {
    real_t y;
    int type = x.type();
    if (type == kNumTypeInteger)
    {
      y.set_int_value(std::log(x.num_integer));
    }
    else if (type == kNumTypeFloat)
    {
      y.set_flt_value(std::log(x.num_float));
    }
    else if (type == kNumTypeMpz)
    {
      float_t _x = mympf::create(x.num_mpz, 0);
      y.set_mpf_value(f::ln(_x, precision));
    }
    else if (type == kNumTypeMpf)
    {
      y.set_mpf_value(f::ln(x.num_mpf, precision));
    }
    else if (type == kNumTypeFraction)
    {
      float_t fx = f::to_float(x.num_fraction);
      y.set_mpf_value(f::ln(fx, precision));
    }
    return y;
  }
} // namespace mynum