template <class T>
T fabs(const T& v) {
  __is_invalid_type<T>();
  return abs(v);
}