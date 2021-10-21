#include <stdlib.h>
#include <mynum/core/numeric.h>

using namespace mynum;
using namespace mynum::core;

typedef std::vector<Numeric> array_t;

// m : input maximal index requested. Must be a power of 2.
array_t test_euler_numbers(uinteger_t m) {
  array_t es = array_t(2*m+1, "0");
  es[0] = "1";

  // for (uinteger_t j = 1; j <= m; j += 2)
  //   es[j] = "0";

  Numeric sum = "0", binom = "1", item;
  for (uinteger_t n = 1; n <= m/2; n++) {
    sum = "0";
    binom = "1";
    for (uinteger_t r = 0; r < n; r++) {
      item = es[2*r];
      item *= binom;
      sum += item;

      binom *= std::to_string((2*n-2*r-1)*(n-r)).c_str();
      binom /= std::to_string((r+1)*(2*r+1)).c_str();
    }
    es[2*n] = -sum;
  }

  array_t res = array_t(m+1, "0");
  for (uinteger_t i = 0, j = 0; i <= m; i+=2, j++) {
    std::cout << "i = " << i << " " << "j = " << j << std::endl;
    std::cout << es[i].str() << std::endl;
    res[j] = es[i];
    std::cout << res[j].str() << std::endl;
  }
  return res;
}

int main() {
  array_t res = test_euler_numbers(8);
  // for (int i = 0; i <= 8; i+=2) {
  //   std::cout << res[i].str() << std::endl;
  // }
  return 0;
}

// #include <math.h>
// #include <float.h>
//
// void EulerA( int iMax, double* daEuler )
// {
//   daEuler[0] = 1.0;

//   // odd index elements
//    for( int j = 1; j <= iMax; j += 2 )
//     daEuler[j] = 0.0;

//   // recurrent relation for even index elements
//   for( int n = 1; n <= iMax/2; n++ )
//   {
//     double dSum = 0.0;
//     long lBinom = 1;            // type should be long
//                                 // for intermediate results not fail
//                                 // if sizeof(int) == 2

//     for( int r = 0; r < n; r++ )
//     {
//       double dItem = daEuler[2*r];

//       dItem *= (double)lBinom;
//       dSum += dItem;

//       // binomial coefficient calculated recurrently
//       lBinom *= (2*n-2*r-1)*(n-r);
//       lBinom /= (r+1)*(2*r+1);
//     }
//     daEuler[2*n] = -dSum;
//   }
// }

//! Calculates Euler numbers using the series expansion
// void EulerB( int iMax, double* daEuler )
// {
//   // odd index elements
//   //
//   for( int j = 1; j <= iMax; j += 2 )
//     daEuler[j] = 0.0;

//   // computer dependent value
//   // ultimate calculation accuracy
//   //
//   double eps = DBL_EPSILON;     // minimal eps such that 1.0 + eps != 1.0

//   // Euler numbers with even index
//   //
//   const double TwoByPi = 0.63661977236758134308;  // 2/Pi
//   double dCoeff = 2.0 * TwoByPi;

//   for( int n = 0; n <= iMax/2; n++ )
//   {
//     double      g1 = 1.0,               // single terms initialization
//                 g2 = 1.0;

//     for( int j = 0; j < n; j++ )
//     {
//       g1 *= 9.0;
//       g2 *= 25.0;
//     }
//     g1 *= 3.0;   // 3^(2n+1)
//     g2 *= 5.0;   // 5^(2n+1)

//     double S0 = 1.0,    // partial sums initialization
//            S1 = S0 - 1.0/g1,
//            S2 = S1 + 1.0/g2,
//            S3;

//     // Aitken transformation to speed up convergence
//     //
//     double T1 = S1 + 1.0/(g2 + g1), // transformed partial sum,
//            T2;

//     long r = 3;
//     double s = -1.0;                    // current term sign
//     int nSuccess = 0;

//     while( !nSuccess )
//     {
//       // (2r+1)^(2n+1)
//       //
//       double r2 = double(2*r+1);
//       double g3 = 1.0;

//       for( int j = 0; j < n; j++ )
//       {
//         g3 *= r2*r2;
//       }
//       g3 *= r2;

//       // next partial sum
//       //
//       S3 = S2 + s/g3;
//       T2 = S2 + s/(g3 + g2);

//       if( fabs(1.0-T1/T2) > eps )       // continue with next term
//       {
//         g2 = g3;
//         S2 = S3;
//         T1 = T2;
//         s = -s;
//         r++;
//       }
//       else                              // convergence
//         nSuccess = 1;

//     }
//     daEuler[2*n] = dCoeff * T2;
//     dCoeff *= -double((2*n+1)*(2*n+2)) * (TwoByPi * TwoByPi);
//   }
// }

//  0             1.000000             1.000000
//  2            -1.000000            -1.000000
//  4             5.000000             5.000000
//  6           -61.000000           -61.000000
//  8          1385.000000          1385.000000
// 10        -50521.000000        -50521.000000
// 12       2702765.000000       2702765.000000
// 14    -199360981.000000    -199360981.000000
// 16   19391512145.000000   19391512145.000027

// #define MAX_INDEX 16
// int main()
// {
//   double dEulerA[MAX_INDEX+1];
//   double dEulerB[MAX_INDEX+1];
 
//   // Table headings
//   printf( "%10s %20s %20s\n", "2n", "E_A(2n) (recurrent)", "E_B(2n) (series)" );
//   printf( "%8s", " " );
//   for( int i = 0; i < 52; i++ )
//     printf( "%c", '-' );
//   printf( "\n" );
 
//   // array calculation
//   Maths::NumberTheory::EulerA( MAX_INDEX, dEulerA );
//   Maths::NumberTheory::EulerB( MAX_INDEX, dEulerB );
 
//   // results output
//   for( int i = 0; i <= MAX_INDEX; i+=2 )
//     printf( "%10d %20.6f %20.6f\n", i, dEulerA[i], dEulerB[i]);
//   return 0;
// }