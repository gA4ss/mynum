#include <mynum/float.h>

#include <ctype.h>
#include <iostream>

namespace mynum {

/* 此函数只对比值的情况，不考虑符号情况。*/
int __cmp(const Float& num1, const Float& num2) {
  int res = cmp(num1.integer_park(), num2.integer_park());
  if (res != 0) return res;
  // 整数相等，则比对小数。
  res = cmp(num1.decimal_park(), num2.decimal_park(), true);
  return res;
}

} // namespace mynum