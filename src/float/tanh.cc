#include <mynum/mynum.h>

namespace mynum
{
  namespace f
  {
    extern std::vector<float_t> __bernoulli_numbers;

    float_t tanh(const float_t &x, size_t precision)
    {
      //
      // 保证 |x| < pi/2
      //
      const float_t epsilon = epsilon_from_precision(precision);
      const float_t const_half_pi = mympf::create(kPI_2);
      if ((mympf::ucmp(x, const_half_pi) > 0) || (diff_eps(const_half_pi, x, epsilon)))
      {
        mynum_operand_value_is_invalid_exception(
            "|x| < PI/2, x = %s", mympf::print_string(x).c_str());
      }

      const float_t const_0 = mympf::create(0);
      const float_t const_1 = mympf::create(1);
      const float_t const_2 = mympf::create(2);

      size_t i = 1, j = __bernoulli_numbers.size();
      float_t y = const_0;
      float_t numerator, denominator, item, exponent = const_0, sign = mympf::create("-1"), p;
      float_t n = const_1, k = mympf::create("-1"),
              l = const_2, o = const_1, b;
      do
      {
        p = y;
        exponent = mympf::mul(n, const_2);
        // std::cout << "exponent = " << exponent.str() << std::endl;
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
        // std::cout << "b = " << b.str() << std::endl;
        sign = pow(k, mympf::sub(n, const_1), precision);
        item = pow(l, exponent, precision);
        numerator = mympf::mul(mympf::mul(sign, item), mympf::sub(item, o));
        numerator = mympf::mul(numerator, b);
        denominator = factorial(exponent);
        item = mympf::div(numerator, denominator);
        exponent = mympf::sub(exponent, const_1);
        item = mympf::mul(item, pow(x, exponent, precision));
        y = mympf::add(y, item);
        n = mympf::add(n, const_1);
        ++i;
      } while (!diff_eps(y, p, epsilon));
      return check_result_on_precision(y, precision);
    }
  }
} // namespace mynum