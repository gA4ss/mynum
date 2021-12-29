#ifndef MYNUM_MATH_HPP_
#define MYNUM_MATH_HPP_

#include <cmath>
#include <mynum/integer.h>
#include <mynum/float.h>

namespace mynum {

template <class T>
bool __is_integer_type() {
  return (my::get_support_type<T>() == kBIntegerT);
}

template <class T>
bool __is_float_type() {
  return (my::get_support_type<T>() == kBFloatT);
}

template <class T>
void __is_invalid_type() {
  my::support_type_t t = my::get_support_type<T>();
  if ((t != kBIntegerT) || (t != kBFloatT)) {
    operation_invalid_class_exception();
  }
}

// Float abs(const Float& x);         // mynum/float/abs.cc
// Integer abs(const Integer& x);     // mynum/integer/abs.cc

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

// Float ceil(const Float& x);          // mynum/float/ceil.cc
// Integer ceil(const Integer& x);      // mynum/integer/ceil.cc

Float copysign(const Float& x, const Float& y);

// Float cos(const Float& x);           // mynum/float/cos.cc

// Float cosh(const Float& x);          // mynum/float/cosh.cc

Float erf(const Float& x);

Float erfc(const Float& x);

// Float exp(const Float& x);           // mynum/float/exp.cc

Float exp2(const Float& x);
Float exp2f(const Float& x);
Float exp2l(const Float& x);

Float expm1(const Float& x);
Float expm1f(const Float& x);
Float expm1l(const Float& x);

#include <mynum/math/fabs.hpp>
#include <mynum/math/fdim.hpp>
#include <mynum/math/floor.hpp>
#include <mynum/math/fma.hpp>
#include <mynum/math/fmax.hpp>
#include <mynum/math/fmin.hpp>
#include <mynum/math/fmod.hpp>
#include <mynum/math/fpclassify.hpp>
#include <mynum/math/frexp.hpp>

#include <mynum/math/hypot.hpp>

#include <mynum/math/ilogb.hpp>
#include <mynum/math/isfinite.hpp>
#include <mynum/math/isgreater.hpp>
#include <mynum/math/isgreaterequal.hpp>
#include <mynum/math/isinf.hpp>
#include <mynum/math/isless.hpp>
#include <mynum/math/islessequal.hpp>
#include <mynum/math/islessgreater.hpp>
#include <mynum/math/isnan.hpp>
#include <mynum/math/isnormal.hpp>
#include <mynum/math/isunordered.hpp>

#include <mynum/math/ldexp.hpp>
#include <mynum/math/lgamma.hpp>
#include <mynum/math/llrint.hpp>
#include <mynum/math/log.hpp>
#include <mynum/math/log10.hpp>
#include <mynum/math/log1p.hpp>
#include <mynum/math/log2.hpp>
#include <mynum/math/logb.hpp>
#include <mynum/math/lrint.hpp>
#include <mynum/math/lround.hpp>

#include <mynum/math/modf.hpp>

#include <mynum/math/nan.hpp>
#include <mynum/math/nanf.hpp>
#include <mynum/math/nanl.hpp>
#include <mynum/math/nearbyint.hpp>
#include <mynum/math/nextafter.hpp>
#include <mynum/math/nexttoward.hpp>

#include <mynum/math/pow.hpp>

#include <mynum/math/remainder.hpp>
#include <mynum/math/remquo.hpp>
#include <mynum/math/rint.hpp>
#include <mynum/math/round.hpp>

#include <mynum/math/scalbln.hpp>
#include <mynum/math/scalbn.hpp>
#include <mynum/math/signbit.hpp>
#include <mynum/math/sin.hpp>
#include <mynum/math/sinh.hpp>
#include <mynum/math/sqrt.hpp>

#include <mynum/math/tan.hpp>
#include <mynum/math/tanh.hpp>
#include <mynum/math/tgamma.hpp>
#include <mynum/math/trunc.hpp>

} // namespace mynum

#endif // MYNUM_MATH_HPP_