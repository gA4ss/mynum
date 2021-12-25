/* Returns whether x or y are unordered values:
 *
 * If one or both arguments are NaN, the arguments are unordered 
 * and the function returns true. In no case the function raises 
 * a FE_INVALID exception.
 */
template <class T>
int isunordered(const T& x, const T& y) {
  return static_cast<int>(is_nan(x) || is_nan(y));
}