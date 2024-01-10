#ifndef MYNUM_COMPILE_H_
#define MYNUM_COMPILE_H_

namespace mynum
{

//
// 在三角函数与双曲函数中通过迭代展开公式
//
// #define ITER_IN_TH

//
// 在核心运算函数中不使用精度控制
//
// #define FULL_COMPUTE_IN_CORE

//
// 调试选项
//
#ifdef DEBUG

#endif

//
// 是否在ARM64中
//
// #define ARCH_ARM64

//
// 开启浮点最大化计算
//
// #define USE_FLOAT_MAX
#define MAX_FLOAT_STR           2024

} // namespace mynum

#endif // MYNUM_COMPILE_H_