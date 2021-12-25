/* Returns a value of type int that matches one of the classification macro constants, 
 * depending on the value of x:
 *
 * value        description
 * FP_INFINITE  Positive or negative infinity (overflow)
 * FP_NAN       Not-A-Number
 * FP_ZERO      Value of zero
 * FP_SUBNORMAL Sub-normal value (underflow)
 * FP_NORMAL    Normal value (none of the above)
 */
template <class T>
int fpclassify(const T& x) {
  __is_invalid_type<T>();
  if (is_infinite(x)) return FP_INFINITE;
  else if (is_nan(x)) return FP_NAN;
  else if (is_zero(x)) return FP_ZERO;
  else if (is_subnormal(x)) return FP_SUBNORMAL;
  return FP_NORMAL;
}