#ifndef MYNUM_WRAPPER_H_
#define MYNUM_WRAPPER_H_

#include <mynum/mynum.h>

mynum::number_t& operator>>(std::istream& in, mynum::number_t &x);
std::ostream& operator<<(std::ostream& out, const mynum::number_t &x);

//
// number_t,number_t
//
mynum::number_t operator+(const mynum::number_t &x, const mynum::number_t &y);
mynum::number_t operator-(const mynum::number_t &x, const mynum::number_t &y);
mynum::number_t operator*(const mynum::number_t &x, const mynum::number_t &y);
mynum::number_t operator/(const mynum::number_t &x, const mynum::number_t &y);
mynum::number_t operator%(const mynum::number_t &x, const mynum::number_t &y);

bool operator||(const mynum::number_t &x, const mynum::number_t &y);
bool operator&&(const mynum::number_t &x, const mynum::number_t &y);
bool operator!(const mynum::number_t &x);

bool operator<(const mynum::number_t &x, const mynum::number_t &y);
bool operator<=(const mynum::number_t &x, const mynum::number_t &y);
bool operator>(const mynum::number_t &x, const mynum::number_t &y);
bool operator>=(const mynum::number_t &x, const mynum::number_t &y);
bool operator==(const mynum::number_t &x, const mynum::number_t &y);
bool operator!=(const mynum::number_t &x, const mynum::number_t &y);

//
// number_t,string
//
mynum::number_t operator+(const mynum::number_t &x, std::string y);
mynum::number_t operator-(const mynum::number_t &x, std::string y);
mynum::number_t operator*(const mynum::number_t &x, std::string y);
mynum::number_t operator/(const mynum::number_t &x, std::string y);
mynum::number_t operator%(const mynum::number_t &x, std::string y);

bool operator||(const mynum::number_t &x, std::string y);
bool operator&&(const mynum::number_t &x, std::string y);

bool operator<(const mynum::number_t &x, std::string y);
bool operator<=(const mynum::number_t &x, std::string y);
bool operator>(const mynum::number_t &x, std::string y);
bool operator>=(const mynum::number_t &x, std::string y);
bool operator==(const mynum::number_t &x, std::string y);
bool operator!=(const mynum::number_t &x, std::string y);

//
// string,number_t
//
mynum::number_t operator+(std::string x, const mynum::number_t &y);
mynum::number_t operator-(std::string x, const mynum::number_t &y);
mynum::number_t operator*(std::string x, const mynum::number_t &y);
mynum::number_t operator/(std::string x, const mynum::number_t &y);
mynum::number_t operator%(std::string x, const mynum::number_t &y);

bool operator||(std::string x, const mynum::number_t &y);
bool operator&&(std::string x, const mynum::number_t &y);

bool operator<(std::string x, const mynum::number_t &y);
bool operator<=(std::string x, const mynum::number_t &y);
bool operator>(std::string x, const mynum::number_t &y);
bool operator>=(std::string x, const mynum::number_t &y);
bool operator==(std::string x, const mynum::number_t &y);
bool operator!=(std::string x, const mynum::number_t &y);

//
// number_t,myflt_t
//
mynum::number_t operator+(const mynum::number_t &x, mynum::myflt_t y);
mynum::number_t operator-(const mynum::number_t &x, mynum::myflt_t y);
mynum::number_t operator*(const mynum::number_t &x, mynum::myflt_t y);
mynum::number_t operator/(const mynum::number_t &x, mynum::myflt_t y);
mynum::number_t operator%(const mynum::number_t &x, mynum::myflt_t y);

bool operator||(const mynum::number_t &x, mynum::myflt_t y);
bool operator&&(const mynum::number_t &x, mynum::myflt_t y);

bool operator<(const mynum::number_t &x, mynum::myflt_t y);
bool operator<=(const mynum::number_t &x, mynum::myflt_t y);
bool operator>(const mynum::number_t &x, mynum::myflt_t y);
bool operator>=(const mynum::number_t &x, mynum::myflt_t y);
bool operator==(const mynum::number_t &x, mynum::myflt_t y);
bool operator!=(const mynum::number_t &x, mynum::myflt_t y);

//
// myflt_t,number_t
//
mynum::number_t operator+(mynum::myflt_t x, const mynum::number_t &y);
mynum::number_t operator-(mynum::myflt_t x, const mynum::number_t &y);
mynum::number_t operator*(mynum::myflt_t x, const mynum::number_t &y);
mynum::number_t operator/(mynum::myflt_t x, const mynum::number_t &y);
mynum::number_t operator%(mynum::myflt_t x, const mynum::number_t &y);

bool operator||(mynum::myflt_t x, const mynum::number_t &y);
bool operator&&(mynum::myflt_t x, const mynum::number_t &y);

bool operator<(mynum::myflt_t x, const mynum::number_t &y);
bool operator<=(mynum::myflt_t x, const mynum::number_t &y);
bool operator>(mynum::myflt_t x, const mynum::number_t &y);
bool operator>=(mynum::myflt_t x, const mynum::number_t &y);
bool operator==(mynum::myflt_t x, const mynum::number_t &y);
bool operator!=(mynum::myflt_t x, const mynum::number_t &y);

#endif // MYNUM_WRAPPER_H_