template <class T>
T fmax(const T& x, const T& y) {
  __is_invalid_type<T>();
  return (x > y) ? x : y;
}