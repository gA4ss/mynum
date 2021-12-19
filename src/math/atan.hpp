template <class T>
Float atan(const T& v) {
  __is_invalid_type<T>();
  return arctan(Float(v));
}