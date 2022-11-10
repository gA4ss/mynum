#include <mynum/mynum.h>

namespace mynum
{

  namespace f
  {
    float_t arccot(const float_t &x, size_t precision)
    {
      float_t at = arctan(x, precision);
      float_t y = mympf::sub(mympf::create(M_PI_2), at);
      return check_result_on_precision(y, precision);
    }
  }

} // namespace mynum