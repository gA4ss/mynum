#ifndef MYNUM_NUMBER_H_
#define MYNUM_NUMBER_H_

#include <mynum/complex.h>

namespace mynum
{

  //
  // 数的定义
  //
#define kNumTypeReal 0
#define kNumTypeGF 1
#define kNumTypeComplex 0x10

  typedef struct __number_t
  {
    __number_t();
    __number_t(const __number_t &n);

    __number_t(const __real_t &r);
    __number_t(const __complex_t &c);

    __number_t(std::string n);
    __number_t(myflt_t n);
    __number_t(integer_t n);
    __number_t(float_t n);
    __number_t(fraction_t n);

    __number_t(const __real_t &re, const __real_t &im);
    __number_t(std::string re, std::string im);

    int type() const;
    bool is_complex() const;
    std::string value() const;

    //
    // 重载运算符
    //
    __number_t &operator=(const __number_t &n);
    __number_t &operator=(std::string n);
    __number_t &operator=(myflt_t n);
    __number_t &operator=(const integer_t &n);
    __number_t &operator=(const float_t &n);

    void operator+=(const __number_t &n);
    void operator-=(const __number_t &n);
    void operator*=(const __number_t &n);
    void operator/=(const __number_t &n);
    void operator%=(const __number_t &n);

    //
    // 保存的值
    //
    int __type;
    real_t num_real;       // 实数
    complex_t num_complex; // 复数
  } number_t;

  bool test(const number_t &x, int type);
  number_t covert_to(const number_t &x, int type);
  number_t integer_to_float(const number_t &x);
  number_t float_to_integer(const number_t &x);
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
  bool relatively_prime(const number_t &x, const number_t &y);

} // namespace mynum

#endif // MYNUM_NUMBER_H_