#include <mynum/bignum.h>

namespace mynum {

/* 整数部分消减 true, 小数部分消减 false。
 * 保留最后一个0。
 * 在除法中div中不能使用缩减，因为
 * 最末尾的0是为了占位。
 */
uinteger_t shrink_zero(bignum_t& a, bool reverse) {
  if (a.empty()) return 0;
  if ((a.size() == 1) && (a[0] == 0)) return 0;

  uinteger_t ret = 0;
  if (reverse) {
    int l = static_cast<int>(a.size());
    for (int i = l-1; i > 0; i--) {
      if (a[i] == 0) {
        a.pop_back(); ++ret;
      } else {
        break;
      }
    }
  } else {
    int l = static_cast<int>(a.size());
    for (int i = 0; i < l; i++) {
      if (a[i] == 0) {
        a.pop_front(); ++ret;
      } else {
        break;
      }
    }
  }
  return ret;
}

static void __invalid_base(int base) {
  if (base != 10 && base != 2 && base != 8 && base != 16) {
    invalid_arguments_exception("base = %d", base);
  }
}

static bool __check_number_format(const char* number) {
  if (number == nullptr) return false;
  char* ptr = const_cast<char*>(number);
  do {
    if (!std::isdigit(*ptr)) return false;
  } while (*(++ptr));
  return true;
}

static const unit_t kZeroCode = 48;
bignum_t string_to_bignum(const char* number, int base, bool shrink_reverse/*=false*/) {
  bignum_t res;

  if (strlen(number) == 0 || number == nullptr) {
    zero(res);
    return res;
  }

  __invalid_base(base);   // FIXME: 目前只支持10进制构造。

  // 检查number字符串的格式
  if (!__check_number_format(number)) {
    invalid_arguments_exception("number = %s", number);
  }

  char* ptr = const_cast<char*>(number);
  do {
    unit_t j = static_cast<unit_t>(*ptr - kZeroCode);
    res.push_front(j);
  } while (*(++ptr));

  shrink_zero(res, shrink_reverse);
  return res;
}

std::string bignum_to_string(bignum_t& a) {
  std::string res = "";
  char c = 0;
  for (bignum_riter_t i = a.rbegin(); i < a.rend(); i++) {
    c = static_cast<char>(*i + kZeroCode);
    res.push_back(c);
  }

  return res;
}

void zero(bignum_t& a) {
  a.clear();
  a.push_back(0);
}

bool is_zero(const bignum_t& a) {
  if (a.empty())
    return true;
  
  for (size_t i = 0; i < a.size(); i++) {
    if (a[i] != 0)
      return false;
  }
  return true;
}

int cmp(const bignum_t& a, const bignum_t& b, bool push_front/*=false*/) {
  int res = 0, l = 0;
  bignum_t _a = a, _b = b;

  if (_a.size() > _b.size()) {
    l = static_cast<int>(_a.size() - _b.size());
    for (int i = 0; i < l; i++) {
      if (push_front) _b.push_front(0);
      else _b.push_back(0);
    }
  } else if (_a.size() < _b.size()) {
    l = static_cast<int>(_b.size() - _a.size());
    for (int i = 0; i < l; i++) {
      if (push_front) _a.push_front(0);
      else _a.push_back(0);
    }
  }

  my_assert(
    _a.size() == _b.size(), 
    "(_a.size() = %d, _b.size() = %d) is not equal.", 
    _a.size(), _b.size()
  );

  l = static_cast<int>(_a.size());
  for (int i = l-1; i >= 0; i--) {
    if (_a[i] > _b[i]) {
      res = 1;
      break;
    } else if (_a[i] < _b[i]) {
      res = -1;
      break;
    }
  }
  return res;
}

} // namespace mynum