#ifndef MYNUM_COMMON_H_
#define MYNUM_COMMON_H_

#include <ctype.h>
#include <iostream>

#include <my/my_common.h>
#include <mynum/exception.h>

namespace mynum {

using namespace my;

//////////////////////////////
//     一些数字类型的定义     //
//////////////////////////////

enum {
  kNegative = -1,
  kPositive = 1
};

typedef int64_t integer_t;
typedef uint64_t uinteger_t;
typedef double float_t;

//////////////////////////////
//        全局配置结构        //
//////////////////////////////
typedef struct Config {
  uinteger_t precision;
  std::string epsilon;
} config_t;

extern config_t __config;

} // namespace mynum

#endif // MYNUM_COMMON_H_