#include <mynum/mynum.h>
namespace mynum
{
  namespace z
  {
    int sgn(const integer_t &x)
    {
      if (mympz::is_zero(x))
        return 0;
      return x.neg;
    }
  }

} // namespace mynum