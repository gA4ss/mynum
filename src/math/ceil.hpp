template <class T>
Float ceil(const T& v) {
  __is_invalid_type<T>();
  return ceil(Float(v));
}