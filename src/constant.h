#ifndef MYNUM_CONSTANT_H_
#define MYNUM_CONSTANT_H_
#include <mynum/numeric.h>

namespace mynum {

extern Numeric __pi;
extern Numeric __half_pi;
extern Numeric __e;

Numeric approximate_pi(const Numeric& precision);
Numeric approximate_e(const Numeric& precision);

} // namespace mynum

#endif // MYNUM_CONSTANT_H_