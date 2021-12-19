/* Returns e raised to the power x minus one: ex-1.
 * For small magnitude values of x, expm1 may be more accurate than exp(x)-1.
 */
template <class T>
Float expm1(const T& v) {
  __is_invalid_type<T>();
  return exp(Float(v)) - 1;
}