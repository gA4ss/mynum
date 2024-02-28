#include <mynum/mynum.h>

namespace mynum
{
  number_t add(const number_t &x, const number_t &y)
  {
    std::pair<number_t, number_t> xy = same_type(x, y);
    number_t _x = xy.first, _y = xy.second, z;
    int type = _x.type();
    if (type == kNumTypeInteger)
    {
      z.set_int_value(_x.num_integer + _y.num_integer);
    }
    else if (type == kNumTypeFloat)
    {
      z.set_flt_value(_x.num_float + _y.num_float);
    }
    else if (type == kNumTypeMpz)
    {
      z.set_mpz_value(mympz::add(_x.num_mpz, _y.num_mpz));
    }
    else if (type == kNumTypeMpf)
    {
      z.set_mpf_value(mympf::add(_x.num_mpf, _y.num_mpf));
    }
    else if (type == kNumTypeFraction)
    {
      z.set_frac_value(f::add(_x.num_fraction, _y.num_fraction));
    }
    return z;
  }
} // namespace mynum