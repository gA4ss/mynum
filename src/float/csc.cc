#include <mynum/mynum.h>

namespace mynum
{

  namespace f
  {
#if defined(ITER_IN_TH)
    extern std::vector<float_t> __bernoulli_numbers;
#endif

    float_t csc(const float_t &x, size_t precision)
    {
      //
      // 保证 0< |x| < pi
      //
      const float_t epsilon = epsilon_from_precision(precision);
      const float_t const_pi = mympf::create(kPI_2);
      if ((is_zero(x)) || (mympf::ucmp(x, const_pi) > 0) || (diff_eps(const_pi, x, epsilon)))
      {
        mynum_operand_value_is_invalid_exception(
            "0 < x < PI, x = %s", mympf::print_string(x).c_str());
      }

      float_t y;
#if defined(ITER_IN_TH)
      const float_t const_1 = mympf::create(1);
      const float_t const_0 = mympf::create(0);
      size_t i = 1, j = __bernoulli_numbers.size();
      float_t numerator, denominator, item, exponent = const_0;
      float_t n = const_1, b, p;
      const float_t const_2 = mympf::create(2, 0);
      y = mympf::div(const_1, x);
      do
      {
        p = y;
        exponent = mympf::mul(exponent, const_2);
        denominator = factorial(exponent);
        exponent = mympf::sub(exponent, const_1); // 2n-1
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
        numerator = mympf::mul(const_2, mympf::sub(pow(const_2, exponent, precision),
                                                   const_1));
        numerator = mympf::mul(numerator, b);
        item = mympf::div(numerator, denominator);
        item = mympf::mul(item, pow(x, exponent, precision));
        y = mympf::add(y, item);
        n = mympf::add(n, const_1);
        ++i;
      } while (!diff_eps(y, p, epsilon));
#else
      y = mympf::div(mympf::create(1), cos(x, precision));
#endif
      return check_result_on_precision(y, precision);
    }
  }

} // namespace mynum