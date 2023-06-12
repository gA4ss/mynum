#include <mynum/mynum.h>
#include <cmath>

namespace mynum
{
  number_t exp(const number_t &x, size_t precision)
  {
    int type = x.type();
    number_t _x;
    if (type == kNumTypeInteger)
    {
      _x.set_int_value(std::exp(x.num_integer));
    }
    else if (type == kNumTypeFloat)
    {
      _x.set_flt_value(std::exp(x.num_float));
    }
    else if (type == kNumTypeMpz)
    {
      _x.set_mpf_value(f::exp(mympf::create(x.num_mpz, 0), precision));
    }
    else if (type == kNumTypeMpf)
    {
      _x.set_mpf_value(f::exp(x.num_mpf, precision));
    }
    else if (type == kNumTypeFraction)
    {
      float_t a = f::to_float(x.num_fraction);
      _x.set_mpf_value(f::exp(a, precision));
    }
    return _x;
  }
} // namespace mynum