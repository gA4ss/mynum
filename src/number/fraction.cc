#include <mynum/mynum.h>

namespace mynum
{
  number_t fraction(const number_t &x)
  {
    number_t y;
    int type = x.type();
    if (type == kNumTypeInteger)
    {
      y.set_frac_value(f::fraction(static_cast<myflt_t>(x.num_integer)));
    }
    else if (type == kNumTypeFloat)
    {
      y.set_frac_value(f::fraction(x.num_float));
    }
    else if (type == kNumTypeMpz)
    {
      y.set_frac_value(f::fraction(x.num_mpz));
    }
    else if (type == kNumTypeMpf)
    {
      y.set_frac_value(f::fraction(x.num_mpf));
    }
    else if (type == kNumTypeFraction)
    {
      return x.num_fraction;
    }
    return y;
  }
} // namespace mynum
