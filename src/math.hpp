#ifndef MYNUM_MATH_HPP_
#define MYNUM_MATH_HPP_

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

#include <mynum/math/abs.hpp>
#include <mynum/math/acos.hpp>
#include <mynum/math/acosh.hpp>
#include <mynum/math/asin.hpp>
#include <mynum/math/asinh.hpp>
#include <mynum/math/atan.hpp>
#include <mynum/math/atan2.hpp>
#include <mynum/math/atanh.hpp>
#include <mynum/math/cbrt.hpp>
#include <mynum/math/ceil.hpp>
#include <mynum/math/copysign.hpp>
#include <mynum/math/cos.hpp>
#include <mynum/math/cosh.hpp>
#include <mynum/math/erf.hpp>
#include <mynum/math/erfc.hpp>
#include <mynum/math/exp.hpp>
#include <mynum/math/exp2.hpp>
#include <mynum/math/expm1.hpp>
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