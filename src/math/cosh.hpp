template <class T>
Float cosh(const T& v) {
  __is_invalid_type<T>();
  return cosh(Float(v));
}