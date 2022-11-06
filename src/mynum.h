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
    float_t exp(const float_t &x, const float_t &epsilon, size_t precision = 16);
    float_t pow(const float_t &a, const float_t &x, const float_t &epsilon, size_t precision = 16);
    float_t ln(const float_t &x, const float_t &epsilon, size_t precision = 16);
    float_t log(const float_t &base, const float_t &x, const float_t &epsilon, size_t precision = 16);
    float_t log2(const float_t &x, const float_t &epsilon, size_t precision = 16);
    float_t log10(const float_t &x, const float_t &epsilon, size_t precision = 16);
    float_t sqrt(const float_t &x, const float_t &epsilon, size_t precision = 16);
    float_t sin(const float_t &x, const float_t &epsilon, size_t precision = 16);
    float_t cos(const float_t &x, const float_t &epsilon, size_t precision = 16);
    float_t tan(const float_t &x, const float_t &epsilon, size_t precision = 16);
    float_t cot(const float_t &x, const float_t &epsilon, size_t precision = 16);
    float_t sec(const float_t &x, const float_t &epsilon, size_t precision = 16);
    float_t csc(const float_t &x, const float_t &epsilon, size_t precision = 16);
    float_t arcsin(const float_t &x, const float_t &epsilon, size_t precision = 16);
    float_t arccos(const float_t &x, const float_t &epsilon, size_t precision = 16);
    float_t arctan(const float_t &x, const float_t &epsilon, size_t precision = 16);
    float_t arccot(const float_t &x, const float_t &epsilon, size_t precision = 16);
    float_t arcsec(const float_t &x, const float_t &epsilon, size_t precision = 16);
    float_t arccsc(const float_t &x, const float_t &epsilon, size_t precision = 16);
    float_t sinh(const float_t &x, const float_t &epsilon, size_t precision = 16);
    float_t cosh(const float_t &x, const float_t &epsilon, size_t precision = 16);
    float_t tanh(const float_t &x, const float_t &epsilon, size_t precision = 16);
    float_t coth(const float_t &x, const float_t &epsilon, size_t precision = 16);
    float_t sech(const float_t &x, const float_t &epsilon, size_t precision = 16);
    float_t csch(const float_t &x, const float_t &epsilon, size_t precision = 16);
    float_t arcsinh(const float_t &x, const float_t &epsilon, size_t precision = 16);
    float_t arccosh(const float_t &x, const float_t &epsilon, size_t precision = 16);
    float_t arctanh(const float_t &x, const float_t &epsilon, size_t precision = 16);
    float_t arccoth(const float_t &x, const float_t &epsilon, size_t precision = 16);
    float_t arcsech(const float_t &x, const float_t &epsilon, size_t precision = 16);
    float_t arccsch(const float_t &x, const float_t &epsilon, size_t precision = 16);
    float_t erf(const float_t &x, const float_t &epsilon, size_t precision = 16);
    float_t erfc(const float_t &x, const float_t &epsilon, size_t precision = 16);
    int sgn(const float_t &x);
    fraction_t fraction(const float_t &x);
    NOT_IMPLEMENTED float_t gamma(const float_t &x, const float_t &epsilon, size_t precision = 16);

    float_t approximate_pi(const float_t &epsilon, size_t precision = 16);
    float_t approximate_e(const float_t &epsilon, size_t precision = 16);
    float_t approximate_golden_ratio(const float_t &epsilon, size_t precision = 16);

    // 定义EPS
    static const long double kEpsilon = DBL_EPSILON;

// 保证至少precision比epsilon的精度大1
#define precision_on_epsilon(precision, epsilon)                                       \
  {                                                                                    \
    (precision) =                                                                      \
        (precision) < (epsilon).precision * 2 ? (epsilon).precision * 2 : (precision); \
  }

// 按照精度输出结果
#define check_result_on_precision(result, precision) mympf::round((result), (precision))
  } // namespace f
} // namespace mynum

#endif // MYNUM_H_
