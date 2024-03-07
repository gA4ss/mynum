#include <mynum/number.h>

namespace mynum
{
  number_t abs(const number_t &x)
  {
    return test(x, kNumTypeReal) ? number_t(abs(x.real)) : number_t(abs(x.complex));
  }
} // namespace mynum