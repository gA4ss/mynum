#include <mynum/real.h>
#include <cmath>

namespace mynum
{
  __real_t::__real_t()
  {
    set_int_value(0);
  }

  __real_t::__real_t(const __real_t &n)
  {
    set_num_value(n);
  }

  __real_t::__real_t(std::string n)
  {
    set_str_value(n);
  }

  __real_t::__real_t(myflt_t n)
  {
    if (static_cast<myint_t>(n) == n)
      set_int_value(n);
    else
      set_flt_value(n);
  }

  __real_t::__real_t(float_t n)
  {
    set_mpf_value(n);
  }

  __real_t::__real_t(integer_t n)
  {
    set_mpz_value(n);
  }

  __real_t::__real_t(fraction_t n)
  {
    set_frac_value(n);
  }

  std::string __real_t::value() const
  {
    std::string r = "";
    switch (__type)
    {
    case kRealTypeInteger:
      r = std::to_string(num_integer);
      break;
    case kRealTypeFloat:
      r = std::to_string(num_float);
      break;
    case kRealTypeMpz:
      r = mympz::print_string(num_mpz);
      break;
    case kRealTypeMpf:
      r = mympf::print_string(num_mpf);
      break;
    case kRealTypeFraction:
      r = mympz::print_string(num_fraction.first) + "/" +
          mympz::print_string(num_fraction.second);
      break;
    default:
      // 异常
      break;
    }
    return r;
  }

  int __real_t::type() const
  {
    return __type;
  }

#if !defined(ARCH_ARM64)
#include <cerrno>
  extern int errno;
#endif
  void __real_t::set_str_value(std::string n)
  {
    int t = my::type_of_string(n);
    switch (t)
    {
    case kStrTypeInt:
    {
      try
      {
        num_integer = std::stoll(n);
        __type = kRealTypeInteger;
      }
      catch (std::invalid_argument const &ex)
      {
        // 异常
      }
      catch (std::out_of_range const &ex)
      {
        // 转换成高精度值
        num_mpz = mympz::create(n);
        __type = kRealTypeMpz;
      }
    }
    break;
    case kStrTypeReal:
    {
// #if !defined(ARCH_ARM64)
//       try
//       {
//         num_float = std::stold(n);
//         if (errno == ERANGE)
//         {
//           // 转换成高精度值
//           num_mpf = mympf::create(n);
//           __type = kRealTypeMpf;
//         }
//         else
//         {
//           __type = kRealTypeFloat;
//         }
//       }
//       catch (std::out_of_range const &ex)
//       {
//         // 转换成高精度值
//         num_mpf = mympf::create(n);
//         __type = kRealTypeMpf;
//       }
#if defined(USE_FLOAT_MAX)
      //
      // 一个相当愚蠢的办法
      //
      float_t min_f = mympf::create(std::to_string(LDBL_MIN));
      // std::cout << LDBL_MIN << " " << std::to_string(LDBL_MIN) << std::endl;
      float_t max_f = mympf::create(std::to_string(LDBL_MAX));
      float_t curr_f = mympf::create(n);
      // std::cout << mympf::print_string(min_f) << " "
      //           << mympf::print_string(max_f) << " "
      //           << mympf::print_string(curr_f) << std::endl;
      if (curr_f.neg() == 0)
      {
        if ((cmp(max_f, curr_f) >= 0) && (cmp(curr_f, min_f) <= 0))
        {
          num_float = std::stold(n);
          __type = kRealTypeFloat;
        }
        else
        {
          num_mpf = curr_f;
          __type = kRealTypeMpf;
        }
      }
      else
      {
        min_f.set_neg(1);
        max_f.set_neg(1);
        if ((cmp(curr_f, max_f) >= 0) && (cmp(min_f, curr_f) <= 0))
        {
          num_float = std::stold(n);
          __type = kRealTypeFloat;
        }
        else
        {
          num_mpf = curr_f;
          __type = kRealTypeMpf;
        }
      }
#else
      //
      // 但凡字符串长度超过2000个字节，直接转换成大数。
      //
      if (n.size() > MAX_FLOAT_STR)
      {
        num_mpf = mympf::create(n);
        __type = kRealTypeMpf;
      }
      else
      {
        num_float = std::stold(n);
        __type = kRealTypeFloat;
      }
#endif
    }
    break;
    case kStrTypeFrac:
    {
      std::size_t pos = n.find("/");
      std::string s1 = n.substr(0, pos);
      std::string s2 = n.substr(pos + 1);
      num_fraction = {mympz::create(s1), mympz::create(s2)};
      __type = kRealTypeFraction;
    }
    break;
    default:
      // 异常
      break;
    }
  }

  void __real_t::set_num_value(const __real_t &n)
  {
    __type = n.type();
    switch (__type)
    {
    case kRealTypeInteger:
      num_integer = n.num_integer;
      break;
    case kRealTypeFloat:
      num_float = n.num_float;
      break;
    case kRealTypeMpz:
      num_mpz = n.num_mpz;
      break;
    case kRealTypeMpf:
      num_mpf = n.num_mpf;
      break;
    case kRealTypeFraction:
      num_fraction = n.num_fraction;
      break;
    default:
      num_integer = 0;
      __type = kRealTypeInteger;
      break;
    }
  }

  void __real_t::set_int_value(myint_t n)
  {
    num_integer = n;
    __type = kRealTypeInteger;
  }

  void __real_t::set_flt_value(myflt_t n)
  {
    num_float = n;
    __type = kRealTypeFloat;
  }

  void __real_t::set_mpf_value(float_t n)
  {
    num_mpf = n;
    __type = kRealTypeMpf;
  }

  void __real_t::set_mpz_value(integer_t n)
  {
    num_mpz = n;
    __type = kRealTypeMpz;
  }

  void __real_t::set_frac_value(fraction_t n)
  {
    num_fraction = n;
    __type = kRealTypeFraction;
  }

  bool test(const real_t &x, int type)
  {
    return x.type() == type;
  }

  static real_t __covert_to_frac(const real_t &x)
  {
    if (x.type() == kRealTypeFraction)
      return x;

    real_t _x;
    fraction_t fr;
    if (x.type() == kRealTypeInteger)
    {
      fr = {mympz::create(x.num_integer), mympz::create(1)};
    }
    else if (x.type() == kRealTypeFloat)
    {
      fr = f::fraction(mympf::create(x.value()));
    }
    else if (x.type() == kRealTypeMpz)
    {
      fr = {x.num_mpz, mympz::create(1)};
    }
    else if (x.type() == kRealTypeMpf)
    {
      fr = f::fraction(x.num_mpf);
    }
    _x.set_frac_value(fr);
    return _x;
  }

  static real_t __covert_to(const real_t &x, int type)
  {
    if (x.type() == type)
      return x;

    real_t y;
    std::string v = x.value();
    if (type == kRealTypeInteger)
    {
      y.set_int_value(std::stoll(v));
    }
    else if (type == kRealTypeFloat)
    {
      y.set_flt_value(std::stold(v));
    }
    else if (type == kRealTypeMpz)
    {
      y.set_mpz_value(mympz::create(v));
    }
    else if (type == kRealTypeMpf)
    {
      y.set_mpf_value(mympf::create(v));
    }
    else if (type == kRealTypeFraction)
    {
      y = __covert_to_frac(x);
    }
    return y;
  }

  real_t covert_to(const real_t &x, int type)
  {
    real_t y;
    int xtype = x.type();
    if (xtype >= type)
      return x;

    y = __covert_to(x, type);
    return y;
  }

  real_t integer_to_float(const real_t &x)
  {
    if (x.type() == kRealTypeInteger)
    {
      return __covert_to(x, kRealTypeFloat);
    }
    else if (x.type() == kRealTypeMpz)
    {
      return __covert_to(x, kRealTypeMpf);
    }
    return x;
  }

  real_t float_to_integer(const real_t &x)
  {
    real_t y;
    if (x.type() == kRealTypeFloat)
    {
      y.set_int_value(static_cast<myint_t>(x.num_float));
    }
    else if (x.type() == kRealTypeMpf)
    {
      y.set_mpz_value(mympf::integer_part(x.num_mpf).number);
    }
    return y;
  }

  std::pair<real_t, real_t> same_type(const real_t &x, const real_t &y)
  {
    if (x.type() == y.type())
      return {x, y};

    real_t _x, _y;
    if (x.type() > y.type())
    {
      _x = x;
      _y = covert_to(y, x.type());
    }
    else
    {
      _y = y;
      _x = covert_to(x, y.type());
    }
    return {_x, _y};
  }

  ////////////////////////////////////////
  //              操作符重载             //
  ////////////////////////////////////////

#if 0

  __real_t &__real_t::operator=(const __real_t &n)
  {
    set_num_value(n);
    return *this;
  }

  __real_t &__real_t::operator=(std::string n)
  {
    set_str_value(n);
    return *this;
  }

  __real_t &__real_t::operator=(myflt_t n)
  {
    set_flt_value(n);
    return *this;
  }

  __real_t &__real_t::operator=(const integer_t &n)
  {
    set_mpz_value(n);
    return *this;
  }

  __real_t &__real_t::operator=(const float_t &n)
  {
    set_mpf_value(n);
    return *this;
  }

  void __real_t::operator+=(const __real_t &n)
  {
    *this = add(*this, n);
  }

  void __real_t::operator-=(const __real_t &n)
  {
    *this = sub(*this, n);
  }

  void __real_t::operator*=(const __real_t &n)
  {
    *this = mul(*this, n);
  }

  void __real_t::operator/=(const __real_t &n)
  {
    *this = div(*this, n);
  }

  void __real_t::operator%=(const __real_t &n)
  {
    *this = mod(*this, n);
  }
#endif

} // namespace mynum