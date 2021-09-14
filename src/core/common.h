#ifndef MYNUM_CORE_COMMON_H_
#define MYNUM_CORE_COMMON_H_

#include <my/my_common.h>
#include <mynum/core/exception.h>

namespace mynum {
namespace core {

using namespace my;

//////////////////////////////
//     一些数字类型的定义     //
//////////////////////////////

enum {
  kNegative = 0,
  kPositive = 1
};

#ifdef BIT64
typedef int64_t integer_t;
typedef uint64_t uinteger_t;
static const uint64_t kNumericUnitMax = 0xFFFFFFFFFFFFFFFF;
#else
typedef int32_t integer_t;
typedef uint32_t uinteger_t;
static const uint32_t kNumericUnitMax = 0xFFFFFFFF;
#endif

} // namespace core
} // namespace mynum

#endif // MYNUM_CORE_COMMON_H_