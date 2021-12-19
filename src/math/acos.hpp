template <class T>
Float acos(const T& v) {
  __is_invalid_type<T>();
  return arccos(Float(v));
}