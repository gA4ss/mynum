template <class T>
T fmin(const T& x, const T& y) {
  __is_invalid_type<T>();
  return (x < y) ? x : y;
}