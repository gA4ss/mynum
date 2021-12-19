template <class T>
Float atanh(const T& v) {
  __is_invalid_type<T>();
  return arctanh(Float(v));
}