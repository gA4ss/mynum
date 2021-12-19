// Returns the base-e exponential function of x, which is e raised to the power x: ex.
template <class T>
Float exp(const T& v) {
  __is_invalid_type<T>();
  return exp(Float(v));
}