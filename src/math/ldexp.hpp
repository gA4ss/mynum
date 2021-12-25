// Returns the result of multiplying x (the significand) by 2 raised to the power of exp (the exponent).
template <class T>
T ldexp(const T& x, const T& exp) {
  return mul(x, pow(2, exp));
}