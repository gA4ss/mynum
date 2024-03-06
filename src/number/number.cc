#include <mynum/number.h>

namespace mynum
{
  __number_t::__number_t() : __type(kNumTypeReal)
  {
  }

  __number_t::__number_t(const __number_t &n)
  {
    __type = n.type();
    num_real = n.num_real;
    num_complex = n.num_complex;
  }

  __number_t::__number_t(std::string n)
  {
    __type = kNumTypeReal;
    num_real = real_t(n);
  }

  __number_t::__number_t(myflt_t n)
  {
    __type = kNumTypeReal;
    num_real = real_t(n);
  }

  __number_t::__number_t(float_t n)
  {
    __type = kNumTypeReal;
    num_real = real_t(n);
  }

  __number_t::__number_t(integer_t n)
  {
    __type = kNumTypeReal;
    num_real = real_t(n);
  }

  __number_t::__number_t(fraction_t n)
  {
    __type = kNumTypeReal;
    num_real = real_t(n);
  }

  static bool __test(int ty, int v)
  {
    return (ty & v) == v;
  }

  std::string __number_t::value() const
  {
    return __test(__type, kNumTypeReal) ? num_real.value() : __test(__type, kNumTypeComplex) ? num_complex.value()
                                                                                             : "";
  }

  int __number_t::type() const
  {
    return __type;
  }

  bool __number_t::is_complex() const
  {
    return __test(__type, kNumTypeComplex);
  }

  bool test(const number_t &x, int type)
  {
    return __test(x.type(), type);
  }

  number_t covert_to(const number_t &x, int type)
  {
    number_t y;

    if (test(x.type(), type))
      return x;

    if (test(x, kNumTypeReal))
    {
      y = number_t(x.num_real, real_t(0));
    }
    else
    {
      y = number_t(x.num_real);
    }
    return y;
  }

  number_t integer_to_float(const number_t &x)
  {
    number_t y = x;
    if (test(x, kNumTypeReal))
    {
      y.num_real = integer_to_float(y.num_real);
    }
    else if (test(x, kNumTypeComplex))
    {
      y.num_complex = integer_to_float(y.num_real);
    }
    return y;
  }

  number_t float_to_integer(const number_t &x)
  {
    number_t y;
    if (test(x, kNumTypeReal))
    {
      y.num_real = float_to_integer(y.num_real);
    }
    else if (test(x, kNumTypeComplex))
    {
      y.num_complex = float_to_integer(y.num_real);
    }
    return y;
  }

  __number_t &__number_t::operator=(const __number_t &n)
  {
    set_num_value(n);
    return *this;
  }

  __number_t &__number_t::operator=(std::string n)
  {
    set_str_value(n);
    return *this;
  }

  __number_t &__number_t::operator=(myflt_t n)
  {
    set_flt_value(n);
    return *this;
  }

  __number_t &__number_t::operator=(const integer_t &n)
  {
    set_mpz_value(n);
    return *this;
  }

  __number_t &__number_t::operator=(const float_t &n)
  {
    set_mpf_value(n);
    return *this;
  }

  void __number_t::operator+=(const __number_t &n)
  {
    *this = add(*this, n);
  }

  void __number_t::operator-=(const __number_t &n)
  {
    *this = sub(*this, n);
  }

  void __number_t::operator*=(const __number_t &n)
  {
    *this = mul(*this, n);
  }

  void __number_t::operator/=(const __number_t &n)
  {
    *this = div(*this, n);
  }

  void __number_t::operator%=(const __number_t &n)
  {
    *this = mod(*this, n);
  }
} // namespace mynum