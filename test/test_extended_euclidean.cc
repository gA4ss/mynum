#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <gtest/gtest.h>
#include <mynum/mynum.h>

using namespace mynum;

TEST(Integer, EE) {
  mynum::integer_t x = mympz::create(5);
  mynum::integer_t y = mympz::create(8);
  std::pair<integer_t, integer_t> res = z::extended_euclidean(x, y);
  // std::cout << "s = " << mympz::print_string(res.first) << std::endl;
  // std::cout << "t = " << mympz::print_string(res.second) << std::endl;
  EXPECT_TRUE(mympz::cmp(res.first, mympz::create("-3")) == 0);
  EXPECT_TRUE(mympz::cmp(res.second,mympz::create("2")) == 0);

  x = mympz::create(18);
  y = mympz::create(32);
  res = z::extended_euclidean(x, y);
  // std::cout << "s = " << mympz::print_string(res.first) << std::endl;
  // std::cout << "t = " << mympz::print_string(res.second) << std::endl;
  EXPECT_TRUE(mympz::cmp(res.first, mympz::create("-7")) == 0);
  EXPECT_TRUE(mympz::cmp(res.second,mympz::create("4")) == 0);
}

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

