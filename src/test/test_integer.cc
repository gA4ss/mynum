#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <gtest/gtest.h>
#include <mynum/integer.h>

using namespace mynum;

TEST(Integer, Create) {
  EXPECT_TRUE(is_nan(Integer("nan")));
  EXPECT_TRUE(Integer("inf") == "inf");
  EXPECT_TRUE(Integer("-inf") == "-inf");
  EXPECT_TRUE("0" == Integer("0"));
  EXPECT_TRUE(Integer("3414") == "3414");
  EXPECT_TRUE("123456789123456789" == Integer("123456789123456789"));
  EXPECT_TRUE(Integer("-1844674407370955161518446744073709551615") == "-1844674407370955161518446744073709551615");
  EXPECT_TRUE(Integer(3) == 3);
  EXPECT_TRUE(Integer(1618) == 1618);
  EXPECT_TRUE(Integer(-4567789120431) == -4567789120431);
}

TEST(Integer, Add) {
  Integer m,n,z;
  m = Integer("31415926");
  n = Integer("21532");
  z = m + n;
  EXPECT_TRUE(z == "31437458");

  m = Integer("31415926");
  n = Integer("-31415926");
  z = m + n;
  EXPECT_TRUE(z == "0") << " z == " << z.str();
}

TEST(Integer, Sub) {
  Integer m,n,z;
  m = Integer("3");
  n = Integer("-3");
  z = m - n;
  EXPECT_TRUE(z == "6");

  m = Integer("0");
  n = Integer("3");
  z = m - n;
  EXPECT_TRUE(z == "-3");

  m = Integer("inf");
  n = Integer("3");
  z = m - n;
  EXPECT_TRUE(z == "inf");

  m = Integer("3");
  n = Integer("inf");
  z = m - n;
  EXPECT_TRUE(z == "-inf");

  m = Integer("3");
  n = Integer("0");
  z = m - n;
  EXPECT_TRUE(z == "3");
}

TEST(Integer, Mul) {
  Integer m,n,z;
  m = Integer("5423784936157847197483457940000098767832678959109111454289");
  n = Integer("-1348958468509017847609193957884909470190843754909375849290843957498298");
  z = m * n;
  EXPECT_TRUE(z == "-7316460621001770695793615722677532697558991811020278508862006264244333162263112086398009291368646551477107496446589401022300122");

  m = Integer("0");
  n = Integer("3");
  z = m * n;
  EXPECT_TRUE(z == "0");

  m = Integer("inf");
  z = m * "0";
  EXPECT_TRUE(is_nan(z)) << "z = " << z.str();

  m = Integer("-inf");
  z = "0" * m;
  EXPECT_TRUE(is_nan(z)) << "z = " << z.str();

  m = Integer("1844674407370955161518446744073709551615");
  m *= "1844674407370955161518446744073709551615"; 
  EXPECT_TRUE(m == "3402823669209384634332867666227678774935636506223790760108426481119284349108225");
}

TEST(Integer, Div) {
  Integer m;
  m = "7";
  m /= "inf";
  EXPECT_TRUE(m == "0") << "m = " << m.str();

  m = "inf";
  m /= "7";
  EXPECT_TRUE(m == "inf");

  m = "-inf";
  m /= "7";
  EXPECT_TRUE(m == "-inf");

  m = "inf";
  m /= "-inf";
  EXPECT_TRUE(is_nan(m));

  m = "0";
  m /= "7";
  EXPECT_TRUE(m == "0");

  m = "0";
  m /= "inf";
  EXPECT_TRUE(m == "0");
}

TEST(Integer, Div2) {
  Integer m,n,z;
  m = "1000";
  n = "2";
  z = m / n;
  EXPECT_TRUE(z == "500") << "z = " << z.str();

  m = Integer("7");
  n = Integer("3");
  z = m / n;
  EXPECT_TRUE(z == "2");

  m = Integer("-7");
  n = Integer("3");
  z = m / n;
  EXPECT_TRUE(z == "-3");

  m = Integer("7");
  n = Integer("-3");
  z = m / n;
  EXPECT_TRUE(z == "-3");

  m = Integer("-7");
  n = Integer("-3");
  z = m / n;
  EXPECT_TRUE(z == "2");

  m = Integer("5");
  n = Integer("11");
  z = m / n;
  EXPECT_TRUE(z == "0");

  m = Integer("-5");
  n = Integer("11");
  z = m / n;
  EXPECT_TRUE(z == "-1");

  m = Integer("5");
  n = Integer("-11");
  z = m / n;
  EXPECT_TRUE(z == "-1");

  m = Integer("-5");
  n = Integer("-11");
  z = m / n;
  EXPECT_TRUE(z == "0");

  m = Integer("8589934590");
  n = Integer("791621423");
  z = m / n;
  EXPECT_TRUE(z == "10");
}

TEST(Integer, Mod) {
  Integer m,n,z;

  m = Integer("inf");
  n = Integer("3");
  z = m % n;
  EXPECT_TRUE(is_nan(z));

  m = Integer("3");
  n = Integer("inf");
  z = m % n;
  EXPECT_TRUE(z == "3");

  m = Integer("7");
  n = Integer("3");
  z = m % n;
  EXPECT_TRUE(z == "1");

  m = Integer("-7");
  n = Integer("3");
  z = m % n;
  EXPECT_TRUE(z == "2");

  m = Integer("7");
  n = Integer("-3");
  z = m % n;
  EXPECT_TRUE(z == "-2");

  m = Integer("-7");
  n = Integer("-3");
  z = m % n;
  EXPECT_TRUE(z == "-1");

  m = Integer("5");
  n = Integer("11");
  z = m % n;
  EXPECT_TRUE(z == "5");

  m = Integer("-5");
  n = Integer("11");
  z = m % n;
  EXPECT_TRUE(z == "6");

  m = Integer("5");
  n = Integer("-11");
  z = m % n;
  EXPECT_TRUE(z == "-6");

  m = Integer("-5");
  n = Integer("-11");
  z = m % n;
  EXPECT_TRUE(z == "-5");
}

TEST(Integer, Shift) {
  Integer m, n, b;

  m = "4";
  b = "5";
  n = m << b;
  EXPECT_TRUE(n == "128") << "n = " << n.str();

  n = m >> b;
  EXPECT_TRUE(n == "0") << "n = " << n.str();

  m = "1000";
  b = "100";
  n = m >> b;
  EXPECT_TRUE(n == "0") << "n = " << n.str();
}

TEST(Integer, Compare) {
  Integer m, n;

  m = "4";
  n = "5";
  EXPECT_TRUE(m != n);
  EXPECT_TRUE(m < n);

  -m;
  -n;
  EXPECT_TRUE(m > n);

  m = "5";
  n = "5";
  EXPECT_TRUE(m == n);

  m = "5";
  n = "inf";
  EXPECT_TRUE(m < n);
}

TEST(Integer, Euclid) {
  Integer m, n, z;
  std::pair<Integer, Integer> st;

  m = "10";
  n = "20";
  z = gcd(m, n);
  EXPECT_TRUE(z == "10") << "z = " << z.str();

  st = extended_euclidean(m, n);
  EXPECT_TRUE(z == st.first * m + st.second * n) << "s = " << st.first.str() << " " << "t = " << st.second.str();

  m = "10";
  n = "20";
  z = lcm(m, n);
  EXPECT_TRUE(z == "20") << "z = " << z.str();

  m = "100";
  n = "25";
  z = gcd(m, n);
  EXPECT_TRUE(z == "25") << "z = " << z.str();

  st = extended_euclidean(m, n);
  EXPECT_TRUE(z == st.first * m + st.second * n) << "s = " << st.first.str() << " " << "t = " << st.second.str();

  m = "14532";
  n = "451";
  z = gcd(m, n);
  st = extended_euclidean(m, n);
  EXPECT_TRUE(z == st.first * m + st.second * n) << "s = " << st.first.str() << " " << "t = " << st.second.str();

  m = "144";
  n = "8";
  z = gcd(m, n);
  st = extended_euclidean(m, n);
  EXPECT_TRUE(z == st.first * m + st.second * n) << "s = " << st.first.str() << " " << "t = " << st.second.str();

  m = "8";
  n = "144";
  z = gcd(m, n);
  st = extended_euclidean(m, n);
  EXPECT_TRUE(z == st.first * m + st.second * n) << "s = " << st.first.str() << " " << "t = " << st.second.str();

  m = "-5";
  n = "15";
  z = gcd(m, n);
  st = extended_euclidean(m, n);
  EXPECT_TRUE(z == st.first * m + st.second * n) <<"gcd = " << z.str() << " "
                                                 << "s = " << st.first.str() << " " << "t = " << st.second.str();
}

TEST(Integer, Factorial) {
  Integer m, n;

  m = "5";
  n = factorial(m);
  EXPECT_TRUE(n == "120") << "n = " << n.str();

  m = "15";
  n = factorial(m);
  EXPECT_TRUE(n == "1307674368000") << "n = " << n.str();

  m = "25";
  n = factorial(m);
  EXPECT_TRUE(n == "15511210043330985984000000") << "n = " << n.str();
}

TEST(Integer, Pow) {
  Integer m, n, exp;

  m = "5";
  exp = "3";
  n = pow(m, exp);
  EXPECT_TRUE(n == "125") << "n = " << n.str();

  m = "2";
  exp = "8";
  n = pow(m, exp);
  EXPECT_TRUE(n == "256") << "n = " << n.str();

  m = "2";
  exp = "64";
  n = pow(m, exp);
  EXPECT_TRUE(n == "18446744073709551616") << "n = " << n.str();

  m = "2";
  exp = "128";
  n = pow(m, exp);
  EXPECT_TRUE(n == "340282366920938463463374607431768211456") << "n = " << n.str();
}

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}