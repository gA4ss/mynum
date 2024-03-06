#include <mynum/number.h>

namespace mynum
{
  number_t abs(const number_t &x)
  {
    int type = x.type();
    number_t _x;
    if (type == kNumTypeInteger)
    {
      _x.set_int_value(std::abs(x.num_integer));
    }
    else if (type == kNumTypeFloat)
    {
      _x.set_flt_value(std::abs(x.num_float));
    }
    else if (type == kNumTypeMpz)
    {
      _x.set_mpz_value(z::abs(x.num_mpz));
    }
    else if (type == kNumTypeMpf)
    {
      _x.set_mpf_value(f::abs(x.num_mpf));
    }
    else if (type == kNumTypeFraction)
    {
      _x.set_frac_value({z::abs(x.num_fraction.first), z::abs(x.num_fraction.second)});
    }
    return _x;
  }
} // namespace mynum