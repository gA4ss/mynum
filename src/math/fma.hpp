// Returns x*y+z.
template <class T>
Float fma(const T& x, const T& y, const T& z) {
  __is_invalid_type<T>();
  return ((Float(x) * Float(y)) + Float(z));
}