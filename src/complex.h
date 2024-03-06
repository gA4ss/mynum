#ifndef MYNUM_COMPLEX_H_
#define MYNUM_COMPLEX_H_

#include <mynum/real.h>

namespace mynum
{

//
// 定义复数
//

  typedef struct __complex_t
  {
    __complex_t();
    __complex_t(const __complex_t &c);
    __complex_t(const __real_t &re, const __real_t &im);
    __complex_t(std::string re, std::string im);

    real_t re() const;
    real_t im() const;

    std::string value() const;

    //
    // 实部与虚部
    //
    real_t __real_park;
    real_t __imaginary_part;
  } complex_t;

  complex_t add(const complex_t &x, const complex_t &y);
  complex_t sub(const complex_t &x, const complex_t &y);
  complex_t mul(const complex_t &x, const complex_t &y);
  complex_t div(const complex_t &x, const complex_t &y);
  complex_t mod(const complex_t &x, const complex_t &y);

  real_t length(const complex_t &x);
  int cmp(const complex_t &x, const complex_t &y);

  complex_t exp(const complex_t &x, size_t precision = 16);
  complex_t pow(const complex_t &a, const complex_t &x, size_t precision = 16);
  complex_t ln(const complex_t &x, size_t precision = 16);
  complex_t log(const complex_t &a, const complex_t &x, size_t precision = 16);
  complex_t log2(const complex_t &x, size_t precision = 16);
  complex_t log10(const complex_t &x, size_t precision = 16);
  complex_t sqrt(const complex_t &x, size_t precision = 16);

  void to_triangle(const complex_t &x, real_t &rho, real_t &phi);
  complex_t from_triangle(const real_t &rho, const real_t &phi);
} // namespace mynum

#endif // MYNUM_COMPLEX_H_