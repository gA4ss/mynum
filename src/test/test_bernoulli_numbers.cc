#include <stdlib.h>
#include <mynum/integer.h>

using namespace mynum;

typedef std::pair<std::vector<Integer>, std::vector<Integer> > fraction_vector_t;
fraction_vector_t test_bernoulli_numbers(my::uinteger_t n) {
  Integer g, den = "1", p = "1";
  my::uinteger_t h = 0, k, i, j = 1, tog = 1;

  if (n == 0) { ; }

  std::vector<Integer> T = std::vector<Integer>(n, "0");
  std::vector<Integer> N = std::vector<Integer>(n, "0");
  std::vector<Integer> D = std::vector<Integer>(n, "0");

  N[0] = "1";
  D[0] = "1";

  if (n == 1) return fraction_vector_t(N, D);

  T[1] = "1";
  for (i = 3; i <= 2 * n; i++) {
    // std::cout << "i = " << i << std::endl;
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
      // std::cout << "N = " << N[j].str() << " D = " << D[j].str() 
      //           << std::endl << std::endl;
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

// Integer bernoulli_numbers(const Integer& x) {
//   Integer k = integer(x), _x = integer(x);
//   Integer b = "0";
//   if (is_zero(_x)) {
//     return "1";
//   }

//   if ((_x > "1") && is_odd(_x)) {
//     return "0";
//   }

//   Integer numerator = "0", denominator = "0", item = "0";
//   while(!is_zero(k)) {
//     k--;
//     numerator = factorial(_x) * bernoulli_numbers(k);
//     denominator = factorial(_x - k) * factorial(k) * (_x - k + "1");
//     item = div(numerator, denominator);
//     b += (item * "-1");
//   }
//   return b;
// }