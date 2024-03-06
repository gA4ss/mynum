#include <mynum/real.h>
#include <cmath>

namespace mynum
{
  real_t log(const real_t &a, const real_t &x, size_t precision)
  {
    std::pair<real_t, real_t> ax = same_type(a, x);
    real_t _a = ax.first, _x = ax.second;

    real_t y;
    int type = _a.type();
    if (type == kRealTypeInteger)
    {
      myflt_t n = std::log(_x.num_integer);
      myflt_t d = std::log(_a.num_integer);
      y.set_flt_value(n / d);
    }
    else if (type == kRealTypeFloat)
    {
      myflt_t n = std::log(_x.num_float);
      myflt_t d = std::log(_a.num_float);
      y.set_flt_value(n / d);
    }
    else if (type == kRealTypeMpz)
    {
      float_t fa = mympf::create(_a.num_mpz, 0);
      float_t fx = mympf::create(_x.num_mpz, 0);
      y.set_mpf_value(f::log(fa, fx, precision));
    }
    else if (type == kRealTypeMpf)
    {
      y.set_mpf_value(f::log(_a.num_mpf, _x.num_mpf, precision));
    }
    else if (type == kRealTypeFraction)
    {
      float_t fa = f::to_float(_a.num_fraction);
      float_t fx = f::to_float(_x.num_fraction);
      y.set_mpf_value(f::log(fa, fx, precision));
    }
    return y;
  }
} // namespace mynum