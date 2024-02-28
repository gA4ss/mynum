#include <mynum/mynum.h>

namespace mynum
{
  number_t mod(const number_t &x, const number_t &y)
  {
    std::pair<number_t, number_t> xy = same_type(x, y);
    number_t _x = xy.first, _y = xy.second, z;
    int type = _x.type();
    if (type == kNumTypeInteger)
    {
      z.set_int_value(_x.num_integer % _y.num_integer);
    }
    else if (type == kNumTypeFloat)
    {
      myint_t r = static_cast<myint_t>(_x.num_float) % static_cast<myint_t>(_y.num_float);
      z.set_flt_value(static_cast<myflt_t>(r));
    }
    else if (type == kNumTypeMpz)
    {
      z.set_mpz_value(mympz::mod(_x.num_mpz, _y.num_mpz));
    }
    else if (type == kNumTypeMpf)
    {
      z.set_mpf_value(mympf::mod(_x.num_mpf, _y.num_mpf));
    }
    else if (type == kNumTypeFraction)
    {
      z.set_frac_value(f::mod(_x.num_fraction, _y.num_fraction));
    }
    return z;
  }
} // namespace mynum