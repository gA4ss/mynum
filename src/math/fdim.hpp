/* Returns the positive difference between x and y.
 * The function returns x-y if x>y, and zero otherwise.
 */
template <class T>
Float fdim(const T& x, const T& y) {
  __is_invalid_type<T>();
  return (x > y) ? (Float(x) - Float(y)) : Float(0.0);
}
