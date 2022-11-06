#include <mynum/mynum.h>

namespace mynum
{
  namespace f
  {

    // static float_t __create_const(std::string v)
    // {
    //   mympf::init();
    //   return mympf::create(v);
    // }

    // float_t __const_eps = __create_const("0.0000000000000005");
    // float_t __pi = __create_const("3.141592653589793238462643383279502884197169399375105820974944");
    // float_t __half_pi = __create_const("1.570796326794896619231321691639751442098584699687552910487472");
    // float_t __e = __create_const("2.7182818284590452353602874713527");
    // float_t __golden_ratio = __create_const("0.6180339887");

    float_t approximate_pi(const float_t &epsilon, size_t precision)
    {
      // 莱布尼兹公式
      // 这TMD的是最慢的近似方法了吧，极慢。
      const float_t const_0 = mympf::create(0);
      const float_t const_1 = mympf::create(1);
      float_t y = const_0, n = mympf::create(3), 
              o = const_1, t = mympf::create(2), item, p;
      const float_t const_4 = mympf::create(4);
      size_t i = 2;
      do
      {
        p = y;
        item = mympf::div(o, n);
        if (i % 2 == 0)
          item.set_neg(1);
        y = mympf::add(y, item);
        n = mympf::add(n, t);
        ++i;
      } while (!diff_eps(y, p, epsilon));
      y = mympf::add(y, const_1);
      y = mympf::mul(y, const_4);
      return check_result_on_precision(y, precision);
    }

    float_t approximate_e(const float_t &epsilon, size_t precision)
    {
      float_t y = f::exp(mympf::create(1), epsilon, precision);
      return check_result_on_precision(y, precision);
    }

    float_t approximate_golden_ratio(const float_t &epsilon, size_t precision)
    {
      const float_t const_1 = mympf::create(1);
      const float_t const_2 = mympf::create(2);
      const float_t const_5 = mympf::create(5);
      float_t y = mympf::div(mympf::sub(sqrt(const_5, epsilon, precision), const_1), const_2);
      return check_result_on_precision(y, precision);
    }
  }
} // namespace mynum