#include <mynum/mynum.h>

namespace mynum
{
  number_t add(const number_t &x, const number_t &y)
  {
    number_t z;

    if (test(x.type(), kNumTypeReal) && test(y.type(), kNumTypeReal))
    {
      z = add(x.real, y.real);
    }
    else if (test(x.type(), kNumTypeComplex) && test(y.type(), kNumTypeReal))
    {
      z = number_t(add(x.complex.real_park, y.real), x.complex.imaginary_part);
    }
    else if (test(x.type(), kNumTypeReal) && test(y.type(), kNumTypeComplex))
    {
      z = number_t(add(x.real, y.complex.real_park), y.complex.imaginary_part);
    }
    else if (test(x.type(), kNumTypeComplex) && test(y.type(), kNumTypeComplex))
    {
      z = add(x.complex, y.complex);
    }

    return z;
  }
} // namespace mynum