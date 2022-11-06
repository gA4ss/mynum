#include <mynum/mynum.h>

namespace mynum
{
  namespace f
  {
    bool is_zero(const float_t &x)
    {
      return (mympf::ucmp(x, mympf::create(0)) == 0);
    }

    bool is_one(const float_t &x)
    {
      return (mympf::ucmp(x, mympf::create(1)) == 0);
    }

    bool diff_eps(const float_t &x, const float_t &y, const float_t &epsilon)
    {
      return (mympf::ucmp(mympf::usub(x, y), epsilon) <= 0);
    }

    // void init()
    // {
    //   mympf::init();
    //   __const_eps = mympf::create("0.0000000000000005");
    //   __pi = mympf::create("3.141592653589793238462643383279502884197169399375105820974944");
    //   __half_pi = mympf::create("1.570796326794896619231321691639751442098584699687552910487472");
    //   __e = mympf::create("2.7182818284590452353602874713527");
    //   __golden_ratio = mympf::create("0.6180339887");
    // }
  } // namespace f
} // namespace mynum
