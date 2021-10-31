#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <gtest/gtest.h>
#include <mynum/bignum.h>

using namespace mynum;

TEST(BigNum, Create) {
  bignum_t a = string_to_bignum("123456789");
  std::string a_str = bignum_to_string(a);
  EXPECT_TRUE(a_str == "123456789") << "a = " << a_str;
}

TEST(BigNum, Mul) {
  bignum_t a = string_to_bignum("123456789");
  std::string a_str = bignum_to_string(a);
  EXPECT_TRUE(a_str == "123456789") << "a = " << a_str;
}

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}