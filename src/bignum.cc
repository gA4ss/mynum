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
bignum_t string_to_bignum(const char* number, int base) {
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

int cmp(const bignum_t& a, const bignum_t& b) {
  int res = 0, l = 0;
  bignum_t _a = a, _b = b;
  if (_a.size() > _b.size()) {
    l = static_cast<int>(_a.size() - _b.size());
    for (int i = 0; i < l; i++)
      _b.push_back(0);
  } else if (_a.size() < _b.size()) {
    l = static_cast<int>(_b.size() - _a.size());
    for (int i = 0; i < l; i++)
      _a.push_back(0);
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

bignum_t add(const bignum_t& a, const bignum_t& b, unit_t o) {
  bignum_t x, y, z;
  if (a.empty() && !b.empty()) {
    x.push_back(0);
    y = b;
  } else if (!a.empty() && b.empty()) {
    x = a;
    y.push_back(0);
  } else if (a.empty() && b.empty()) {
    x.push_back(0);
    y.push_back(0);
  } else {
    x = a;
    y = b;
  }

  if (x.size() > y.size()) {
    y.resize(x.size());
  } else if (x.size() < y.size()) {
    x.resize(y.size());
  }

  unit_t c = 0, r = o;
  size_t l = x.size();
  for (size_t i = 0; i < l; i++) {
    c = x[i] + y[i] + r;
    if (c >= 10) {
      c = c - 10;
      r = 1;
    } else {
      r = 0;
    }
    z.push_back(c);
  }
  // 如果存在进位则保存
  if (r) z.push_back(r);
  return z;
}

bignum_t sub(bignum_t& a, bignum_t& b, bool t=false) {
  bignum_t x, y, z;

  if (a.empty() && !b.empty()) {
    x.push_back(0);
    y = b;
  } else if (!a.empty() && b.empty()) {
    x = a;
    y.push_back(0);
  } else if (a.empty() && b.empty()) {
    x.push_back(0);
    y.push_back(0);
  } else {
    x = a;
    y = b;
  }

  //
  // x比 y小则交换两者位置
  //
  if (cmp(x, y) < 0) {
    z = x;
    x = y;
    y = z;
    z.clear();
  }

  if (x.size() > y.size()) {
    y.resize(x.size());
  } else if (x.size() < y.size()) {
    x.resize(y.size());
  }

  unit_t r = static_cast<unit_t>(t), c = 0;
  size_t l = x.size();
  for (size_t i = 0; i < l; i++) {
    if (x[i] - r >= y[i]) {
      c = x[i] - y[i] - r;
      r = 0;
    } else {
      c = x[i] + 10 - y[i] - r;
      r = 1;
    }
    z.push_back(c);
  }
  if (r != 0) {
    r = 1;
  }
  my_assert(r == 0, "%s", "borrow must be 0.");
  return z;
}

bignum_t mul(const bignum_t& a, const bignum_t& b) {
  if (a.empty() || b.empty()) {
    bignum_t c = {0};
    return c;
  }
  bignum_t x, y, z;
  size_t m = 0, n = 0;

  // 保证 m >= n
  if (a.size() >= b.size()) {
    x = a; m = a.size();
    y = b; n = b.size();
  } else if (a.size() < b.size()) {
    y = a; n = a.size();
    x = b; m = b.size();
  }
  z.resize(m+n);

  unit_t q = 0, t = 0;
  for (size_t j = 0; j < n; j++) {
    q = 0;
    for (size_t i = 0; i < m; i++) {
      t = x[i] * y[j] + z[i+j] + q;
      z[i+j] = t % 10;
      q = t / 10;
    }
    z[j+m] = q;
  }
  return z;
}

// bignum_t mul(const bignum_t& a, const bignum_t& b) {
//   if (a.empty() || b.empty()) {
//     bignum_t c = {0};
//     return c;
//   }
//   bignum_t x, y, z;
//   size_t m = 0, n = 0;

//   // 保证 m >= n
//   if (a.size() >= b.size()) {
//     x = a; m = a.size();
//     y = b; n = b.size();
//   } else if (a.size() < b.size()) {
//     y = a; n = a.size();
//     x = b; m = b.size();
//   }
//   z.resize(m+n);

//   unit_t q = 0, t = 0;
//   for (size_t j = 0; j < n; j++) {
//     q = 0;
//     for (size_t i = 0; i < m; i++) {
//       t = x[i] * y[j] + z[i+j] + q;
//       z[i+j] = t % 10;
//       q = t / 10;
//     }
//     z[j+m] = q;
//   }

//   __shrink_zero(z, true);
//   return z;
// }

/*
 * a1表示a的首项系数，以此类推。B为某个进制。
 * 1.当a,b的位数一致，a1 >= b1，a > b。
 *  1-1 : a1 = b1 ---> q = 1.
 *  1-2 : a1 > b1 ---> q1 = floor(a_1/b_1), q2 = max(floor( (a1*B+a2-B+1) / (b1*B+b2)) ), 1)
 *        q1 <= q <= q2
 * 2.当a的位数比b大一位，a1 <= b1，a > b, a < b*B(仅差一位)。
 *  2-1 : q1 = min(floor( (a1*B+a2) / b1 ), B-1)
 *        q <= q1
 * 证明见《计算机代数》【陈玉福，张智勇】 25-26页。
 */
// static std::pair<unit_t, unit_t> __get_quotient_range(const bignum_t& a, const bignum_t& b) {
//   const unit_t B = 10;
//   unit_t a1 = *(a.end()-1), b1 = *(b.end()-1);
//   unit_t a2 = 0, b2 = 0;

//   if (a.size() >= 2) a2 = *(a.end()-2);
//   if (b.size() >= 2) b2 = *(b.end()-2);

//   if (a.size() == b.size()) {
//     //
//     // 第一种情况
//     //
//     if (a1 == b1)
//       return std::make_pair(1, 1);
//     else { // 这里一定是 a1 > b1
//       my_assert(a1 > b1, "a1(%d) < b1(%d)", a1, b1);
//       unit_t q1 = a1 / b1, q2 = std::max((a1*B+a2-B+1)/(b1*B+b2), 1);
//       return q1 < q2 ? std::make_pair(q1, q2) : std::make_pair(q2, q1);
//     }
//   } else {
//     //
//     // 第二种情况
//     //
//     unit_t q = std::min((a1*B+a2)/b1, B-1);
//     return std::make_pair(1, q);
//   }
//   my_assert(false, "%s", "never go here!");
//   return std::make_pair(0, 0);
// }

// /* 不考虑符号，这里保证b不为0。 */
// bignum_t div(const bignum_t& a, const bignum_t& b, 
//               uinteger_t max_quotient_borrow, 
//               uinteger_t* m=nullptr) {
//   //const bignum_t ten = {0, 1};    // 表示10
//   bignum_t x = a, y = b;

//   if (__cmp(x, y) == 0) {
//     return {1};
//   }

//   bignum_t quotient, product, dividend = x, divisor = y, remainder = {0};
//   uinteger_t dividend_remainder_digits = dividend.size(), multiple = 0; // 这里扩大了多少倍，返回结果缩小多少倍。

//   //
//   // 这里对被除数与除数做一些初始化工作
//   //
//   int cmp = __cmp(dividend, divisor);
//   if (cmp == -1) {
//     while (__cmp(dividend, divisor) == -1) {
//       dividend.push_front(0); // dividend = __mul(dividend, ten);
//       quotient.push_front(0);
//       ++multiple;
//     }
//     dividend_remainder_digits = 0;
//   } else { // cmp == 1
//     //
//     // 从末尾取a与b相同的位数 : a_n, b_n
//     // 如果 a_n < b_n, 则取a_{n+1}
//     //
//     size_t n = divisor.size();
//     dividend_remainder_digits -= n;
//     dividend = bignum_t(x.begin()+dividend_remainder_digits, x.end());
//     if (__cmp(dividend, divisor) == -1) {
//       // 如果小于这里dividend必比divisor多一位。
//       --dividend_remainder_digits;
//       dividend = bignum_t(x.begin()+dividend_remainder_digits, x.end());
//     }
//   }

//   // 第一次运行必须保证被除数大于除数。
//   while (true) {
//     // 尝试获取商的范围。
//     std::pair<unit_t, unit_t> quo_range = __get_quotient_range(dividend, divisor);
//     unit_t q = 0;
//     for (q = quo_range.first; q <= quo_range.second; q++) {
//       product = __mul(divisor, {q});
//       //
//       // product 必然小于等于 dividend
//       //
//       remainder = __sub_integer_park(dividend, product, false);
//       int c = __cmp(divisor, remainder);
//       if ((c == -1) || (c == 0)) {
//         continue;
//       } else {
//         quotient.push_front(q);
//         break;
//       }
//     }

//     //
//     // 算法结束条件： 1，2需要同时满足。3是单独满足即可。
//     // 1.检查余数如果为0。
//     // 2.被除数没有多余的位。
//     // 3.商的精度足够了。
//     //
//     // FIXME : 这里存在一个BUG。当 1 / 小数位数很多超过 max_quotient_borrow
//     //         那么这里会因为借位耗禁而终止运算，造成误差过大。
//     //
//     if ((__cmp(remainder, {0}) == 0) && (dividend_remainder_digits == 0))
//       break;
//     if (max_quotient_borrow != kNumericUnitMax) {
//       if (multiple >= max_quotient_borrow) {
//         break;
//       }
//     }

//     //
//     // 更新被除数
//     //
//     dividend = remainder;
//     if (dividend_remainder_digits == 0) {
//       //
//       // 这里其实有个隐含条件就是余数不为0。因为到达这里余数肯定不为零。
//       // 上面的退出条件已经判断了。 
//       // my_assert(__cmp(remainder, {0}) != 0, "%s", "remainder is zero!");
//       //
//       while (__cmp(dividend, divisor) == -1) {
//         dividend.push_front(0); // dividend = __mul(dividend, ten);
//         quotient.push_front(0);
//         ++multiple;
//       }
//       //
//       // 这里不存在借用被除数的位。所以
//       // 商的0要比被除数少一个
//       //
//       quotient.pop_front();
//     } else {
//       if (__cmp(dividend, {0}) == 0) dividend.clear();  // 余数为零。
//       //
//       // 这里首先借一位，如果大于则直接做运算。
//       // 如果还是小于则商使用0补位。
//       // 保证被除数大于除数。
//       //
//       if ((__cmp(dividend, divisor) == -1) && (dividend_remainder_digits != 0)) {
//         dividend.push_front(x[dividend_remainder_digits-1]);
//         --dividend_remainder_digits;
//         //
//         // 这里如果借了一位还是小于那么开始补位
//         //
//         while ((__cmp(dividend, divisor) == -1) && (dividend_remainder_digits != 0)) {
//           dividend.push_front(x[dividend_remainder_digits-1]);
//           quotient.push_front(0);
//           --dividend_remainder_digits;
//         }
//       }

//       //
//       // 如果被除数剩余全部是0，这里蕴含的一个条件就是 dividend_remainder_digits为0。
//       // quotient压入0比dividend少一个。
//       //
//       if (__cmp(dividend, {0}) == 0) {
//         // quotient.insert(quotient.begin(), dividend.begin(), dividend.end());
//         quotient.push_front(0);
//         break;
//       }

//       //
//       // 如果进入循环说明 dividend_remainder_digits == 0，
//       // 这时候如果dividend仍然小于divisor则进行借位。
//       // 因为这边是正常补位所以不进行弹出了。
//       //
//       while (__cmp(dividend, divisor) == -1) {
//         dividend.push_front(0); // dividend = __mul(dividend, ten);
//         quotient.push_front(0);
//         ++multiple;
//       }
//       //
//       // 例如：10001 / 2 这种情况，可能造成 dividend = 0010
//       // 这里将前面两个0清除。
//       //
//       if (dividend.back() == 0) __shrink_zero(dividend, true);
//     }
//   }/* end while */

//   if(m) *m = multiple;
//   return quotient;
// }

} // namespace mynum