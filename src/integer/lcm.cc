#include <mynum/mynum.h>

namespace mynum
{
  namespace z
  {
    integer_t lcm(const integer_t &x, const integer_t &y)
    {
      integer_t z;
      integer_t g = z::gcd(x, y);
      z = mympz::mul(x, y);
      z = mympz::idiv(z, g);
      return z;
    }
  }

} // namespace mynum