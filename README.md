# mynum

数值运算库。

# 编译

在编译本库之前请先安装`cmake`、`gtest`库以及[_*mympz*_](https://github.com/gA4ss/mympz)库与[_*mympf*_](https://github.com/gA4ss/mympf)库，在安装完成后，使用如下命令进行编译。

```bash
mkdir build
cd build
cmake ..
make
```

编译完成后，可以使用`make install`进行安装。

# 使用说明

在使用时，仅需包含头文件`#include <mynum/mynum.h>`即可使用。链接库文件请链接`libmynum.a`文件。

## 命名空间

本库给定了三个命令空间如下所示：

```c++
namespace mynum
{
  namespace z
  {
    // 整型运算的空间
  }

  namespace f
  {
    // 浮点数运算的空间
  }
}
```

## 整型函数列表

|名称|说明|
|---|----|
|`abs`|绝对值|
|`bernoulli_numbers`|伯努利数|
|`euler_numbers`|欧拉数|
|`extended_euclidean`|扩展欧几里得算法|
|`gcd`|最大公约数|
|`lcm`|最小公倍数|
|`lshift_bits`|左移位|
|`rshift_bits`|右移位|
|`not_bits`|非运算|
|`or_bits`|或运算|
|`xor_bits`|异或运算|
|`and_bits`|与运算|
|`factorial`|阶乘|
|`pow`|指数运算|
|`sgn`|当前符号|

## 浮点函数列表

|名称|说明|
|---|----|
|`abs`|绝对值|
|`sin`|正弦|
|`cos`|余弦|
|`tan`|正切|
|`cot`|余切|
|`sec`|正割|
|`csc`|余割|
|`arcsin`|反正弦|
|`arccos`|反余弦|
|`arctan`|反正切|
|`arccot`|反余切|
|`arcsec`|反正割|
|`arcsc`|反余割|
|`sinh`|双曲正弦|
|`cosh`|双曲余弦|
|`tanh`|双曲正切|
|`coth`|双曲余切|
|`sech`|双曲正割|
|`csch`|双曲余割|
|`arcsinh`|双曲反正弦|
|`arccosh`|双曲反余弦|
|`arctanh`|双曲反正切|
|`arccoth`|双曲反余切|
|`arcsech`|双曲反正割|
|`arccsch`|双曲反余割|
|`erf`|误差函数|
|`erfc`|误差补函数|
|`sqrt`|开平方|
|`exp`|以e为底的指数函数|
|`pow`|任意数为底，任意次幂的指数函数|
|`ln`|以e为底的对数函数|
|`log2`|以2为底的对数函数|
|`log10`|以10为底的对数函数|
|`log`|以任意数为底的对数函数|
|`gmmma`|伽马函数，*未实现*|
|`factorial`|阶乘|
|`fraction`|化浮点为分数|
|`add(fraction)`|分数加|
|`sub(fraction)`|分数减|
|`mul(fraction)`|分数乘|
|`div(fraction)`|分数除|
|`common_denominator(fraction)`|通分|
|`reduction(fraction)`|分数消减|
|`floor`|下取整|
|`ceil`|上取整|
|`round`|四舍五入|
|`sgn`|当前符号|

# 异常说明

|异常|
|---|
|无效操作数|
|超出伯努利数表|
|超出欧拉数表|

其余异常发生由`mympz`与`mympf`抛出。


# ChangeList

## 2023-4-6

* 增加分数的加减乘除函数、分子分母消减函数、通分函数。
```
    fraction_t reduction(const fraction_t &x);
    fraction_t add(const fraction_t &x, const fraction_t &y);
    fraction_t sub(const fraction_t &x, const fraction_t &y);
    fraction_t mul(const fraction_t &x, const fraction_t &y);
    fraction_t div(const fraction_t &x, const fraction_t &y);
    std::pair<fraction_t, fraction_t> common_denominator(const fraction_t &x, const fraction_t &y);
```