
#include <mynum/integer.h>

namespace mynum {

/* 求伯努利数 */
fraction_vector_t bernoulli_numbers(my::uinteger_t n) {
  Integer g, den = "1", p = "1";
  my::uinteger_t h = 0, k, i, j = 1, tog = 1;

  if (n == 0) {
    operand_value_is_invalid_exception(
      "n is not equal 0 , n = %ul", n
    );
  }

  std::vector<Integer> T = std::vector<Integer>(n, "0");
  std::vector<Integer> N = std::vector<Integer>(n, "0");
  std::vector<Integer> D = std::vector<Integer>(n, "0");

  N[0] = "1";
  D[0] = "1";

  if (n == 1) return fraction_vector_t(N, D);

  T[1] = "1";
  for (i = 3; i <= 2 * n; i++) {
    if (tog) {
      p *= "4";
      den = (p - "1") * "2";

      for (k = h++; k > 0; k--)
        T[k] += T[k + 1];
    } else {
      for (k = 1; k <= h; k++)
        T[k] += T[k - 1];
      
      g = gcd(T[h], den);
      N[j] = T[h] / g;
      D[j] = den / g;
      j++;
    }
    tog = 1 - tog;
  }

  return fraction_vector_t(N, D);
}

} // namespae mynum