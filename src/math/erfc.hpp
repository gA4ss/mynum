/* Returns the complementary error function value for x.
 * The complementary error function is equivalent to:
 * erfc(x) = 1-erf(x)
 */
template <class T>
Float erfc(const T& v) {
  __is_invalid_type<T>();
  return 1 - erf(Float(v));
}