#ifndef MYNUM_CONSTANT_H_
#define MYNUM_CONSTANT_H_
#include <mynum/float.h>

namespace mynum {

extern Float __pi;
extern Float __half_pi;
extern Float __e;

Float approximate_pi(const Float& precision);
Float approximate_e(const Float& precision);

} // namespace mynum

#endif // MYNUM_CONSTANT_H_