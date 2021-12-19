// Returns the error function value for x.
template <class T>
Float erf(const T& v) {
  __is_invalid_type<T>();
  return erf(Float(v));
}