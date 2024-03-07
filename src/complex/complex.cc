#include <mynum/complex.h>
#include <cmath>
namespace mynum
{
  __complex_t::__complex_t()
  {
  }

  __complex_t::__complex_t(const __complex_t &c)
  {
    real_park = c.real_park;
    imaginary_part = c.imaginary_part;
  }

  __complex_t::__complex_t(const __real_t &re, const __real_t &im)
  {
    real_park = re;
    imaginary_part = im;
  }

  __complex_t::__complex_t(std::string re, std::string im)
  {
    real_park = real_t(re);
    imaginary_part = real_t(im);
  }

  std::string __complex_t::value() const
  {
    return "(" + real_park.value() + "," + imaginary_part.value() + ")";
  }

  complex_t integer_to_float(const complex_t &x)
  {
    return complex_t(integer_to_float(x.real_park), integer_to_float(x.imaginary_part));
  }

  complex_t float_to_integer(const complex_t &x)
  {
    return complex_t(float_to_integer(x.real_park), float_to_integer(x.imaginary_part));
  }

} // namespace mynum