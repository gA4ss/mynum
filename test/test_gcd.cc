#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <gtest/gtest.h>
#include <mynum/mynum.h>

using namespace mynum;

TEST(Float, GCD) {
  number_t a(121);
  number_t b(11);
  EXPECT_EQ(gcd(a, b).value(), "11");
}

TEST(Float, ExGCD) {
  number_t a(121);
  number_t b(11);
  number_t s, t;
  number_t d = extended_euclidean(a, b, s, t);
  EXPECT_EQ(d.num_integer, s.num_integer*a.num_integer+t.num_integer*b.num_integer);
}

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}