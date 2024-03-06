#include <mynum/complex.h>
#include <cmath>
namespace mynum
{
  __complex_t::__complex_t()
  {
  }

  __complex_t::__complex_t(const __complex_t &c)
  {
    __real_park = c.re();
    __imaginary_part = c.im();
  }

  __complex_t::__complex_t(const __real_t &re, const __real_t &im)
  {
    __real_park = re;
    __imaginary_part = im;
  }

  __complex_t::__complex_t(std::string re, std::string im)
  {
    __real_park = real_t(re);
    __imaginary_part = real_t(im);
  }

  real_t __complex_t::re() const
  {
    return __real_park;
  }

  real_t __complex_t::im() const
  {
    return __imaginary_part;
  }

  std::string __complex_t::value() const
  {
    return "(" + __real_park.value() + "," + __imaginary_part.value() + ")";
  }

  complex_t integer_to_float(const complex_t &x)
  {
    return complex_t(integer_to_float(x.));
  }

  complex_t float_to_integer(const complex_t &x)
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

} // namespace mynum