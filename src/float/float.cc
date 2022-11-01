#include <mynum/float.h>
#include <mynum/constant.h>

#include <cstring>

namespace mynum {

Float::Float() { nan(); }

Float::Float(const char* number, int base) {
  zero();
  __create_from_string(number, base);
}

Float::Float(std::string number, int base) {
  zero();
  __create_from_string(number.c_str(), base);
}

Float::Float(my::float_t number) {
  zero();
  std::stringstream ss;
  // ss << std::setiosflags(std::ios::fixed) << number;
  ss << std::setprecision(__config.set_precision) << number;
  std::string s = ss.str();
  __create_from_string(s.c_str(), 10);
}

Float::Float(const bignum_t& integer_park) {
  zero();
  integer_park_ = integer_park;
  decimal_park_ = {0};
}

Float::Float(const bignum_t& integer_park, const bignum_t& decimal_park) {
  zero();
  integer_park_ = integer_park;
  decimal_park_ = decimal_park;
}

Float::Float(const Integer& integer_park, const Integer& decimal_park) {
  zero();
  integer_park_ = integer_park.integer_park();
  decimal_park_ = decimal_park.integer_park();
  sign_ = integer_park.sign();
}

Float::Float(Integer* number) {
  zero();
  integer_park_ = number->integer_park();
  sign_ = number->sign();
}

Float::Float(const Integer& number) {
  zero();
  integer_park_ = number.integer_park();
  sign_ = number.sign();
}

Float::Float(Float* number) {
  assign(*number);
}

Float::Float(const Float& number) {
  assign(number);
}

Float::~Float() {}

void Float::assign(const Float& number) {
  sign_ = number.sign();
  infinite_ = number.infinite();
  integer_park_ = number.integer_park();
  decimal_park_ = number.decimal_park();
}

void Float::zero() {
  sign_ = kPositive;
  infinite_ = false;
  integer_park_ = {0};
  decimal_park_ = {0};
}

void Float::one() {
  sign_ = kPositive;
  infinite_ = false;
  integer_park_ = {1};
  decimal_park_ = {0};
}

void Float::nan() {
  sign_ = kPositive;
  infinite_ = false;
  integer_park_.clear();
  decimal_park_.clear();
}

void Float::none() {
  sign_ = kNegative;
  infinite_ = false;
  integer_park_.clear();
  decimal_park_.clear();
}

int Float::sign() const {
  return sign_; 
}

bool Float::infinite() const {
  return infinite_;
}

bignum_t Float::integer_park() const {
  return integer_park_;
}

bignum_t Float::decimal_park() const {
  return decimal_park_;
}

size_t Float::precision() const {
  return decimal_park_.size();
}

std::string Float::str() const {
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

  ret += bignum_to_string(integer_park_);
  if (!decimal_park_.empty()) {
    ret.push_back('.');
    ret += bignum_to_string(decimal_park_);
  }
  return ret;
}

void Float::set_sign(int sign) {
  if (sign <= 0) sign_ = kNegative;
  else sign_ = kPositive;
}

void Float::set_infinite(bool infinite) {
  infinite_ = infinite;
}

void Float::set_integer_park(const bignum_t& integer_park) {
  integer_park_ = integer_park;
}

void Float::set_decimal_park(const bignum_t& decimal_park) {
  decimal_park_ = decimal_park;
}

void Float::set_integer_park_zero() {
  integer_park_ = {0};
}

void Float::set_decimal_park_zero() {
  decimal_park_ = {0};
}

static void __invalid_base(int base) {
  if (base != 10 && base != 2 && base != 8 && base != 16) {
    invalid_arguments_exception("base = %d", base);
  }
}

static bool __check_number_format(const char* number) {
  return true;
}

void Float::__create_from_string(const char* number, int base) {
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
  // size_t length = number_str.size();

  // 首先判断符号
  if (number_str[0] == '-') {
    sign_ = kNegative;
    number_str.erase(0, 1);
  } else if (number_str[0] == '+') {
    sign_ = kPositive;
    number_str.erase(0, 1);
  } else {
    sign_ = kPositive;
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

  //
  // 这里分为两部分处理,整数部分与小数部分
  //
  std::string integer_str = "", decimal_str = "";
  my::uinteger_t precision = 0;
  std::size_t found = number_str.find('.');
  if (found != std::string::npos) {
    integer_str = number_str.substr(0, found);
    decimal_str = number_str.substr(found + 1);
    precision = 1;
  } else {
    integer_str = number_str;
    precision = 0;
  }

  if (integer_str.empty()) integer_str = "0";

  integer_park_ = string_to_bignum(integer_str.c_str(), base, true);
  if (precision) decimal_park_ = string_to_bignum(decimal_str.c_str(), base, false);
  else decimal_park_ = {0};

  // precision = decimal_park_.size();
  // shrink_zero(integer_park_, true);
  // shrink_zero(decimal_park_, false);
}

} // namespace mynum