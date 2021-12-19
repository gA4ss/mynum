template <class T>
Float asinh(const T& v) {
  __is_invalid_type<T>();
  return arcsinh(Float(v));
}