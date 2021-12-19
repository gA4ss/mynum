template <class T>
Float floor(const T& v) {
  __is_invalid_type<T>();
  return floor(Float(v));
}