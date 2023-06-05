#include <mynum/mynum.h>
#include <cmath>
namespace mynum
{
  __number_t::__number_t()
  {
    set_int_value(0);
  }

  __number_t::__number_t(std::string n)
  {
    set_str_value(n);
  }

  __number_t::__number_t(myflt_t n)
  {
    if (static_cast<myint_t>(n) == n)
      set_int_value(n);
    else
      set_flt_value(n);
  }

  __number_t::__number_t(float_t n)
  {
    set_mpf_value(n);
  }
  
  __number_t::__number_t(integer_t n)
  {
    set_mpz_value(n);
  }
  
  __number_t::__number_t(fraction_t n)
  {
    set_frac_value(n);
  }

  std::string __number_t::value() const
  {
    std::string r = "";
    switch (__type)
    {
      case kNumTypeInteger:
        r = std::to_string(num_integer);
      break;
      case kNumTypeFloat:
        r = std::to_string(num_float);
      break;
      case kNumTypeMpz:
        r = mympz::print_string(num_mpz);
      break;
      case kNumTypeMpf:
        r = mympf::print_string(num_mpf);
      break;
      case kNumTypeFraction:
        r = mympz::print_string(num_fraction.first) + "/" + 
            mympz::print_string(num_fraction.second);
      break;
      default:
        // 异常
      break;
    }
    return r;
  }

  std::string __number_t::value()
  {
    std::string r = "";
    switch (__type)
    {
      case kNumTypeInteger:
        r = std::to_string(num_integer);
      break;
      case kNumTypeFloat:
        r = std::to_string(num_float);
      break;
      case kNumTypeMpz:
        r = mympz::print_string(num_mpz);
      break;
      case kNumTypeMpf:
        r = mympf::print_string(num_mpf);
      break;
      case kNumTypeFraction:
        r = mympz::print_string(num_fraction.first) + "/" + 
            mympz::print_string(num_fraction.second);
      break;
      default:
        // 异常
      break;
    }
    return r;
  }

  int __number_t::type() const
  {
    return __type;
  }

  int __number_t::type()
  {
    return __type;
  }

#if !defined(ARCH_ARM64)
  #include <cerrno> 
  extern int errno;
#endif
  void __number_t::set_str_value(std::string n)
  {
    int t = my::type_of_string(n);
    switch (t)
    {
      case kStrTypeInt:
      {
        try
        {
          num_integer = std::stoll(n);
          __type = kNumTypeInteger;
        }
        catch(std::invalid_argument const& ex)
        {
          // 异常
        }
        catch(std::out_of_range const& ex)
        {
          // 转换成高精度值
          num_mpz = mympz::create(n);
          __type = kNumTypeMpz;
        }
      }break;
      case kStrTypeReal:
      {
#if !defined(ARCH_ARM64)
        try
        {
          num_float = std::stold(n);
          if (errno == ERANGE)
          {
            // 转换成高精度值
            num_mpf = mympf::create(n);
            __type = kNumTypeMpf;
          }
          else
          {
            __type = kNumTypeFloat;
          }
        }
        catch(std::out_of_range const& ex)
        {
          // 转换成高精度值
          num_mpf = mympf::create(n);
          __type = kNumTypeMpf;
        }
#else
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
            __type = kNumTypeFloat;
          }
          else
          {
            num_mpf = curr_f;
            __type = kNumTypeMpf;
          }
        }
        else
        {
          min_f.set_neg(1); max_f.set_neg(1);
          if ((cmp(curr_f, max_f) >= 0) && (cmp(min_f, curr_f) <= 0))
          {
            num_float = std::stold(n);
            __type = kNumTypeFloat;
          }
          else
          {
            num_mpf = curr_f;
            __type = kNumTypeMpf;
          }
        }
#endif
      }break;
      case kStrTypeFrac:
      {
        std::size_t pos = n.find("/");
        std::string s1 = n.substr(0, pos);
        std::string s2 = n.substr(pos+1);
        num_fraction = {mympz::create(s1), mympz::create(s2)};
        __type = kNumTypeFraction;
      }break;
      default:
        // 异常
        break;
    }
  }

  void __number_t::set_int_value(myint_t n)
  {
    num_integer = n;
    __type = kNumTypeInteger;
  }

  void __number_t::set_flt_value(myflt_t n)
  {
    num_float = n;
    __type = kNumTypeFloat;
  }

  void __number_t::set_mpf_value(float_t n)
  {
    num_mpf = n;
    __type = kNumTypeMpf;
  }

  void __number_t::set_mpz_value(integer_t n)
  {
    num_mpz = n;
    __type = kNumTypeMpz;
  }

  void __number_t::set_frac_value(fraction_t n)
  {
    num_fraction = n;
    __type = kNumTypeFraction;
  }

  bool test(const number_t &x, int type)
  {
    return x.type() == type;
  }

  static number_t __covert_to_frac(const number_t &x)
  {
    if (x.type() == kNumTypeFraction)
      return x;

    number_t _x;
    fraction_t fr;
    if (x.type() == kNumTypeInteger)
    {
      fr = {mympz::create(x.num_integer), mympz::create(1)};
    }
    else if (x.type() == kNumTypeFloat)
    {
      fr = f::fraction(mympf::create(x.value()));
    }
    else if (x.type() == kNumTypeMpz)
    {
      fr = {x.num_mpz, mympz::create(1)};
    }
    else if (x.type() == kNumTypeMpf)
    {
      fr = f::fraction(x.num_mpf);
    }
    _x.set_frac_value(fr);
    return _x;
  }

  static number_t __covert_to(const number_t &x, int type)
  {
    if (x.type() == type)
      return x;

    number_t y;
    std::string v = x.value();
    if (type == kNumTypeInteger)
    {
      y.set_int_value(std::stoll(v));
    }
    else if (type == kNumTypeFloat)
    {
      y.set_flt_value(std::stold(v));
    }
    else if (type == kNumTypeMpz)
    {
      y.set_mpz_value(mympz::create(v));
    }
    else if (type == kNumTypeMpf)
    {
      y.set_mpf_value(mympf::create(v));
    }
    else if (type == kNumTypeFraction)
    {
      y = __covert_to_frac(x);
    }
    return y;
  }

  number_t covert_to(const number_t &x, int type)
  {
    number_t y;
    int xtype = x.type();
    if (xtype >= type)
      return x;

    y = __covert_to(x, type);
    return y;
  }

  std::pair<number_t, number_t> same_type(const number_t &x, const number_t &y)
  {
    if (x.type() == y.type())
      return {x, y};

    number_t _x, _y;
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

  number_t add(const number_t &x, const number_t &y)
  {
    std::pair<number_t, number_t> xy = same_type(x, y);
    number_t _x = xy.first, _y = xy.second, z;
    int type = _x.type();
    if (type == kNumTypeInteger)
    {
      z.set_int_value(_x.num_integer + _y.num_integer);
    }
    else if (type == kNumTypeFloat)
    {
      z.set_flt_value(_x.num_float + _y.num_float);
    }
    else if (type == kNumTypeMpz)
    {
      z.set_mpz_value(mympz::add(_x.num_mpz, _y.num_mpz));
    }
    else if (type == kNumTypeMpf)
    {
      z.set_mpf_value(mympf::add(_x.num_mpf, _y.num_mpf));
    }
    else if (type == kNumTypeFraction)
    {
      z.set_frac_value(f::add(_x.num_fraction, _y.num_fraction));
    }
    return z;
  }

  number_t sub(const number_t &x, const number_t &y)
  {
    std::pair<number_t, number_t> xy = same_type(x, y);
    number_t _x = xy.first, _y = xy.second, z;
    int type = _x.type();
    if (type == kNumTypeInteger)
    {
      z.set_int_value(_x.num_integer - _y.num_integer);
    }
    else if (type == kNumTypeFloat)
    {
      z.set_flt_value(_x.num_float - _y.num_float);
    }
    else if (type == kNumTypeMpz)
    {
      z.set_mpz_value(mympz::sub(_x.num_mpz, _y.num_mpz));
    }
    else if (type == kNumTypeMpf)
    {
      z.set_mpf_value(mympf::sub(_x.num_mpf, _y.num_mpf));
    }
    else if (type == kNumTypeFraction)
    {
      z.set_frac_value(f::sub(_x.num_fraction, _y.num_fraction));
    }
    return z;
  }

  number_t mul(const number_t &x, const number_t &y)
  {
    std::pair<number_t, number_t> xy = same_type(x, y);
    number_t _x = xy.first, _y = xy.second, z;
    int type = _x.type();
    if (type == kNumTypeInteger)
    {
      z.set_int_value(_x.num_integer * _y.num_integer);
    }
    else if (type == kNumTypeFloat)
    {
      z.set_flt_value(_x.num_float * _y.num_float);
    }
    else if (type == kNumTypeMpz)
    {
      z.set_mpz_value(mympz::mul(_x.num_mpz, _y.num_mpz));
    }
    else if (type == kNumTypeMpf)
    {
      z.set_mpf_value(mympf::mul(_x.num_mpf, _y.num_mpf));
    }
    else if (type == kNumTypeFraction)
    {
      z.set_frac_value(f::mul(_x.num_fraction, _y.num_fraction));
    }
    return z;
  }

  number_t div(const number_t &x, const number_t &y)
  {
    std::pair<number_t, number_t> xy = same_type(x, y);
    number_t _x = xy.first, _y = xy.second, z;
    int type = _x.type();
    if (type == kNumTypeInteger)
    {
      z.set_int_value(_x.num_integer / _y.num_integer);
    }
    else if (type == kNumTypeFloat)
    {
      z.set_flt_value(_x.num_float / _y.num_float);
    }
    else if (type == kNumTypeMpz)
    {
      z.set_mpz_value(mympz::idiv(_x.num_mpz, _y.num_mpz));
    }
    else if (type == kNumTypeMpf)
    {
      z.set_mpf_value(mympf::div(_x.num_mpf, _y.num_mpf));
    }
    else if (type == kNumTypeFraction)
    {
      z.set_frac_value(f::div(_x.num_fraction, _y.num_fraction));
    }
    return z;
  }

  number_t idiv(const number_t &x, const number_t &y)
  {
    std::pair<number_t, number_t> xy = same_type(x, y);
    number_t _x = xy.first, _y = xy.second, z;
    int type = _x.type();
    if (type == kNumTypeInteger)
    {
      z.set_int_value(_x.num_integer / _y.num_integer);
    }
    else if (type == kNumTypeFloat)
    {
      myint_t r = static_cast<myint_t>(_x.num_float / _y.num_float);
      z.set_flt_value(static_cast<myflt_t>(r));
    }
    else if (type == kNumTypeMpz)
    {
      z.set_mpz_value(mympz::idiv(_x.num_mpz, _y.num_mpz));
    }
    else if (type == kNumTypeMpf)
    {
      z.set_mpf_value(mympf::idiv(_x.num_mpf, _y.num_mpf));
    }
    else if (type == kNumTypeFraction)
    {
      z.set_frac_value(f::div(_x.num_fraction, _y.num_fraction));
    }
    return z;
  }

  number_t mod(const number_t &x, const number_t &y)
  {
    std::pair<number_t, number_t> xy = same_type(x, y);
    number_t _x = xy.first, _y = xy.second, z;
    int type = _x.type();
    if (type == kNumTypeInteger)
    {
      z.set_int_value(_x.num_integer % _y.num_integer);
    }
    else if (type == kNumTypeFloat)
    {
      myint_t r = static_cast<myint_t>(_x.num_float) % static_cast<myint_t>(_y.num_float);
      z.set_flt_value(static_cast<myflt_t>(r));
    }
    else if (type == kNumTypeMpz)
    {
      z.set_mpz_value(mympz::mod(_x.num_mpz, _y.num_mpz));
    }
    else if (type == kNumTypeMpf)
    {
      z.set_mpf_value(mympf::mod(_x.num_mpf, _y.num_mpf));
    }
    else if (type == kNumTypeFraction)
    {
      z.set_frac_value(f::mod(_x.num_fraction, _y.num_fraction));
    }
    return z;
  }

  number_t abs(const number_t &x)
  {
    int type = x.type();
    number_t _x;
    if (type == kNumTypeInteger)
    {
      _x.set_int_value(std::abs(x.num_integer));
    }
    else if (type == kNumTypeFloat)
    {
      _x.set_flt_value(std::abs(x.num_float));
    }
    else if (type == kNumTypeMpz)
    {
      _x.set_mpz_value(z::abs(x.num_mpz));
    }
    else if (type == kNumTypeMpf)
    {
      _x.set_mpf_value(f::abs(x.num_mpf));
    }
    else if (type == kNumTypeFraction)
    {
      _x.set_frac_value({z::abs(x.num_fraction.first), z::abs(x.num_fraction.second)});
    }
    return _x;
  }

  number_t ceil(const number_t &x)
  {
    int type = x.type();
    number_t _x;
    if (type == kNumTypeInteger)
    {
      _x.set_int_value(std::ceil(x.num_integer));
    }
    else if (type == kNumTypeFloat)
    {
      _x.set_flt_value(std::ceil(x.num_float));
    }
    else if (type == kNumTypeMpz)
    {
      _x = x;
    }
    else if (type == kNumTypeMpf)
    {
      _x.set_mpf_value(f::ceil(x.num_mpf));
    }
    else if (type == kNumTypeFraction)
    {
      _x = x;
    }
    return _x;
  }

  number_t floor(const number_t &x)
  {
    int type = x.type();
    number_t _x;
    if (type == kNumTypeInteger)
    {
      _x.set_int_value(std::floor(x.num_integer));
    }
    else if (type == kNumTypeFloat)
    {
      _x.set_flt_value(std::floor(x.num_float));
    }
    else if (type == kNumTypeMpz)
    {
      _x = x;
    }
    else if (type == kNumTypeMpf)
    {
      _x.set_mpf_value(f::floor(x.num_mpf));
    }
    else if (type == kNumTypeFraction)
    {
      _x = x;
    }
    return _x;
  }

  number_t round(const number_t &x)
  {
    int type = x.type();
    number_t _x;
    if (type == kNumTypeInteger)
    {
      _x.set_int_value(std::round(x.num_integer));
    }
    else if (type == kNumTypeFloat)
    {
      _x.set_flt_value(std::round(x.num_float));
    }
    else if (type == kNumTypeMpz)
    {
      _x = x;
    }
    else if (type == kNumTypeMpf)
    {
      _x.set_mpf_value(f::round(x.num_mpf));
    }
    else if (type == kNumTypeFraction)
    {
      _x = x;
    }
    return _x;
  }

  number_t exp(const number_t &x, size_t precision)
  {
    int type = x.type();
    number_t _x;
    if (type == kNumTypeInteger)
    {
      _x.set_int_value(std::exp(x.num_integer));
    }
    else if (type == kNumTypeFloat)
    {
      _x.set_flt_value(std::exp(x.num_float));
    }
    else if (type == kNumTypeMpz)
    {
      _x.set_mpf_value(f::exp(mympf::create(x.num_mpz, 0), precision));
    }
    else if (type == kNumTypeMpf)
    {
      _x.set_mpf_value(f::exp(x.num_mpf, precision));
    }
    else if (type == kNumTypeFraction)
    {
      float_t a = f::to_float(x.num_fraction);
      _x.set_mpf_value(f::exp(a, precision));
    }
    return _x;
  }

  number_t pow(const number_t &a, const number_t &x, size_t precision)
  {
    std::pair<number_t, number_t> ax = same_type(a, x);
    number_t _a = ax.first, _x = ax.second;

    number_t y;
    int type = _a.type();
    if (type == kNumTypeInteger)
    {
      y.set_int_value(std::pow(_a.num_integer, _x.num_integer));
    }
    else if (type == kNumTypeFloat)
    {
      y.set_flt_value(std::pow(_a.num_float, _x.num_float));
    }
    else if (type == kNumTypeMpz)
    {
      float_t fa = mympf::create(_a.num_mpz, 0);
      float_t fx = mympf::create(_x.num_mpz, 0);
      y.set_mpf_value(f::pow(fa, fx, precision));
    }
    else if (type == kNumTypeMpf)
    {
      y.set_mpf_value(f::pow(_a.num_mpf, _x.num_mpf, precision));
    }
    else if (type == kNumTypeFraction)
    {
      float_t fa = f::to_float(_a.num_fraction);
      float_t fx = f::to_float(_x.num_fraction);
      y.set_mpf_value(f::pow(fa, fx, precision));
    }
    return y;
  }

  number_t ln(const number_t &x, size_t precision)
  {
    number_t y;
    int type = x.type();
    if (type == kNumTypeInteger)
    {
      y.set_int_value(std::log(x.num_integer));
    }
    else if (type == kNumTypeFloat)
    {
      y.set_flt_value(std::log(x.num_float));
    }
    else if (type == kNumTypeMpz)
    {
      float_t _x = mympf::create(x.num_mpz, 0);
      y.set_mpf_value(f::ln(_x, precision));
    }
    else if (type == kNumTypeMpf)
    {
      y.set_mpf_value(f::ln(x.num_mpf, precision));
    }
    else if (type == kNumTypeFraction)
    {
      float_t fx = f::to_float(x.num_fraction);
      y.set_mpf_value(f::ln(fx, precision));
    }
    return y;
  }

  number_t log(const number_t &a, const number_t &x, size_t precision)
  {
    std::pair<number_t, number_t> ax = same_type(a, x);
    number_t _a = ax.first, _x = ax.second;

    number_t y;
    int type = _a.type();
    if (type == kNumTypeInteger)
    {
      myflt_t n = std::log(_x.num_integer);
      myflt_t d = std::log(_a.num_integer);
      y.set_flt_value(n / d);
    }
    else if (type == kNumTypeFloat)
    {
      myflt_t n = std::log(_x.num_float);
      myflt_t d = std::log(_a.num_float);
      y.set_flt_value(n / d);
    }
    else if (type == kNumTypeMpz)
    {
      float_t fa = mympf::create(_a.num_mpz, 0);
      float_t fx = mympf::create(_x.num_mpz, 0);
      y.set_mpf_value(f::log(fa, fx, precision));
    }
    else if (type == kNumTypeMpf)
    {
      y.set_mpf_value(f::log(_a.num_mpf, _x.num_mpf, precision));
    }
    else if (type == kNumTypeFraction)
    {
      float_t fa = f::to_float(_a.num_fraction);
      float_t fx = f::to_float(_x.num_fraction);
      y.set_mpf_value(f::log(fa, fx, precision));
    }
    return y;
  }

  number_t log2(const number_t &x, size_t precision)
  {
    number_t y;
    int type = x.type();
    if (type == kNumTypeInteger)
    {
      y.set_flt_value(std::log2(x.num_integer));
    }
    else if (type == kNumTypeFloat)
    {
      y.set_flt_value(std::log2(x.num_float));
    }
    else if (type == kNumTypeMpz)
    {
      float_t fx = mympf::create(x.num_mpz, 0);
      y.set_mpf_value(f::log2(fx, precision));
    }
    else if (type == kNumTypeMpf)
    {
      y.set_mpf_value(f::log2(x.num_mpf, precision));
    }
    else if (type == kNumTypeFraction)
    {
      float_t fx = f::to_float(x.num_fraction);
      y.set_mpf_value(f::log2(fx, precision));
    }
    return y;
  }

  number_t log10(const number_t &x, size_t precision)
  {
    number_t y;
    int type = x.type();
    if (type == kNumTypeInteger)
    {
      y.set_flt_value(std::log10(x.num_integer));
    }
    else if (type == kNumTypeFloat)
    {
      y.set_flt_value(std::log10(x.num_float));
    }
    else if (type == kNumTypeMpz)
    {
      float_t fx = mympf::create(x.num_mpz, 0);
      y.set_mpf_value(f::log10(fx, precision));
    }
    else if (type == kNumTypeMpf)
    {
      y.set_mpf_value(f::log10(x.num_mpf, precision));
    }
    else if (type == kNumTypeFraction)
    {
      float_t fx = f::to_float(x.num_fraction);
      y.set_mpf_value(f::log10(fx, precision));
    }
    return y;
  }

  number_t sqrt(const number_t &x, size_t precision)
  {
    number_t y;
    int type = x.type();
    if (type == kNumTypeInteger)
    {
      y.set_flt_value(std::sqrt(x.num_integer));
    }
    else if (type == kNumTypeFloat)
    {
      y.set_flt_value(std::sqrt(x.num_float));
    }
    else if (type == kNumTypeMpz)
    {
      float_t fx = mympf::create(x.num_mpz, 0);
      y.set_mpf_value(f::sqrt(fx, precision));
    }
    else if (type == kNumTypeMpf)
    {
      y.set_mpf_value(f::sqrt(x.num_mpf, precision));
    }
    else if (type == kNumTypeFraction)
    {
      float_t fx = f::to_float(x.num_fraction);
      y.set_mpf_value(f::sqrt(fx, precision));
    }
    return y;
  }

  number_t sin(const number_t &x, size_t precision)
  {
    number_t y;
    int type = x.type();
    if (type == kNumTypeInteger)
    {
      y.set_flt_value(std::sin(x.num_integer));
    }
    else if (type == kNumTypeFloat)
    {
      y.set_flt_value(std::sin(x.num_float));
    }
    else if (type == kNumTypeMpz)
    {
      float_t fx = mympf::create(x.num_mpz, 0);
      y.set_mpf_value(f::sin(fx, precision));
    }
    else if (type == kNumTypeMpf)
    {
      y.set_mpf_value(f::sin(x.num_mpf, precision));
    }
    else if (type == kNumTypeFraction)
    {
      float_t fx = f::to_float(x.num_fraction);
      y.set_mpf_value(f::sin(fx, precision));
    }
    return y;
  }

  number_t cos(const number_t &x, size_t precision)
  {
    number_t y;
    int type = x.type();
    if (type == kNumTypeInteger)
    {
      y.set_flt_value(std::cos(x.num_integer));
    }
    else if (type == kNumTypeFloat)
    {
      y.set_flt_value(std::cos(x.num_float));
    }
    else if (type == kNumTypeMpz)
    {
      float_t fx = mympf::create(x.num_mpz, 0);
      y.set_mpf_value(f::cos(fx, precision));
    }
    else if (type == kNumTypeMpf)
    {
      y.set_mpf_value(f::cos(x.num_mpf, precision));
    }
    else if (type == kNumTypeFraction)
    {
      float_t fx = f::to_float(x.num_fraction);
      y.set_mpf_value(f::cos(fx, precision));
    }
    return y;
  }

  number_t tan(const number_t &x, size_t precision)
  {
    number_t y;
    int type = x.type();
    if (type == kNumTypeInteger)
    {
      y.set_flt_value(std::tan(x.num_integer));
    }
    else if (type == kNumTypeFloat)
    {
      y.set_flt_value(std::tan(x.num_float));
    }
    else if (type == kNumTypeMpz)
    {
      float_t fx = mympf::create(x.num_mpz, 0);
      y.set_mpf_value(f::tan(fx, precision));
    }
    else if (type == kNumTypeMpf)
    {
      y.set_mpf_value(f::tan(x.num_mpf, precision));
    }
    else if (type == kNumTypeFraction)
    {
      float_t fx = f::to_float(x.num_fraction);
      y.set_mpf_value(f::tan(fx, precision));
    }
    return y;
  }

  number_t cot(const number_t &x, size_t precision)
  {
    number_t y;
    int type = x.type();
    if (type == kNumTypeInteger)
    {
      y.set_flt_value(std::sin(x.num_integer) / std::cos(x.num_integer));
    }
    else if (type == kNumTypeFloat)
    {
      y.set_flt_value(std::sin(x.num_float) / std::cos(x.num_float));
    }
    else if (type == kNumTypeMpz)
    {
      float_t fx = mympf::create(x.num_mpz, 0);
      y.set_mpf_value(f::cot(fx, precision));
    }
    else if (type == kNumTypeMpf)
    {
      y.set_mpf_value(f::cot(x.num_mpf, precision));
    }
    else if (type == kNumTypeFraction)
    {
      float_t fx = f::to_float(x.num_fraction);
      y.set_mpf_value(f::cot(fx, precision));
    }
    return y;
  }

  number_t sec(const number_t &x, size_t precision)
  {
    number_t y;
    int type = x.type();
    if (type == kNumTypeInteger)
    {
      y.set_flt_value(1 / std::cos(x.num_integer));
    }
    else if (type == kNumTypeFloat)
    {
      y.set_flt_value(1 / std::cos(x.num_float));
    }
    else if (type == kNumTypeMpz)
    {
      float_t fx = mympf::create(x.num_mpz, 0);
      y.set_mpf_value(f::sec(fx, precision));
    }
    else if (type == kNumTypeMpf)
    {
      y.set_mpf_value(f::sec(x.num_mpf, precision));
    }
    else if (type == kNumTypeFraction)
    {
      float_t fx = f::to_float(x.num_fraction);
      y.set_mpf_value(f::sec(fx, precision));
    }
    return y;
  }

  number_t csc(const number_t &x, size_t precision)
  {
    number_t y;
    int type = x.type();
    if (type == kNumTypeInteger)
    {
      y.set_flt_value(1 / std::sin(x.num_integer));
    }
    else if (type == kNumTypeFloat)
    {
      y.set_flt_value(1 / std::sin(x.num_float));
    }
    else if (type == kNumTypeMpz)
    {
      float_t fx = mympf::create(x.num_mpz, 0);
      y.set_mpf_value(f::csc(fx, precision));
    }
    else if (type == kNumTypeMpf)
    {
      y.set_mpf_value(f::csc(x.num_mpf, precision));
    }
    else if (type == kNumTypeFraction)
    {
      float_t fx = f::to_float(x.num_fraction);
      y.set_mpf_value(f::csc(fx, precision));
    }
    return y;
  }

  number_t arcsin(const number_t &x, size_t precision)
  {
    number_t y;
    int type = x.type();
    if (type == kNumTypeInteger)
    {
      y.set_flt_value(std::asin(x.num_integer));
    }
    else if (type == kNumTypeFloat)
    {
      y.set_flt_value(std::asin(x.num_float));
    }
    else if (type == kNumTypeMpz)
    {
      float_t fx = mympf::create(x.num_mpz, 0);
      y.set_mpf_value(f::arcsin(fx, precision));
    }
    else if (type == kNumTypeMpf)
    {
      y.set_mpf_value(f::arcsin(x.num_mpf, precision));
    }
    else if (type == kNumTypeFraction)
    {
      float_t fx = f::to_float(x.num_fraction);
      y.set_mpf_value(f::arcsin(fx, precision));
    }
    return y;
  }

  number_t arccos(const number_t &x, size_t precision)
  {
    number_t y;
    int type = x.type();
    if (type == kNumTypeInteger)
    {
      y.set_flt_value(std::acos(x.num_integer));
    }
    else if (type == kNumTypeFloat)
    {
      y.set_flt_value(std::acos(x.num_float));
    }
    else if (type == kNumTypeMpz)
    {
      float_t fx = mympf::create(x.num_mpz, 0);
      y.set_mpf_value(f::arccos(fx, precision));
    }
    else if (type == kNumTypeMpf)
    {
      y.set_mpf_value(f::arccos(x.num_mpf, precision));
    }
    else if (type == kNumTypeFraction)
    {
      float_t fx = f::to_float(x.num_fraction);
      y.set_mpf_value(f::arccos(fx, precision));
    }
    return y;
  }

  number_t arctan(const number_t &x, size_t precision)
  {
    number_t y;
    int type = x.type();
    if (type == kNumTypeInteger)
    {
      y.set_flt_value(std::atan(x.num_integer));
    }
    else if (type == kNumTypeFloat)
    {
      y.set_flt_value(std::atan(x.num_float));
    }
    else if (type == kNumTypeMpz)
    {
      float_t fx = mympf::create(x.num_mpz, 0);
      y.set_mpf_value(f::arctan(fx, precision));
    }
    else if (type == kNumTypeMpf)
    {
      y.set_mpf_value(f::arctan(x.num_mpf, precision));
    }
    else if (type == kNumTypeFraction)
    {
      float_t fx = f::to_float(x.num_fraction);
      y.set_mpf_value(f::arctan(fx, precision));
    }
    return y;
  }

  number_t arccot(const number_t &x, size_t precision)
  {
    number_t y;
    int type = x.type();
    if (type == kNumTypeInteger)
    {
      y.set_flt_value(std::stold(kPI_2) - std::atan(x.num_integer));
    }
    else if (type == kNumTypeFloat)
    {
      y.set_flt_value(std::stold(kPI_2) - std::atan(x.num_float));
    }
    else if (type == kNumTypeMpz)
    {
      float_t fx = mympf::create(x.num_mpz, 0);
      y.set_mpf_value(f::arccot(fx, precision));
    }
    else if (type == kNumTypeMpf)
    {
      y.set_mpf_value(f::arccot(x.num_mpf, precision));
    }
    else if (type == kNumTypeFraction)
    {
      float_t fx = f::to_float(x.num_fraction);
      y.set_mpf_value(f::arccot(fx, precision));
    }
    return y;
  }

  number_t arcsec(const number_t &x, size_t precision)
  {
    number_t y;
    int type = x.type();
    if (type == kNumTypeInteger)
    {
      y.set_flt_value(std::acos(1 / x.num_integer));
    }
    else if (type == kNumTypeFloat)
    {
      y.set_flt_value(std::acos(1 / x.num_float));
    }
    else if (type == kNumTypeMpz)
    {
      float_t fx = mympf::create(x.num_mpz, 0);
      y.set_mpf_value(f::arcsec(fx, precision));
    }
    else if (type == kNumTypeMpf)
    {
      y.set_mpf_value(f::arcsec(x.num_mpf, precision));
    }
    else if (type == kNumTypeFraction)
    {
      float_t fx = f::to_float(x.num_fraction);
      y.set_mpf_value(f::arcsec(fx, precision));
    }
    return y;
  }

  number_t arccsc(const number_t &x, size_t precision)
  {
    number_t y;
    int type = x.type();
    if (type == kNumTypeInteger)
    {
      y.set_flt_value(std::asin(1 / x.num_integer));
    }
    else if (type == kNumTypeFloat)
    {
      y.set_flt_value(std::asin(1 / x.num_float));
    }
    else if (type == kNumTypeMpz)
    {
      float_t fx = mympf::create(x.num_mpz, 0);
      y.set_mpf_value(f::arccsc(fx, precision));
    }
    else if (type == kNumTypeMpf)
    {
      y.set_mpf_value(f::arccsc(x.num_mpf, precision));
    }
    else if (type == kNumTypeFraction)
    {
      float_t fx = f::to_float(x.num_fraction);
      y.set_mpf_value(f::arccsc(fx, precision));
    }
    return y;
  }

  number_t sinh(const number_t &x, size_t precision)
  {
    number_t y;
    int type = x.type();
    if (type == kNumTypeInteger)
    {
      y.set_flt_value(std::sinh(x.num_integer));
    }
    else if (type == kNumTypeFloat)
    {
      y.set_flt_value(std::sinh(x.num_float));
    }
    else if (type == kNumTypeMpz)
    {
      float_t fx = mympf::create(x.num_mpz, 0);
      y.set_mpf_value(f::sinh(fx, precision));
    }
    else if (type == kNumTypeMpf)
    {
      y.set_mpf_value(f::sinh(x.num_mpf, precision));
    }
    else if (type == kNumTypeFraction)
    {
      float_t fx = f::to_float(x.num_fraction);
      y.set_mpf_value(f::sinh(fx, precision));
    }
    return y;
  }

  number_t cosh(const number_t &x, size_t precision)
  {
    number_t y;
    int type = x.type();
    if (type == kNumTypeInteger)
    {
      y.set_flt_value(std::cosh(x.num_integer));
    }
    else if (type == kNumTypeFloat)
    {
      y.set_flt_value(std::cosh(x.num_float));
    }
    else if (type == kNumTypeMpz)
    {
      float_t fx = mympf::create(x.num_mpz, 0);
      y.set_mpf_value(f::cosh(fx, precision));
    }
    else if (type == kNumTypeMpf)
    {
      y.set_mpf_value(f::cosh(x.num_mpf, precision));
    }
    else if (type == kNumTypeFraction)
    {
      float_t fx = f::to_float(x.num_fraction);
      y.set_mpf_value(f::cosh(fx, precision));
    }
    return y;
  }

  number_t tanh(const number_t &x, size_t precision)
  {
    number_t y;
    int type = x.type();
    if (type == kNumTypeInteger)
    {
      y.set_flt_value(std::tanh(x.num_integer));
    }
    else if (type == kNumTypeFloat)
    {
      y.set_flt_value(std::tanh(x.num_float));
    }
    else if (type == kNumTypeMpz)
    {
      float_t fx = mympf::create(x.num_mpz, 0);
      y.set_mpf_value(f::tanh(fx, precision));
    }
    else if (type == kNumTypeMpf)
    {
      y.set_mpf_value(f::tanh(x.num_mpf, precision));
    }
    else if (type == kNumTypeFraction)
    {
      float_t fx = f::to_float(x.num_fraction);
      y.set_mpf_value(f::tanh(fx, precision));
    }
    return y;
  }

  number_t coth(const number_t &x, size_t precision)
  {
    number_t y;
    int type = x.type();
    if (type == kNumTypeInteger)
    {
      y.set_flt_value(std::cosh(x.num_integer) / std::sinh(x.num_integer));
    }
    else if (type == kNumTypeFloat)
    {
      y.set_flt_value(std::cosh(x.num_float) / std::sinh(x.num_float));
    }
    else if (type == kNumTypeMpz)
    {
      float_t fx = mympf::create(x.num_mpz, 0);
      y.set_mpf_value(f::coth(fx, precision));
    }
    else if (type == kNumTypeMpf)
    {
      y.set_mpf_value(f::coth(x.num_mpf, precision));
    }
    else if (type == kNumTypeFraction)
    {
      float_t fx = f::to_float(x.num_fraction);
      y.set_mpf_value(f::coth(fx, precision));
    }
    return y;
  }

  number_t sech(const number_t &x, size_t precision)
  {
    number_t y;
    int type = x.type();
    if (type == kNumTypeInteger)
    {
      y.set_flt_value(1 / std::cosh(x.num_integer));
    }
    else if (type == kNumTypeFloat)
    {
      y.set_flt_value(1 / std::cosh(x.num_float));
    }
    else if (type == kNumTypeMpz)
    {
      float_t fx = mympf::create(x.num_mpz, 0);
      y.set_mpf_value(f::sech(fx, precision));
    }
    else if (type == kNumTypeMpf)
    {
      y.set_mpf_value(f::sech(x.num_mpf, precision));
    }
    else if (type == kNumTypeFraction)
    {
      float_t fx = f::to_float(x.num_fraction);
      y.set_mpf_value(f::sech(fx, precision));
    }
    return y;
  }

  number_t csch(const number_t &x, size_t precision)
  {
    number_t y;
    int type = x.type();
    if (type == kNumTypeInteger)
    {
      y.set_flt_value(1 / std::sinh(x.num_integer));
    }
    else if (type == kNumTypeFloat)
    {
      y.set_flt_value(1 / std::sinh(x.num_float));
    }
    else if (type == kNumTypeMpz)
    {
      float_t fx = mympf::create(x.num_mpz, 0);
      y.set_mpf_value(f::csch(fx, precision));
    }
    else if (type == kNumTypeMpf)
    {
      y.set_mpf_value(f::csch(x.num_mpf, precision));
    }
    else if (type == kNumTypeFraction)
    {
      float_t fx = f::to_float(x.num_fraction);
      y.set_mpf_value(f::csch(fx, precision));
    }
    return y;
  }

  number_t arcsinh(const number_t &x, size_t precision)
  {
    number_t y;
    int type = x.type();
    if (type == kNumTypeInteger)
    {
      y.set_flt_value(std::asinh(x.num_integer));
    }
    else if (type == kNumTypeFloat)
    {
      y.set_flt_value(std::asinh(x.num_float));
    }
    else if (type == kNumTypeMpz)
    {
      float_t fx = mympf::create(x.num_mpz, 0);
      y.set_mpf_value(f::arcsinh(fx, precision));
    }
    else if (type == kNumTypeMpf)
    {
      y.set_mpf_value(f::arcsinh(x.num_mpf, precision));
    }
    else if (type == kNumTypeFraction)
    {
      float_t fx = f::to_float(x.num_fraction);
      y.set_mpf_value(f::arcsinh(fx, precision));
    }
    return y;
  }

  number_t arccosh(const number_t &x, size_t precision)
  {
    number_t y;
    int type = x.type();
    if (type == kNumTypeInteger)
    {
      y.set_flt_value(std::acosh(x.num_integer));
    }
    else if (type == kNumTypeFloat)
    {
      y.set_flt_value(std::acosh(x.num_float));
    }
    else if (type == kNumTypeMpz)
    {
      float_t fx = mympf::create(x.num_mpz, 0);
      y.set_mpf_value(f::arccosh(fx, precision));
    }
    else if (type == kNumTypeMpf)
    {
      y.set_mpf_value(f::arccosh(x.num_mpf, precision));
    }
    else if (type == kNumTypeFraction)
    {
      float_t fx = f::to_float(x.num_fraction);
      y.set_mpf_value(f::arccosh(fx, precision));
    }
    return y;
  }

  number_t arctanh(const number_t &x, size_t precision)
  {
    number_t y;
    int type = x.type();
    if (type == kNumTypeInteger)
    {
      y.set_flt_value(std::atanh(x.num_integer));
    }
    else if (type == kNumTypeFloat)
    {
      y.set_flt_value(std::atanh(x.num_float));
    }
    else if (type == kNumTypeMpz)
    {
      float_t fx = mympf::create(x.num_mpz, 0);
      y.set_mpf_value(f::arctanh(fx, precision));
    }
    else if (type == kNumTypeMpf)
    {
      y.set_mpf_value(f::arctanh(x.num_mpf, precision));
    }
    else if (type == kNumTypeFraction)
    {
      float_t fx = f::to_float(x.num_fraction);
      y.set_mpf_value(f::arctanh(fx, precision));
    }
    return y;
  }

  number_t arccoth(const number_t &x, size_t precision)
  {
    number_t y;
    int type = x.type();
    if (type == kNumTypeInteger)
    {
      y.set_flt_value(std::atanh(1 / x.num_integer));
    }
    else if (type == kNumTypeFloat)
    {
      y.set_flt_value(std::atanh(1 / x.num_float));
    }
    else if (type == kNumTypeMpz)
    {
      float_t fx = mympf::create(x.num_mpz, 0);
      y.set_mpf_value(f::arccoth(fx, precision));
    }
    else if (type == kNumTypeMpf)
    {
      y.set_mpf_value(f::arccoth(x.num_mpf, precision));
    }
    else if (type == kNumTypeFraction)
    {
      float_t fx = f::to_float(x.num_fraction);
      y.set_mpf_value(f::arccoth(fx, precision));
    }
    return y;
  }

  number_t arcsech(const number_t &x, size_t precision)
  {
    number_t y;
    int type = x.type();
    if (type == kNumTypeInteger)
    {
      y.set_flt_value(std::acosh(1 / x.num_integer));
    }
    else if (type == kNumTypeFloat)
    {
      y.set_flt_value(std::acosh(1 / x.num_float));
    }
    else if (type == kNumTypeMpz)
    {
      float_t fx = mympf::create(x.num_mpz, 0);
      y.set_mpf_value(f::arcsech(fx, precision));
    }
    else if (type == kNumTypeMpf)
    {
      y.set_mpf_value(f::arcsech(x.num_mpf, precision));
    }
    else if (type == kNumTypeFraction)
    {
      float_t fx = f::to_float(x.num_fraction);
      y.set_mpf_value(f::arcsech(fx, precision));
    }
    return y;
  }

  number_t arccsch(const number_t &x, size_t precision)
  {
    number_t y;
    int type = x.type();
    if (type == kNumTypeInteger)
    {
      y.set_flt_value(std::asinh(1 / x.num_integer));
    }
    else if (type == kNumTypeFloat)
    {
      y.set_flt_value(std::asinh(1 / x.num_float));
    }
    else if (type == kNumTypeMpz)
    {
      float_t fx = mympf::create(x.num_mpz, 0);
      y.set_mpf_value(f::arccsch(fx, precision));
    }
    else if (type == kNumTypeMpf)
    {
      y.set_mpf_value(f::arccsch(x.num_mpf, precision));
    }
    else if (type == kNumTypeFraction)
    {
      float_t fx = f::to_float(x.num_fraction);
      y.set_mpf_value(f::arccsch(fx, precision));
    }
    return y;
  }

  number_t erf(const number_t &x, size_t precision)
  {
    number_t y;
    int type = x.type();
    if (type == kNumTypeInteger)
    {
      y.set_flt_value(std::erf(x.num_integer));
    }
    else if (type == kNumTypeFloat)
    {
      y.set_flt_value(std::erf(x.num_float));
    }
    else if (type == kNumTypeMpz)
    {
      float_t fx = mympf::create(x.num_mpz, 0);
      y.set_mpf_value(f::erf(fx, precision));
    }
    else if (type == kNumTypeMpf)
    {
      y.set_mpf_value(f::erf(x.num_mpf, precision));
    }
    else if (type == kNumTypeFraction)
    {
      float_t fx = f::to_float(x.num_fraction);
      y.set_mpf_value(f::erf(fx, precision));
    }
    return y;
  }

  number_t erfc(const number_t &x, size_t precision)
  {
    number_t y;
    int type = x.type();
    if (type == kNumTypeInteger)
    {
      y.set_flt_value(std::erfc(x.num_integer));
    }
    else if (type == kNumTypeFloat)
    {
      y.set_flt_value(std::erfc(x.num_float));
    }
    else if (type == kNumTypeMpz)
    {
      float_t fx = mympf::create(x.num_mpz, 0);
      y.set_mpf_value(f::erfc(fx, precision));
    }
    else if (type == kNumTypeMpf)
    {
      y.set_mpf_value(f::erfc(x.num_mpf, precision));
    }
    else if (type == kNumTypeFraction)
    {
      float_t fx = f::to_float(x.num_fraction);
      y.set_mpf_value(f::erfc(fx, precision));
    }
    return y;
  }

  int sgn(const number_t &x)
  {
    int type = x.type(), s = 0;
    if (type == kNumTypeInteger)
    {
      s = x.num_integer < 0 ? 1 : 0;
    }
    else if (type == kNumTypeFloat)
    {
      s = x.num_float < 0.0 ? 1 : 0;
    }
    else if (type == kNumTypeMpz)
    {
      s = z::sgn(x.num_mpz);
    }
    else if (type == kNumTypeMpf)
    {
      s = f::sgn(x.num_mpf);
    }
    else if (type == kNumTypeFraction)
    {
      s = f::sgn(x.num_fraction);
    }
    return s;
  }

  number_t fraction(const number_t &x)
  {
    number_t y;
    int type = x.type();
    if (type == kNumTypeInteger)
    {
      y.set_frac_value(f::fraction(static_cast<myflt_t>(x.num_integer)));
    }
    else if (type == kNumTypeFloat)
    {
      y.set_frac_value(f::fraction(x.num_float));
    }
    else if (type == kNumTypeMpz)
    {
      y.set_frac_value(f::fraction(x.num_mpz));
    }
    else if (type == kNumTypeMpf)
    {
      y.set_frac_value(f::fraction(x.num_mpf));
    }
    else if (type == kNumTypeFraction)
    {
      return x.num_fraction;
    }
    return y;
  }

  number_t reduction(const number_t &x)
  {
    if (x.type() == kNumTypeFraction)
    {
      number_t y;
      y.set_frac_value(f::reduction(x.num_fraction));
      return y;
    }
    return x;
  }

  number_t gamma(const number_t &x, size_t precision)
  {
    number_t y;
    int type = x.type();
    if (type == kNumTypeInteger)
    {
      y.set_flt_value(std::lgamma(x.num_integer));
    }
    else if (type == kNumTypeFloat)
    {
      y.set_flt_value(std::lgamma(x.num_float));
    }
    else if (type == kNumTypeMpz)
    {
      float_t fx = mympf::create(x.num_mpz, 0);
      y.set_mpf_value(f::gamma(fx, precision));
    }
    else if (type == kNumTypeMpf)
    {
      y.set_mpf_value(f::gamma(x.num_mpf, precision));
    }
    else if (type == kNumTypeFraction)
    {
      float_t fx = f::to_float(x.num_fraction);
      y.set_mpf_value(f::gamma(fx, precision));
    }
    return y;
  }

  // void init()
  // {
  //   z::init();
  //   f::init();
  // }
} // namespace mynum