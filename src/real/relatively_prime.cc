#include <mynum/mynum.h>
#include <cmath>
#include <numeric>

namespace mynum
{
  bool relatively_prime(const real_t &x, const number_t &y)
  {
    real_t d = gcd(x, y);
    bool rp = false;

    int type = d.type();
    if (type == kNumTypeInteger)
    {
      rp = (d.num_integer == 1 ? true : false);
    }
    else if (type == kNumTypeMpz)
    {
      rp = (mympz::cmp(d.num_mpz, mympz::create(1)) == 0 ? true : false);
    }
    else if (type == kNumTypeFraction)
    {
      rp = false;
    }
    return rp;
  }
} // namespace mynum