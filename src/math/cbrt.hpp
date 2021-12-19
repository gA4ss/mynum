// Returns the cubic root of x.
template <class T>
Float cbrt(const T& v) {
  __is_invalid_type<T>();
  return pow(Float(v), Float("0.333333333333333333333333333333333333333"));
}