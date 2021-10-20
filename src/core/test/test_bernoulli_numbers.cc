#include <stdlib.h>
#include <mynum/core/numeric.h>

using namespace mynum::core;

typedef std::pair<std::vector<Numeric>, std::vector<Numeric> > fraction_vector_t;

fraction_vector_t test_bernoulli_numbers(int n) {
  Numeric g, den = "1", p = "1";
  long h = 0, k, i, j = 1, tog = 1;

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