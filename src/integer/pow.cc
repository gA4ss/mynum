#include <mynum/mynum.h>

namespace mynum
{
  namespace z
  {
    integer_t pow(const integer_t &x, const integer_t &e)
    {
      return mympz::exp(x, e);
    }
  }

} // namespace mynum