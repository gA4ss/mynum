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
  typedef int64_t myint_t;
  typedef long double myflt_t;

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
    fraction_t fraction(const myflt_t x);
    fraction_t fraction(const integer_t &x);
    fraction_t fraction(const integer_t &x, const integer_t &y);
    fraction_t fraction(const float_t &x);
    fraction_t reduction(const fraction_t &x);
    std::pair<fraction_t, fraction_t> common_denominator(const fraction_t &x, const fraction_t &y);
    fraction_t add(const fraction_t &x, const fraction_t &y);
    fraction_t sub(const fraction_t &x, const fraction_t &y);
    fraction_t mul(const fraction_t &x, const fraction_t &y);
    fraction_t div(const fraction_t &x, const fraction_t &y);
    fraction_t mod(const fraction_t &x, const fraction_t &y, size_t precision = 16);
    float_t to_float(const fraction_t &x, size_t precision = 16);
    int sgn(const fraction_t &x);
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

  //
  // 定义Number
#define kNumTypeNone 0
#define kNumTypeInteger 1
#define kNumTypeFloat 2
#define kNumTypeMpz 3
#define kNumTypeMpf 4
#define kNumTypeFraction 5

  typedef struct __number_t
  {
    __number_t();
    __number_t(std::string n);
    __number_t(myflt_t n);
    __number_t(integer_t n);
    __number_t(float_t n);
    __number_t(fraction_t n);

    std::string value() const;
    std::string value();
    int type() const;
    int type();

    void set_str_value(std::string n, bool use_bignum = false);
    void set_int_value(myint_t n);
    void set_flt_value(myflt_t n);
    void set_mpz_value(integer_t n);
    void set_mpf_value(float_t n);
    void set_frac_value(fraction_t n);

    //
    // 当前保存的类型
    //
    int __type;

    //
    // 所存储的类型
    //
    myint_t num_integer;
    myflt_t num_float;
    integer_t num_mpz;
    float_t num_mpf;
    fraction_t num_fraction;
  } number_t;

  bool test(const number_t &x, int type);
  number_t covert_to(const number_t &x, int type);
  number_t integer_to_float(const number_t &x);
  number_t float_to_integer(const number_t &x);
  std::pair<number_t, number_t> same_type(const number_t &x, const number_t &y);
  // -----------------------------------
  bool is_zero(const number_t &x);
  bool is_one(const number_t &x);
  number_t add(const number_t &x, const number_t &y);
  number_t sub(const number_t &x, const number_t &y);
  number_t mul(const number_t &x, const number_t &y);
  number_t div(const number_t &x, const number_t &y);
  number_t idiv(const number_t &x, const number_t &y);
  number_t mod(const number_t &x, const number_t &y);
  int cmp(const number_t &x, const number_t &y);

  number_t abs(const number_t &x);
  number_t ceil(const number_t &x);
  number_t floor(const number_t &x);
  number_t round(const number_t &x);
  number_t exp(const number_t &x, size_t precision = 16);
  number_t pow(const number_t &a, const number_t &x, size_t precision = 16);
  number_t ln(const number_t &x, size_t precision = 16);
  number_t log(const number_t &a, const number_t &x, size_t precision = 16);
  number_t log2(const number_t &x, size_t precision = 16);
  number_t log10(const number_t &x, size_t precision = 16);
  number_t sqrt(const number_t &x, size_t precision = 16);
  number_t sin(const number_t &x, size_t precision = 16);
  number_t cos(const number_t &x, size_t precision = 16);
  number_t tan(const number_t &x, size_t precision = 16);
  number_t cot(const number_t &x, size_t precision = 16);
  number_t sec(const number_t &x, size_t precision = 16);
  number_t csc(const number_t &x, size_t precision = 16);
  number_t arcsin(const number_t &x, size_t precision = 16);
  number_t arccos(const number_t &x, size_t precision = 16);
  number_t arctan(const number_t &x, size_t precision = 16);
  number_t arccot(const number_t &x, size_t precision = 16);
  number_t arcsec(const number_t &x, size_t precision = 16);
  number_t arccsc(const number_t &x, size_t precision = 16);
  number_t sinh(const number_t &x, size_t precision = 16);
  number_t cosh(const number_t &x, size_t precision = 16);
  number_t tanh(const number_t &x, size_t precision = 16);
  number_t coth(const number_t &x, size_t precision = 16);
  number_t sech(const number_t &x, size_t precision = 16);
  number_t csch(const number_t &x, size_t precision = 16);
  number_t arcsinh(const number_t &x, size_t precision = 16);
  number_t arccosh(const number_t &x, size_t precision = 16);
  number_t arctanh(const number_t &x, size_t precision = 16);
  number_t arccoth(const number_t &x, size_t precision = 16);
  number_t arcsech(const number_t &x, size_t precision = 16);
  number_t arccsch(const number_t &x, size_t precision = 16);
  number_t erf(const number_t &x, size_t precision = 16);
  number_t erfc(const number_t &x, size_t precision = 16);
  int sgn(const number_t &x);
  number_t fraction(const number_t &x);
  number_t reduction(const number_t &x);
  number_t gamma(const number_t &x, size_t precision = 16);

  //
  // 仅作用于整型number_t的函数
  //
  number_t gcd(const number_t &x, const number_t &y);
  number_t lcm(const number_t &x, const number_t &y);
  number_t extended_euclidean(const number_t &x, const number_t &y, number_t &s, number_t &t);

} // namespace mynum

#endif // MYNUM_H_
