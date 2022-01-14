#ifndef MYNUM_COMMON_H_
#define MYNUM_COMMON_H_

#include <ctype.h>
#include <iostream>
#include <iomanip>
#include <sstream>

#include <my/my_common.h>
#include <mynum/exception.h>

namespace mynum {

//////////////////////////////
//     一些数字类型的定义     //
//////////////////////////////

enum {
  kNegative = -1,
  kPositive = 1
};

//////////////////////////////
//        全局配置结构        //
//////////////////////////////
typedef struct Config {
  my::uinteger_t significant_digits;    // 0xFFFFFFFFFFFFFFFF 表示一直计算。
  std::string epsilon;
  int set_precision;                // 仅针对使用浮点数构造Float时，setprecision函数的值。
} config_t;

extern config_t __config;

} // namespace mynum

#endif // MYNUM_COMMON_H_