#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <gtest/gtest.h>
#include <mynum/number/complex.h>
#include <mynum/number/real.h>
#include <mynum/number/integer.h>

using namespace mynum::core;
using namespace mynum::number;

TEST(Number, ComplexCreate) {
  Complex c("3.1415926+1.618i");
  EXPECT_STREQ(c.str().c_str(), "3.1415926+1.618i");
  c = "3.1415926";
  EXPECT_STREQ(c.str().c_str(), "3.1415926");
  c = "+3.1415926";
  EXPECT_STREQ(c.str().c_str(), "3.1415926");
  c = "1.618i";
  EXPECT_STREQ(c.str().c_str(), "1.618i");
  c = "+1.618i";
  EXPECT_STREQ(c.str().c_str(), "1.618i");

  c = "-1.618i";
  EXPECT_STREQ(c.str().c_str(), "-1.618i");

  c = "+123-1.618i";
  EXPECT_STREQ(c.str().c_str(), "123-1.618i");
}

TEST(Number, ComplexSingleOpt) {
  Complex c("3+1i");
  Complex d = c++;
  EXPECT_TRUE(d == "3+1i") << "d = " << d.str();
  ++c;
  EXPECT_TRUE(c == "5+3i") << "c = " << d.str();
  --c;
  EXPECT_TRUE(c == "4+2i") << "c = " << d.str();
}

TEST(Number, ComplexOperation) {
  Complex a = "123+5i", b = "542-3i";
  Complex c = a * b;
  EXPECT_TRUE(c == "66681+2341i") << "c = " << c.str();

  a = "123+5i", b = "542-3i";
  c = a + b;
  EXPECT_TRUE(c == "665+2i") << "c = " << c.str();

  a = "123+5i", b = "542-3i";
  c = a - b;
  EXPECT_TRUE(c == "-419+8i") << "c = " << c.str();

  a = "123+5i", b = "542-3i";
  c = a / b;
  EXPECT_TRUE(abs(c.real_park() - "0.22687925711348556") < "0.0000000001") << "c.real_park() = " 
                                                                                    << c.real_park().str();
  Numeric debug = abs(c.imaginary_park() - "0.010480881496938111");
  // std::cout << "debug = " << debug.str() << std::endl;
  EXPECT_TRUE(abs(c.imaginary_park() - "0.010480881496938111") < "0.0000000001") << "c.imaginary_park - 0.010480881496938111 = " 
                                                                                          << abs(c.imaginary_park() - "0.010480881496938111").str();
}

TEST(Number, Integer) {
  Integer i = "3.1415926", j = "4.43";
  EXPECT_TRUE(i == "3") << "i = " << i.str();
  EXPECT_TRUE(j == "4") << "j = " << j.str();

  Integer g = gcd(i, j);
  EXPECT_TRUE(g == "1") << "g = " << g.str();

  std::pair<Integer, Integer> st;
  Integer k;

  i = "10";
  j = "20";
  k = gcd(i, j);
  st = extended_euclidean(i, j);
  EXPECT_TRUE(k == st.first * i + st.second * j) <<"gcd = " << k.str() << " "
                                                 << "s = " << st.first.str() << " " << "t = " << st.second.str();

  i = "-55";
  j = "54535";
  k = gcd(i, j);
  st = extended_euclidean(i, j);
  EXPECT_TRUE(k == st.first * i + st.second * j) <<"gcd = " << k.str() << " "
                                                 << "s = " << st.first.str() << " " << "t = " << st.second.str();

  i = "4580";
  j = "-4123";
  k = gcd(i, j);
  st = extended_euclidean(i, j);
  EXPECT_TRUE(k == st.first * i + st.second * j) <<"gcd = " << k.str() << " "
                                                 << "s = " << st.first.str() << " " << "t = " << st.second.str();

  i = "121";
  j = "11";
  k = gcd(i, j);
  st = extended_euclidean(i, j);
  EXPECT_TRUE(k == st.first * i + st.second * j) <<"gcd = " << k.str() << " "
                                                 << "s = " << st.first.str() << " " << "t = " << st.second.str();

  i = "654";
  j = "374";
  k = gcd(i, j);
  st = extended_euclidean(i, j);
  EXPECT_TRUE(k == st.first * i + st.second * j) <<"gcd = " << k.str() << " "
                                                 << "s = " << st.first.str() << " " << "t = " << st.second.str();

  i = "98776";
  j = "4567";
  k = gcd(i, j);
  st = extended_euclidean(i, j);
  EXPECT_TRUE(k == st.first * i + st.second * j) <<"gcd = " << k.str() << " "
                                                 << "s = " << st.first.str() << " " << "t = " << st.second.str();
}

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}