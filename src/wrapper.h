#ifndef MYNUM_WRAPPER_H_
#define MYNUM_WRAPPER_H_

#include <mynum/mynum.h>

mynum::number_t operator+(const mynum::number_t &x, const mynum::number_t &y);
mynum::number_t operator-(const mynum::number_t &x, const mynum::number_t &y);
mynum::number_t operator*(const mynum::number_t &x, const mynum::number_t &y);
mynum::number_t operator/(const mynum::number_t &x, const mynum::number_t &y);
mynum::number_t operator%(const mynum::number_t &x, const mynum::number_t &y);

#endif // MYNUM_WRAPPER_H_