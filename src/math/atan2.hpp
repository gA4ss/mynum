template <class T>
Float atan2(const T& y, const T& x) {
  __is_invalid_type<T>();
  return arctan(Float(y) / Float(x));
}