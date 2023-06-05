#include <mynum/mynum.h>

namespace mynum
{
  namespace f
  {
#if defined(ITER_IN_TH)
    extern std::vector<float_t> __bernoulli_numbers;
#endif

    float_t csch(const float_t &x, size_t precision)
    {
      //
      // 保证 0< |x| < pi
      //
      const float_t epsilon = epsilon_from_precision(precision);
      const float_t const_pi = mympf::create(kPI);
      if ((is_zero(x)) || (mympf::ucmp(x, const_pi) > 0) ||
          (diff_eps(const_pi, x, epsilon)))
      {
        mynum_operand_value_is_invalid_exception(
            "0 < |x| < PI, x = %s", mympf::print_string(x).c_str());
      }

      float_t y;
#if defined(ITER_IN_TH)
      const float_t const_0 = mympf::create(0);
      const float_t const_1 = mympf::create(1);
      size_t i = 1, j = __bernoulli_numbers.size();
      float_t p;
      float_t numerator, denominator, item, exponent = const_0, sign = mympf::create("-1");
      float_t n = const_1, k = mympf::create("-1"),
              l = mympf::create(2), o = const_1, b;
      y = mympf::div(const_1, x);
      do
      {
        p = y;
        exponent = mympf::sub(mympf::mul(n, l), o); //  2n-1
        if (i < j)
        {
          b = __bernoulli_numbers[i];
        }
        else
        {
          // 超过表大小，则重新计算。
          mynum_over_bernoulli_numbers_table_exception(
              "index \'%lu\' over the bernoulli table.", i);
        }
        item = mympf::sub(pow(l, exponent, precision), o);
        numerator = mympf::mul(l, item);
        numerator = mympf::mul(numerator, b);
        denominator = factorial(mympf::add(exponent, o));
        item = mympf::div(numerator, denominator);
        item = mympf::mul(item, pow(x, exponent, precision));
        sign = pow(k, n, precision);
        item = mympf::mul(item, sign);
        y = mympf::add(y, item);
        n = mympf::add(n, const_1);
        ++i;
      } while (!diff_eps(y, p, epsilon));
#else
      y = mympf::div(mympf::create(1), sinh(x, precision));
#endif
      return check_result_on_precision(y, precision);
    }
  }
} // namespace mynum