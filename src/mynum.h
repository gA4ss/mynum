#ifndef MYNUM_H_
#define MYNUM_H_

#include <cmath>
#include <cfloat>
#include <algorithm>
#include <sstream>
#include <iostream>

#include <mympz/mympz.h>
#include <mympf/mympf.h>
#include <mynum/compile.h>
#include <mynum/exception.h>
#include <mynum/debug.h>

namespace mynum
{
  typedef mympf::float_t float_t;
  typedef mympz::bignum_t integer_t;

  typedef std::pair<integer_t, integer_t> fraction_t;
  typedef std::pair<std::vector<integer_t>, std::vector<integer_t>> fraction_vector_t;
  typedef std::vector<integer_t> int_array_t;

#define is_float(x) mympf::ucmp(mympf::decimal_part((x)), mympf::create(0))
#define is_integer(x) (mympf::ucmp(mympf::decimal_part((x)), mympf::create(0)) == 0)

  namespace z
  {
    integer_t abs(const integer_t &x);
    fraction_vector_t bernoulli_numbers(size_t n);
    int_array_t euler_numbers(size_t m);
    std::pair<integer_t, integer_t> extended_euclidean(const integer_t &x, const integer_t &y);

    int sgn(const integer_t &x);
    integer_t factorial(const integer_t &x);
    integer_t pow(const integer_t &x, const integer_t &e);
    integer_t lcm(const integer_t &x, const integer_t &y);
    integer_t gcd(const integer_t &x, const integer_t &y);
    integer_t not_bits(const integer_t &x);
    integer_t and_bits(const integer_t &x, const integer_t &y);
    integer_t or_bits(const integer_t &x, const integer_t &y);
    integer_t xor_bits(const integer_t &x, const integer_t &y);
    integer_t lshift_bits(const integer_t &x, size_t n);
    integer_t rshift_bits(const integer_t &x, size_t n);
  } // namespace z

  namespace f
  {
    bool is_zero(const float_t &x);
    bool is_one(const float_t &x);
    bool diff_eps(const float_t &x, const float_t &y, const float_t &epsilon);

    float_t abs(const float_t &x);
    float_t ceil(const float_t &x);
    float_t floor(const float_t &x);
    float_t round(const float_t &x);
    float_t factorial(const float_t &x);
    float_t exp(const float_t &x, size_t precision = 16);
    float_t pow(const float_t &a, const float_t &x, size_t precision = 16);
    float_t ln(const float_t &x, size_t precision = 16);
    float_t log(const float_t &base, const float_t &x, size_t precision = 16);
    float_t log2(const float_t &x, size_t precision = 16);
    float_t log10(const float_t &x, size_t precision = 16);
    float_t sqrt(const float_t &x, size_t precision = 16);
    float_t sin(const float_t &x, size_t precision = 16);
    float_t cos(const float_t &x, size_t precision = 16);
    float_t tan(const float_t &x, size_t precision = 16);
    float_t cot(const float_t &x, size_t precision = 16);
    float_t sec(const float_t &x, size_t precision = 16);
    float_t csc(const float_t &x, size_t precision = 16);
    float_t arcsin(const float_t &x, size_t precision = 16);
    float_t arccos(const float_t &x, size_t precision = 16);
    float_t arctan(const float_t &x, size_t precision = 16);
    float_t arccot(const float_t &x, size_t precision = 16);
    float_t arcsec(const float_t &x, size_t precision = 16);
    float_t arccsc(const float_t &x, size_t precision = 16);
    float_t sinh(const float_t &x, size_t precision = 16);
    float_t cosh(const float_t &x, size_t precision = 16);
    float_t tanh(const float_t &x, size_t precision = 16);
    float_t coth(const float_t &x, size_t precision = 16);
    float_t sech(const float_t &x, size_t precision = 16);
    float_t csch(const float_t &x, size_t precision = 16);
    float_t arcsinh(const float_t &x, size_t precision = 16);
    float_t arccosh(const float_t &x, size_t precision = 16);
    float_t arctanh(const float_t &x, size_t precision = 16);
    float_t arccoth(const float_t &x, size_t precision = 16);
    float_t arcsech(const float_t &x, size_t precision = 16);
    float_t arccsch(const float_t &x, size_t precision = 16);
    float_t erf(const float_t &x, size_t precision = 16);
    float_t erfc(const float_t &x, size_t precision = 16);
    int sgn(const float_t &x);
    fraction_t fraction(const float_t &x);
    fraction_t reduction(const fraction_t &x);
    std::pair<fraction_t, fraction_t> common_denominator(const fraction_t &x, const fraction_t &y);
    fraction_t add(const fraction_t &x, const fraction_t &y);
    fraction_t sub(const fraction_t &x, const fraction_t &y);
    fraction_t mul(const fraction_t &x, const fraction_t &y);
    fraction_t div(const fraction_t &x, const fraction_t &y);
    float_t gamma(const float_t &x, size_t precision = 16);

    float_t approximate_pi(size_t precision = 16);
    float_t approximate_e(size_t precision = 16);
    float_t approximate_golden_ratio(size_t precision = 16);

// 定义EPS
#define kEpsilon DBL_EPSILON
#define kPI "3.141592653589793238462643383279502884"
#define kPI_2 "1.570796326794896619231321691639751442"
#define kPI_4 "0.785398163397448309615660845819875721"

    // # define M_Ef128	__f128 (2.718281828459045235360287471352662498) /* e */
    // # define M_LOG2Ef128	__f128 (1.442695040888963407359924681001892137) /* log_2 e */
    // # define M_LOG10Ef128	__f128 (0.434294481903251827651128918916605082) /* log_10 e */
    // # define M_LN2f128	__f128 (0.693147180559945309417232121458176568) /* log_e 2 */
    // # define M_LN10f128	__f128 (2.302585092994045684017991454684364208) /* log_e 10 */
    // # define M_PIf128	__f128 (3.141592653589793238462643383279502884) /* pi */
    // # define M_PI_2f128	__f128 (1.570796326794896619231321691639751442) /* pi/2 */
    // # define M_PI_4f128	__f128 (0.785398163397448309615660845819875721) /* pi/4 */
    // # define M_1_PIf128	__f128 (0.318309886183790671537767526745028724) /* 1/pi */
    // # define M_2_PIf128	__f128 (0.636619772367581343075535053490057448) /* 2/pi */
    // # define M_2_SQRTPIf128	__f128 (1.128379167095512573896158903121545172) /* 2/sqrt(pi) */
    // # define M_SQRT2f128	__f128 (1.414213562373095048801688724209698079) /* sqrt(2) */
    // # define M_SQRT1_2f128	__f128 (0.707106781186547524400844362104849039) /* 1/sqrt(2) */

#define epsilon_from_precision(precision) mympf::create(1, precision + 1)                // 从precision生成epsilon
#define check_result_on_precision(result, precision) mympf::round((result), (precision)) // 按照精度输出结果
  }                                                                                      // namespace f
} // namespace mynum

#endif // MYNUM_H_
