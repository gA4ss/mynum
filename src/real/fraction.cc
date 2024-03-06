#include <mynum/real.h>

namespace mynum
{
  real_t fraction(const real_t &x)
  {
    real_t y;
    int type = x.type();
    if (type == kRealTypeInteger)
    {
      y.set_frac_value(f::fraction(static_cast<myflt_t>(x.num_integer)));
    }
    else if (type == kRealTypeFloat)
    {
      y.set_frac_value(f::fraction(x.num_float));
    }
    else if (type == kRealTypeMpz)
    {
      y.set_frac_value(f::fraction(x.num_mpz));
    }
    else if (type == kRealTypeMpf)
    {
      y.set_frac_value(f::fraction(x.num_mpf));
    }
    else if (type == kRealTypeFraction)
    {
      return x.num_fraction;
    }
    return y;
  }
} // namespace mynum
