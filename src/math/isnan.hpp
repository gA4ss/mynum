/* Returns whether x is a NaN (Not-A-Number) value.
 *
 * The NaN values are used to identify undefined or non-representable values 
 * for floating-point elements, such as the square root of negative numbers or the result of 0/0.
 */
template <class T>
int isnan(const T& x) {
  return static_cast<int>(is_nan(x));
}