// Returns the base-2 exponential function of x, which is 2 raised to the power x: 2x.
template <class T>
Float exp2(const T& v) {
  __is_invalid_type<T>();
  return pow(Float(2.0), Float(v));
}