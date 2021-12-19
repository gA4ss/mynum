template <class T>
Float cos(const T& v) {
  __is_invalid_type<T>();
  return cos(Float(v));
}