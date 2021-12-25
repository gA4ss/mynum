/* Returns whether x is a finite value.
 *
 * A finite value is any floating-point value that is neither infinite nor NaN (Not-A-Number).
 */
template <class T>
int isfinite(const T& x) {
  return static_cast<int>(!is_infinite(x));
}
