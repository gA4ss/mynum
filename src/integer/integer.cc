#include <mynum/integer.h>
#include <cstring>

namespace mynum {

Integer::Integer() { nan(); }

Integer::Integer(const char* number, int base) {
  zero();
  __create_from_string(number, base);
}

Integer::Integer(std::string number, int base) {
  zero();
  __create_from_string(number.c_str(), base);
}

Integer::Integer(my::integer_t number) {
  zero();
  __create_from_string(std::to_string(number).c_str(), 10);
}

Integer::Integer(const bignum_t& number) {
  zero();
  integer_park_ = number;
}

Integer::Integer(Integer* number) {
  assign(*number);
}

Integer::Integer(const Integer& number) {
  assign(number);
}

// Integer::Integer(Float* number) {
//   zero();
//   integer_park_ = number->integer_park();
// }

// Integer::Integer(const Float& number) {
//   zero();
//   integer_park_ = number.integer_park();
// }

Integer::~Integer() {}

void Integer::assign(const Integer& n) {
  sign_ = n.sign();
  infinite_ = n.infinite();
  integer_park_ = n.integer_park();
}

void Integer::zero() {
  sign_ = kPositive;
  infinite_ = false;

  integer_park_.clear();
  integer_park_.push_back(0);
}

void Integer::one() {
  sign_ = kPositive;
  infinite_ = false;

  integer_park_.clear();
  integer_park_.push_back(1);
}

void Integer::nan() {
  sign_ = kPositive;
  infinite_ = false;
  integer_park_.clear();
}

void Integer::none() {
  sign_ = kNegative;
  infinite_ = false;
  integer_park_.clear();
}

int Integer::sign() const {
  return sign_;
}

bool Integer::infinite() const {
  return infinite_;
}

bignum_t Integer::integer_park() const {
  return integer_park_;
}

std::string Integer::str() const {
  std::string ret="";

  if (is_nan(*this)) {
    ret = "nan";
    return ret;
  }

  if (sign_ == kNegative)
    ret.push_back('-');

  // inf
  if (infinite_) {
    ret += "inf";
    return ret;
  }

  ret = bignum_to_string(integer_park_);
  return ret;
}

void Integer::set_sign(int sign) {
  if (sign <= 0) sign_ = kNegative;
  else sign_ = kPositive;
}

void Integer::set_infinite(bool infinite) {
  infinite_ = infinite;
}

void Integer::set_integer_park(const bignum_t& integer_park) { 
  integer_park_ = integer_park; 
}

void Integer::set_integer_park_zero() {
  integer_park_.clear();
  integer_park_.push_back(0);
}

static void __invalid_base(int base) {
  if (base != 10 && base != 2 && base != 8 && base != 16) {
    invalid_arguments_exception("base = %d", base);
  }
}

static bool __check_number_format(const char* number) {
  return true;
}

void Integer::__create_from_string(const char* number, int base) {
  my_assert(number, "%s", "number ptr is null.");
  __invalid_base(base);   // FIXME: 目前只支持10进制构造。
  __check_number_format(number);

  //
  // FIXME: 这里存在溢出风险。
  // strcpy,strcmp
  //

  if (strlen(number) == 0) {
    zero();
    return;
  }

  std::string number_str = number;

  // 首先判断符号
  sign_ = kPositive;
  if (number_str[0] == '-') {
    sign_ = kNegative;
    number_str.erase(0, 1);
  } else if (number_str[0] == '+') {
    number_str.erase(0, 1);
  }

  // nan
  if (number_str == "nan") {
    nan();
    return;
  }

  // inf
  if (number_str == "inf") {
    infinite_ = true;
    return;
  }

  integer_park_ = string_to_bignum(number_str.c_str(), base, true);
}

} // namespace mynum