#include <mynum/number.h>

namespace mynum
{
  static bool __test(int ty, int v)
  {
    return (ty & v) == v;
  }
  __number_t::__number_t() : __type(kNumTypeReal)
  {
  }

  __number_t::__number_t(const __number_t &n)
  {
    __type = n.type();
    if (__test(__type, kNumTypeReal))
      real = n.real;
    else if (__test(__type, kNumTypeComplex))
      complex = n.complex;
  }

  __number_t::__number_t(const __real_t &r)
  {
    __type = kNumTypeReal;
    real = r;
  }

  __number_t::__number_t(const __complex_t &c)
  {
    __type = kNumTypeComplex;
    complex = c;
  }

  std::string __number_t::value() const
  {
    return __test(__type, kNumTypeReal) ? real.value() : __test(__type, kNumTypeComplex) ? complex.value()
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
      y = number_t(x.real, real_t(0));
    }
    else
    {
      y = number_t(x.real);
    }
    return y;
  }

  number_t integer_to_float(const number_t &x)
  {
    number_t y = x;
    if (test(x, kNumTypeReal))
    {
      y.real = integer_to_float(y.real);
    }
    else if (test(x, kNumTypeComplex))
    {
      y.complex = integer_to_float(y.complex);
    }
    return y;
  }

  number_t float_to_integer(const number_t &x)
  {
    number_t y;
    if (test(x, kNumTypeReal))
    {
      y.real = float_to_integer(y.real);
    }
    else if (test(x, kNumTypeComplex))
    {
      y.complex = float_to_integer(y.complex);
    }
    return y;
  }

  __number_t &__number_t::operator=(const __real_t &n)
  {
    __type = kNumTypeReal;
    real = n;
  }

  __number_t &__number_t::operator=(const __complex_t &n)
  {
    __type = kNumTypeComplex;
    complex = n;
  }

  __number_t &__number_t::operator=(const __number_t &n)
  {
    __type = n.type();
    if (__test(__type, kNumTypeReal))
      real = n.real;
    else if (__test(__type, kNumTypeComplex))
      complex = n.complex;

    return *this;
  }

  __number_t &__number_t::operator=(std::string n)
  {
    __type = kNumTypeReal;
    real = real_t(n);

    return *this;
  }

  __number_t &__number_t::operator=(myflt_t n)
  {
    __type = kNumTypeReal;
    real = real_t(n);

    return *this;
  }

  __number_t &__number_t::operator=(const integer_t &n)
  {
    __type = kNumTypeReal;
    real = real_t(n);

    return *this;
  }

  __number_t &__number_t::operator=(const float_t &n)
  {
    __type = kNumTypeReal;
    real = real_t(n);

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