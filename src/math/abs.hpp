template <class T>
T abs(const T& v) {
  __is_invalid_type<T>();
  return abs(v);
}