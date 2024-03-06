#include <mynum/real.h>
#include <cmath>

namespace mynum
{
  real_t pow(const real_t &a, const real_t &x, size_t precision)
  {
    std::pair<real_t, real_t> ax = same_type(a, x);
    real_t _a = ax.first, _x = ax.second;

    real_t y;
    int type = _a.type();
    if (type == kRealTypeInteger)
    {
      y.set_int_value(std::pow(_a.num_integer, _x.num_integer));
    }
    else if (type == kRealTypeFloat)
    {
      y.set_flt_value(std::pow(_a.num_float, _x.num_float));
    }
    else if (type == kRealTypeMpz)
    {
      float_t fa = mympf::create(_a.num_mpz, 0);
      float_t fx = mympf::create(_x.num_mpz, 0);
      y.set_mpf_value(f::pow(fa, fx, precision));
    }
    else if (type == kRealTypeMpf)
    {
      y.set_mpf_value(f::pow(_a.num_mpf, _x.num_mpf, precision));
    }
    else if (type == kRealTypeFraction)
    {
      float_t fa = f::to_float(_a.num_fraction);
      float_t fx = f::to_float(_x.num_fraction);
      y.set_mpf_value(f::pow(fa, fx, precision));
    }
    return y;
  }
} // namespace mynum