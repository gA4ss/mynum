#ifndef MYNUM_INTEGER___INFINITY_H_
#define MYNUM_INTEGER___INFINITY_H_

enum {
  kOperandInfNegInfinity = -1,        // 结果是负无穷
  kOperandInfZero = 0,                // 结果是0
  kOperandInfPosInfinity = 1,         // 结果是正无穷
  kOperandInfOne = 2,                 // 结果是1
  kOperandInfNegOne = 3,              // 结果是-1
  kOperandInfNan = 4,                 // 结果是空值
  kOperandInfIndeterminacy = 5        // 结果不确定
};

#endif