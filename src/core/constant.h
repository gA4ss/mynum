#ifndef MYNUM_CORE_CONSTANT_H_
#define MYNUM_CORE_CONSTANT_H_
#include <mynum/core/numeric.h>

namespace mynum {
namespace core {

extern Numeric __pi;
extern Numeric __half_pi;
extern Numeric __e;

Numeric approximate_pi(const Numeric& precision);
Numeric approximate_e(const Numeric& precision);

} // namespace core
} // namespace mynum

#endif