#ifndef MYNUM_CONSTANT_H_
#define MYNUM_CONSTANT_H_
#include <mynum/float.h>

namespace mynum {

extern Float __pi;
extern Float __half_pi;
extern Float __e;
extern Float __golden_ratio;

Float approximate_pi(const char* epsilon="0.0000000000000001");
Float approximate_e(const char* epsilon="0.0000000000000001");
Float approximate_golden_ratio(const char* epsilon="0.0000000000000001");

} // namespace mynum

#endif // MYNUM_CONSTANT_H_