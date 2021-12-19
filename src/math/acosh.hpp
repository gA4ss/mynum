template <class T>
Float acosh(const T& v) {
  __is_invalid_type<T>();
  return arccosh(Float(v));
}