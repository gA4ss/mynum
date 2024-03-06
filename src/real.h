#ifndef MYNUM_REAL_H_
#define MYNUM_REAL_H_

#include <mynum/mp.h>

namespace mynum
{

//
// 定义实数
//
#define kRealTypeNone 0
#define kRealTypeInteger 1
#define kRealTypeFloat 2
#define kRealTypeMpz 3
#define kRealTypeMpf 4
#define kRealTypeFraction 5

  typedef struct __real_t
  {
    __real_t();
    __real_t(const __real_t &n);
    __real_t(std::string n);
    __real_t(myflt_t n);
    __real_t(integer_t n);
    __real_t(float_t n);
    __real_t(fraction_t n);

    void set_str_value(std::string n);
    void set_num_value(const __real_t &n);
    void set_int_value(myint_t n);
    void set_flt_value(myflt_t n);
    void set_mpz_value(integer_t n);
    void set_mpf_value(float_t n);
    void set_frac_value(fraction_t n);

    int type() const;
    std::string value() const;

#if 0
    //
    // 操作符重载
    //
    __real_t &operator=(const __real_t &n);
    __real_t &operator=(std::string n);
    __real_t &operator=(myflt_t n);
    __real_t &operator=(const integer_t &n);
    __real_t &operator=(const float_t &n);

    void operator+=(const __real_t &n);
    void operator-=(const __real_t &n);
    void operator*=(const __real_t &n);
    void operator/=(const __real_t &n);
    void operator%=(const __real_t &n);
#endif

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
  } real_t;

  bool test(const real_t &x, int type);
  real_t covert_to(const real_t &x, int type);
  real_t integer_to_float(const real_t &x);
  real_t float_to_integer(const real_t &x);
  std::pair<real_t, real_t> same_type(const real_t &x, const real_t &y);
  // -----------------------------------
  bool is_zero(const real_t &x);
  bool is_one(const real_t &x);
  real_t add(const real_t &x, const real_t &y);
  real_t sub(const real_t &x, const real_t &y);
  real_t mul(const real_t &x, const real_t &y);
  real_t div(const real_t &x, const real_t &y);
  real_t idiv(const real_t &x, const real_t &y);
  real_t mod(const real_t &x, const real_t &y);
  int cmp(const real_t &x, const real_t &y);

  real_t abs(const real_t &x);
  real_t ceil(const real_t &x);
  real_t floor(const real_t &x);
  real_t round(const real_t &x);
  real_t exp(const real_t &x, size_t precision = 16);
  real_t pow(const real_t &a, const real_t &x, size_t precision = 16);
  real_t ln(const real_t &x, size_t precision = 16);
  real_t log(const real_t &a, const real_t &x, size_t precision = 16);
  real_t log2(const real_t &x, size_t precision = 16);
  real_t log10(const real_t &x, size_t precision = 16);
  real_t sqrt(const real_t &x, size_t precision = 16);
  real_t sin(const real_t &x, size_t precision = 16);
  real_t cos(const real_t &x, size_t precision = 16);
  real_t tan(const real_t &x, size_t precision = 16);
  real_t cot(const real_t &x, size_t precision = 16);
  real_t sec(const real_t &x, size_t precision = 16);
  real_t csc(const real_t &x, size_t precision = 16);
  real_t arcsin(const real_t &x, size_t precision = 16);
  real_t arccos(const real_t &x, size_t precision = 16);
  real_t arctan(const real_t &x, size_t precision = 16);
  real_t arccot(const real_t &x, size_t precision = 16);
  real_t arcsec(const real_t &x, size_t precision = 16);
  real_t arccsc(const real_t &x, size_t precision = 16);
  real_t sinh(const real_t &x, size_t precision = 16);
  real_t cosh(const real_t &x, size_t precision = 16);
  real_t tanh(const real_t &x, size_t precision = 16);
  real_t coth(const real_t &x, size_t precision = 16);
  real_t sech(const real_t &x, size_t precision = 16);
  real_t csch(const real_t &x, size_t precision = 16);
  real_t arcsinh(const real_t &x, size_t precision = 16);
  real_t arccosh(const real_t &x, size_t precision = 16);
  real_t arctanh(const real_t &x, size_t precision = 16);
  real_t arccoth(const real_t &x, size_t precision = 16);
  real_t arcsech(const real_t &x, size_t precision = 16);
  real_t arccsch(const real_t &x, size_t precision = 16);
  real_t erf(const real_t &x, size_t precision = 16);
  real_t erfc(const real_t &x, size_t precision = 16);
  int sgn(const real_t &x);
  real_t fraction(const real_t &x);
  real_t reduction(const real_t &x);
  real_t gamma(const real_t &x, size_t precision = 16);

  //
  // 仅作用于整型number_t的函数
  //
  real_t gcd(const real_t &x, const real_t &y);
  real_t lcm(const real_t &x, const real_t &y);
  real_t extended_euclidean(const real_t &x, const real_t &y, real_t &s, real_t &t);
  bool relatively_prime(const real_t &x, const real_t &y);

} // namespace mynum

#endif // MYNUM_REAL_H_