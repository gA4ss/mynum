template <class T>
Float asin(const T& v) {
  __is_invalid_type<T>();
  return arcsin(Float(v));
}