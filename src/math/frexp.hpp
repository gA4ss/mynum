/* Get significand and exponent
 * Breaks the floating point number x into its binary significand (a floating point with an absolute value between 0.5(included) and 1.0(excluded)) and an integral exponent for 2, such that:
 * 
 * x = significand * 2 exponent
 * The exponent is stored in the location pointed by exp, and the significand is the value returned by the function.
 *
 * If x is zero, both parts (significand and exponent) are zero.
 * If x is negative, the significand returned by this function is negative.
 */
template <class T>
T frexp (const T& x, T* exp) {
  __is_invalid_type<T>();
  return x;
}