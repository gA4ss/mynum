# 介绍
主要是实现大数运算以及各种数域算法与插值算法。

# 编译

在_mysym_目录下，首先按照以下小节安装_my_库与_uuid_库以及_gtest_库(单元测试)。随后执行
```sh
mkdir build
cd build
cmake ..
make
sudo make install
```

## my
```sh
git clone http://github.nagain.com/simulation/my.git
cd my
mkdir build
cd build
cmake ..
make
sudo make install
```

## uuid

```sh
tar zxvf ./lib/libuuid-1.0.3.tar
cd ./lib/libuuid-1.0.3
./configure
make
sudo make install
```

## gtest

```sh
tar zxvf ./lib/googletest-release-1.11.0.tar.gz
cd ./lib/googletest-release-1.11.0
./configure
make
sudo make install
```

# 数域

|类|文件名称|说明|
|-|--------|---|
|`Numeric`|||
|`Complex`|||
|`Real`|||
|`Integer`|||
|`Rational`|||

## 运算

1. 大数运算加、减、乘、除、整除、模、指数、对数、位与、位或、位非、位异或、左移、右移。
2. 大数对比。

### 除法说明

整除与非整除都在`Numeric`中得以实现，实现了统一的接口。

## `Numeric`说明

### `__shrink_zero`说明

首先说明下`__shrink_zero`函数。此函数作用是消去整数前边的$0$与小数部分后边的$0$，在以下函数中进行使用。
但是如果被消减的大数为空，或者只有一位并且是$0$则保留。

1. `__create_from_string`，在通过字符串构造时，此函数最后被调用用于规整输入。
2. `__add_integer_park`
3. `__add_decimal_park`
4. `__sub_decimal_park`
5. `__sub_integer_park`
6. `__mul`
7. `div`(精度除法)，除法运算中使用两次来规范数值输出。但是在内部函数`__div`中并没有使用，因为在内部函数中的$0$是为了用来替代借位的次数。
8. `div`(整除)，`__idiv`中也没有使用。
9. `quo`
10. `rem`


### `__idiv`说明

### NAN值运算说明

### 无穷运算说明

## `Complex`说明
## `Real`说明
## `Integer`说明
## `Rational`说明



