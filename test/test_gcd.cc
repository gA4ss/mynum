#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <gtest/gtest.h>
// #include <mynum/mynum.h>
#include <mynum/wrapper.h>

using namespace mynum;

TEST(Float, GCD) {
  number_t a(121);
  number_t b(11);
  EXPECT_EQ(gcd(a, b).value(), "11");

  a = 11;
  b = 121;
  EXPECT_EQ(gcd(a, b).value(), "11");
}

TEST(Float, ExGCD) {
  number_t a(121);
  number_t b(11);
  number_t s, t;
  number_t d = extended_euclidean(a, b, s, t);
  number_t _d = s * a + t * b;
  // std::cout << "d = " << d << std::endl;
  // std::cout << "_d = " << _d << std::endl;
  EXPECT_TRUE(d == _d);
}

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}