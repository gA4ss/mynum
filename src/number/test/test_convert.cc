
#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <gtest/gtest.h>
#include <mynum/number/convert.h>

using namespace mynum::core;
using namespace mynum::number;

TEST(Number, ConvertObject) {
  mynum_number_t obj1 = create_object<Complex>();
  mynum_complex_t comp_obj = convert_to_complex(obj1);
  EXPECT_TRUE(comp_obj != nullptr) << "class type = " << comp_obj->class_name();
  EXPECT_FALSE(is_real(comp_obj));
  EXPECT_FALSE(is_integer(comp_obj));

  mynum_number_t obj2 = create_object<Real>();
  mynum_real_t real_obj = convert_to_real(obj2);
  EXPECT_TRUE(real_obj != nullptr) << "class type = " << real_obj->class_name();
  EXPECT_FALSE(is_complex(real_obj));
  EXPECT_FALSE(is_integer(real_obj));

  mynum_number_t obj3 = create_object<Integer>();
  mynum_integer_t integer_obj = convert_to_integer(obj3);
  EXPECT_TRUE(integer_obj != nullptr) << "class type = " << integer_obj->class_name();
  EXPECT_FALSE(is_complex(integer_obj));
  EXPECT_FALSE(is_real(integer_obj));
}

TEST(Number, ConvertPtr) {
  Number* obj1 = new Complex;
  Complex* comp_obj = convert_to_complex_ptr(obj1);
  EXPECT_TRUE(comp_obj != nullptr);
  EXPECT_FALSE(is_real_ptr(comp_obj));
  EXPECT_FALSE(is_integer_ptr(comp_obj));

  Number* obj2 = new Real;
  Real* real_obj = convert_to_real_ptr(obj2);
  EXPECT_TRUE(real_obj != nullptr);
  EXPECT_FALSE(is_complex_ptr(real_obj));
  EXPECT_FALSE(is_integer_ptr(real_obj));

  Number* obj3 = new Integer;
  Integer* integer_obj = convert_to_integer_ptr(obj3);
  EXPECT_TRUE(integer_obj != nullptr);
  EXPECT_FALSE(is_complex_ptr(integer_obj));
  EXPECT_FALSE(is_real_ptr(integer_obj));
}

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}