#include <stdlib.h>
#include <mynum/core/numeric.h>

using namespace mynum;
using namespace mynum::core;

typedef std::pair<std::vector<Numeric>, std::vector<Numeric> > fraction_vector_t;

fraction_vector_t test_bernoulli_numbers(uinteger_t n) {
  Numeric g, den = "1", p = "1";
  uinteger_t h = 0, k, i, j = 1, tog = 1;

  if (n == 0) { ; }

  std::vector<Numeric> T = std::vector<Numeric>(n, "0");
  std::vector<Numeric> N = std::vector<Numeric>(n, "0");
  std::vector<Numeric> D = std::vector<Numeric>(n, "0");

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

int main(void) {
  fraction_vector_t b;
  b = test_bernoulli_numbers(20);
  for (int i = 0; i < 20; i++)
    std::cout << b.first[i].str() << " / " << b.second[i].str() << std::endl;
  return 0;
}

// Numeric bernoulli_numbers(const Numeric& x) {
//   Numeric k = integer(x), _x = integer(x);
//   Numeric b = "0";
//   if (is_zero(_x)) {
//     return "1";
//   }

//   if ((_x > "1") && is_odd(_x)) {
//     return "0";
//   }

//   Numeric numerator = "0", denominator = "0", item = "0";
//   while(!is_zero(k)) {
//     k--;
//     numerator = factorial(_x) * bernoulli_numbers(k);
//     denominator = factorial(_x - k) * factorial(k) * (_x - k + "1");
//     item = div(numerator, denominator);
//     b += (item * "-1");
//   }
//   return b;
// }