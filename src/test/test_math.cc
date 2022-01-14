#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <gtest/gtest.h>
#include <mynum/integer.h>
#include <mynum/float.h>
#include <mynum/math.h>

using namespace mynum;

TEST(Math, Type) {
  Integer n = 1210;
  Float f = 3.1415926;
  EXPECT_TRUE(my::get_type_name<Integer>() == "N5mynum7IntegerE");
  EXPECT_TRUE(my::get_type_name<Float>() == "N5mynum5FloatE");
  EXPECT_TRUE(my::get_support_type<Integer>() == my::kBIntegerT);
  EXPECT_TRUE(my::get_support_type<Float>() == my::kBFloatT);
}

TEST(Math, abs) {
  EXPECT_TRUE(abs(Float(-1.1)) == "1.1");
  EXPECT_TRUE(abs(Integer(1001)) == 1001);
}

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}