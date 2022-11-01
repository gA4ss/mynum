# 介绍
主要是实现大数运算以及各种数值运算。目前实现了**整数**、**浮点数**的基本加减乘除以及取模的大数运算以及指数函数、对数函数、幂函数、三角函数、反三角函数、双曲函数、反双曲函数、阶乘、最大公约数、扩展欧几里德算法等等大数运算。重载了基本上**所有的运算符**，可以通过字符串来定义大数也可以直接使用字符串定义的大数直接参与运算。

# 目前没有做任何优化 ---> 运算还很慢
努力吧，少年。。。

# 运算类

* `Integer` : 实现了整数的大数运算。
* `Float` : 实现了浮点数的大数运算。
* `bignum_t` : 实现了基本的大数运算，`Integer`与`Float`的运算都是封装此类，不直接使用。

# 数值类型
除了基础数值，还提供了**无穷**以及**NAN**两种类型。可以通过`Integer("inf")`定义无穷，或者`Integer("-inf")`定义负无穷。`Integer`可以替换成`Float`也可以。定义**NAN**值是当某个计算不符合数理的时候进行值的定义。可以通过`Float("nan")`来定义。当声明一个数时没有调用任何构造函数，那么它也是一个非数值数。例如：`Float x;`，此时`x`就算一个**NAN**值。

# 整型运算提供的函数
```c++
//
// 比较运算
//
bool equ(const Integer& num1, const Integer& num2);
bool gt(const Integer& num1, const Integer& num2);
bool lt(const Integer& num1, const Integer& num2);
bool ge(const Integer& num1, const Integer& num2);
bool le(const Integer& num1, const Integer& num2);

//
// 基础的运算
//
bool is_zero(const Integer& num1);
bool is_one(const Integer& num1);
bool is_nan(const Integer& num1);
bool is_infinite(const Integer& num1);
bool is_none(const Integer& num1);
bool is_odd(const Integer& num1);
bool is_even(const Integer& num1);

Integer add(const Integer& num1, const Integer& num2);
Integer sub(const Integer& num1, const Integer& num2);
Integer mul(const Integer& num1, const Integer& num2);
std::pair<Integer, Integer> div(const Integer& num1, const Integer& num2);
Integer quo(const Integer& num1, const Integer& num2);
Integer mod(const Integer& num1, const Integer& num2);

Integer abs(const Integer& num1);
Integer floor(const Integer& num1);
Integer ceil(const Integer& num1);
Integer pow(const Integer& num1, const Integer& exp);
Integer factorial(const Integer& num1);
std::pair<Integer, Integer> extended_euclidean(const Integer& num1, const Integer& num2);
Integer gcd(const Integer& num1, const Integer& num2);
Integer lcm(const Integer& num1, const Integer& num2);
int sgn(const Integer& num1);

Integer or_bits(const Integer& num1, const Integer& num2);
Integer and_bits(const Integer& num1, const Integer& num2);
Integer xor_bits(const Integer& num1, const Integer& num2);
Integer not_bits(const Integer& num1);
Integer lshift_bits(const Integer& num1, const Integer& bits);
Integer rshift_bits(const Integer& num1, const Integer& bits);

//
// 各种代数数
//
fraction_vector_t bernoulli_numbers(uinteger_t n);
int_array_t euler_numbers(uinteger_t m);

//
// 功能函数
//
void copy(Integer& to, const Integer& from);
void same_digits(Integer& num1, Integer& num2);
```

# 浮点运算提供的函数

```c++
//
// 比较运算
//
bool equ(const Float& num1, const Float& num2);
bool gt(const Float& num1, const Float& num2);
bool lt(const Float& num1, const Float& num2);
bool ge(const Float& num1, const Float& num2);
bool le(const Float& num1, const Float& num2);

//
// 基础的运算
//
bool is_zero(const Float& num1);
bool is_one(const Float& num1);
bool is_nan(const Float& num1);
bool is_infinite(const Float& num1);
bool is_none(const Float& num1);
bool is_integer(const Float& num1);
bool is_float(const Float& num1);

Float add(const Float& num1, const Float& num2);
Float sub(const Float& num1, const Float& num2);
Float mul(const Float& num1, const Float& num2);
Float div(const Float& num1, const Float& num2, uinteger_t significant_digits=16);
void div2(const Float& num1, const Float& num2, Float& quo, Float& rem, uinteger_t significant_digits=16);
Float mod(const Float& num1, const Float& num2, uinteger_t significant_digits=16);

Float abs(const Float& num1);
Float floor(const Float& num1);
Float ceil(const Float& num1);
Float round(const Float& num1, uinteger_t significant_digits=0);
Float integer(const Float& num1);
Float pow(const Float& a, const Float& x, const char* epsilon="0.0000000000000001");
Float exp(const Float& x, const char* epsilon="0.0000000000000001");
Float sqrt(const Float& num1, const char* epsilon=kDefEpsilon);
Float factorial(const Float& num1);
Float log(const Float& base, const Float& x, const char* epsilon="0.0000000000000001");
Float log2(const Float& x, const char* epsilon="0.0000000000000001");
Float log10(const Float& x, const char* epsilon="0.0000000000000001");
Float ln(const Float& x, const char* epsilon="0.0000000000000001");
int sgn(const Float& num1);

//
// 三角函数
//
Float sin(const Float& x, const char* epsilon=kDefEpsilon);
Float cos(const Float& x, const char* epsilon=kDefEpsilon);
Float tan(const Float& x, const char* epsilon=kDefEpsilon);
Float csc(const Float& x, const char* epsilon=kDefEpsilon);
Float sec(const Float& x, const char* epsilon=kDefEpsilon);
Float cot(const Float& x, const char* epsilon=kDefEpsilon);

//
// 反三角函数
//
Float arcsin(const Float& x, const char* epsilon=kDefEpsilon);
Float arccos(const Float& x, const char* epsilon=kDefEpsilon);
Float arctan(const Float& x, const char* epsilon=kDefEpsilon);
Float arccsc(const Float& x, const char* epsilon=kDefEpsilon);
Float arcsec(const Float& x, const char* epsilon=kDefEpsilon);
Float arccot(const Float& x, const char* epsilon=kDefEpsilon);

//
// 双曲函数
//
Float sinh(const Float& x, const char* epsilon=kDefEpsilon);
Float cosh(const Float& x, const char* epsilon=kDefEpsilon);
Float tanh(const Float& x, const char* epsilon=kDefEpsilon);
Float csch(const Float& x, const char* epsilon=kDefEpsilon);
Float sech(const Float& x, const char* epsilon=kDefEpsilon);
Float coth(const Float& x, const char* epsilon=kDefEpsilon);

//
// 反双曲函数
//
Float arcsinh(const Float& x, const char* epsilon=kDefEpsilon);
Float arccosh(const Float& x, const char* epsilon=kDefEpsilon);
Float arctanh(const Float& x, const char* epsilon=kDefEpsilon);
Float arccsch(const Float& x, const char* epsilon=kDefEpsilon);
Float arcsech(const Float& x, const char* epsilon=kDefEpsilon);
Float arccoth(const Float& x, const char* epsilon=kDefEpsilon);

//
// 分数相关
//
std::pair<Integer, Integer> fraction(const Float& x);

//
// 功能函数
//
void copy(Float& to, const Float& from);
void same_digits(Float& num1, Float& num2);
```

# 运算符重载

```c++
m = "1844674407370955161518446744073709551615";
m *= "1844674407370955161518446744073709551615"; 
EXPECT_TRUE(m == "3402823669209384634332867666227678774935636506223790760108426481119284349108225");
```
以上`EXPECT_TRUE`是_gtest_的测试宏，用于判定`m`的值是否等于`==`后边的数字。`<`,`>`,`<=`,`>=`,`==`都已经重载了。
这里可以参见"_src/integer/operator.cc_"与"_src/float/operator.cc_"下的代码来查看重载的运算符。

**整数与浮点数提供的重载不太一样，整数有位操作而浮点数就没有提供。**

# 编译
这里需要一个小工具库 _my_ 进行支持。提供了异常定义与调试日志功能。
## my
```sh
git clone https://github.com/gA4ss/my.git
cd my
mkdir build
cd build
cmake ..
make
sudo make install
```
## gtest
下载_gtest_并按照，为了测试用例的支持。
```sh
# tar zxvf ./lib/googletest-release-1.11.0.tar.gz
git clone https://github.com/google/googletest.git
cd ./googletest
./configure
make
sudo make install
```

在_mynum_目录下执行以下代码。
```sh
mkdir build
cd build
cmake ..
make
sudo make install
```

## 使用
参见"_src/test/_"下的"_test\_float.cc_"、"_test\_float\_log.cc_"、"_test\_float\_pow.cc_"以及"_test\_integer_.cc"的测试用例。


