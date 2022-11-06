#include <mynum/mynum.h>
namespace mynum
{
  namespace f
  {
    int sgn(const float_t &x)
    {
      if (is_zero(x))
        return 0;
      return x.neg();
    }
  }

} // namespace mynum