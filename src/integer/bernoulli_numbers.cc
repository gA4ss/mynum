#include <mynum/mynum.h>

namespace mynum
{

  namespace z
  {
    /* 求伯努利数 */
    fraction_vector_t bernoulli_numbers(size_t n)
    {
      // mynum_dbgprint_fmt("generate \'%lu\' bernoulli numbers.\n", n);
      const integer_t const_0 = mympz::create(0);
      const integer_t const_1 = mympz::create(1);
      const integer_t const_2 = mympz::create(2);
      const integer_t const_4 = mympz::create(4);

      integer_t g, den = const_1, p = const_1;
      size_t h = 0, k, i, j = 1, tog = 1;

      if (n == 0)
      {
        mynum_operand_value_is_invalid_exception(
            "n is not equal 0 , n = %ul", n);
      }

      std::vector<integer_t> T = std::vector<integer_t>(n, const_0);
      std::vector<integer_t> N = std::vector<integer_t>(n, const_0);
      std::vector<integer_t> D = std::vector<integer_t>(n, const_0);

      N[0] = const_1;
      D[0] = const_1;

      if (n == 1)
        return fraction_vector_t(N, D);

      T[1] = const_1;
      for (i = 3; i <= 2 * n; i++)
      {
        if (tog)
        {
          p = mympz::mul(p, const_4);
          den = mympz::mul(mympz::sub(p, const_1), const_2);

          // mynum_dbgprint_fmt("p = %s.\n", mympz::print_string(p).c_str());
          // mynum_dbgprint_fmt("den = %s.\n", mympz::print_string(den).c_str());

          for (k = h++; k > 0; k--)
            T[k] = mympz::add(T[k], T[k + 1]);
        }
        else
        {
          for (k = 1; k <= h; k++)
            T[k] = mympz::add(T[k], T[k - 1]);

          g = mympz::gcd(T[h], den);
          // mynum_dbgprint_fmt("T[%lu] = %s.\n", h, mympz::print_string(T[h]).c_str());
          // mynum_dbgprint_fmt("den = %s.\n", mympz::print_string(den).c_str());
          // mynum_dbgprint_fmt("g = %s.\n", mympz::print_string(g).c_str());
          N[j] = mympz::idiv(T[h], g);
          // mynum_dbgprint_fmt("N[%lu] = %s.\n", j, mympz::print_string(N[j]).c_str());
          D[j] = mympz::idiv(den, g);
          // mynum_dbgprint_fmt("D[%lu] = %s.\n", j, mympz::print_string(D[j]).c_str());
          j++;
        }
        tog = 1 - tog;
      }

      return fraction_vector_t(N, D);
    }
  }
} // namespae mynum