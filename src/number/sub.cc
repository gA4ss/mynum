#include <mynum/mynum.h>

namespace mynum
{
  number_t sub(const number_t &x, const number_t &y)
  {
    number_t z;

    if (test(x.type(), kNumTypeReal) && test(y.type(), kNumTypeReal))
    {
      z = sub(x.real, y.real);
    }
    else if (test(x.type(), kNumTypeComplex) && test(y.type(), kNumTypeReal))
    {
      z = number_t(sub(x.complex.real_park, y.real), x.complex.imaginary_part);
    }
    else if (test(x.type(), kNumTypeReal) && test(y.type(), kNumTypeComplex))
    {
      z = number_t(sub(x.real, y.complex.real_park), sub(real_t(0), y.complex.imaginary_part));
    }
    else if (test(x.type(), kNumTypeComplex) && test(y.type(), kNumTypeComplex))
    {
      z = sub(x.complex, y.complex);
    }

    return z;
  }
} // namespace mynum