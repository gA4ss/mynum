#ifndef MYNUM_MATH_H_
#define MYNUM_MATH_H_

#include <cfenv>
#include <cfloat>
#include <cmath>

#include <mynum/integer.h>
#include <mynum/float.h>

namespace mynum {
namespace math {

Float abs(const Float& x);
Float acos(const Float& x);
Float acosh(const Float& x);
Float acoshf(const Float& x);
Float acoshl(const Float& x);
Float asin(const Float& x);
Float asinh(const Float& x);
Float asinhf(const Float& x);
Float asinhl(const Float& x);
Float atan(const Float& x);
Float atan2(const Float& y, const Float& x);
Float atanh(const Float& x);
Float atanhf(const Float& x);
Float atanhl(const Float& x);
Float cbrt(const Float& x);
Float ceil(const Float& x);
Float copysign(const Float& x, const Float& y);
Float cos(const Float& x);
Float cosh(const Float& x);
Float erf(const Float& x);
Float erfc(const Float& x);
Float exp(const Float& x);
Float exp2(const Float& x);
Float exp2f(const Float& x);
Float exp2l(const Float& x);
Float expm1(const Float& x);
Float expm1f(const Float& x);
Float expm1l(const Float& x);
Float fabs(const Float& x);
Float fdim(const Float& x, const Float& y);
Float fdimf (const Float& x, const Float& y);
Float fdiml (const Float& x, const Float& y);
Float floor(const Float& x);
Float fma(const Float& x, const Float& y, const Float& z);
Float fmaf(const Float& x, const Float& y, const Float& z);
Float fmal(const Float& x, const Float& y, const Float& z);
Float fmax(const Float& x, const Float& y);
Float fmaxf(const Float& x, const Float& y);
Float fmaxl(const Float& x, const Float& y);
Float fmin(const Float& x, const Float& y);
Float fminf(const Float& x, const Float& y);
Float fminl(const Float& x, const Float& y);
Float fmod(const Float& numer, const Float& denom);
Integer fpclassify(const Float& x);
Float frexp(const Float& x, Integer* exp);
Float hypot(const Float& x, const Float& y);
Float hypotf(const Float& x, const Float& y);
Float hypotl(const Float& x, const Float& y);
Integer ilogb(const Float& x);
Integer ilogbf(const Float& x);
Integer ilogbl(const Float& x);
bool isfinite(const Float& x);
bool isgreater(const Float& x, const Float& y);
bool isgreaterequal(const Float& x, const Float& y);
bool isinf(const Float& x);
bool isless(const Float& x, const Float& y);
bool islessequal(const Float& x, const Float& y);
bool islessgreater(const Float& x, const Float& y);
bool isnan(const Float& x);
bool isnormal(const Float& x);
bool isunordered(const Float& x, const Float& y);
Float ldexp(const Float& x, const Integer& exp);
Float lgamma(const Float& x);
Float lgammaf(const Float& x);
Float lgammal(const Float& x);
Integer llrint(const Float& x);
Integer llrintf(const Float& x);
Integer llrintl(const Float& x);
Integer llround(const Float& x);
Integer llroundf(const Float& x);
Integer llroundl(const Float& x);
Float log(const Float& x);
Float log10(const Float& x);
Float log1p(const Float& x);
Float log1pf(const Float& x);
Float log1pl(const Float& x);
Float log2(const Float& x);
Float log2f(const Float& x);
Float log2l(const Float& x);
Float logb(const Float& x);
Float logbf(const Float& x);
Float logbl(const Float& x);
Float lrint(const Float& x);
Float lrintf(const Float& x);
Float lrintl(const Float& x);
Integer lround(const Float& x);
Integer lroundf(const Float& x);
Integer lroundl(const Float& x);
Float modf(const Float& x, Integer* intpart);
Float nan(const char* tagp);
Float nanf(const char* tagp);
Float nanl(const char* tagp);
Float nearbyint(const Float& x);
Float nearbyintf(const Float& x);
Float nearbyintl(const Float& x);
Float nextafter(const Float& x, const Float& y);
Float nextafterf(const Float& x, const Float& y);
Float nextafterl(const Float& x, const Float& y);
Float nexttoward(const Float& x, const Float& y);
Float nexttowardf(const Float& x, const Float& y);
Float nexttowardl(const Float& x, const Float& y);
Float pow(const Float& base, const Float& exponent);
Float remainder(const Float& numer, const Float& denom);
Float remainderf(const Float& numer, const Float& denom);
Float remainderl(const Float& numer, const Float& denom);
Float remquo(const Float& numer, const Float& denom, Integer* quot);
Float remquof(const Float& numer, const Float& denom, Integer* quot);
Float remquol(const Float& numer, const Float& denom, Integer* quot);
Float rint(const Float& x);
Float rintf(const Float& x);
Float rintl(const Float& x);
Float round(const Float& x);
Float roundf(const Float& x);
Float roundl(const Float& x);
Float scalbln(const Float& x, const Integer& n);
Float scalblnf(const Float& x, const Integer& n);
Float scalblnl(const Float& x, const Integer& n);
Float scalbn(const Float& x, const Integer& n);
Float scalbnf(const Float& x, const Integer& n);
Float scalbnl(const Float& x, const Integer& n);
Integer signbit(const Float& x);
Float sin(const Float& x);
Float sinh(const Float& x);
Float sqrt(const Float& x);
Float tan(const Float& x);
Float tanh(const Float& x);
Float tgamma(const Float& x);
Float tgammaf(const Float& x);
Float tgammal(const Float& x);
Float trunc(const Float& x);
Float truncf(const Float& x);
Float truncl(const Float& x);

} // namespace math
} // namespace mynum

#endif // MYNUM_MATH_HPP_