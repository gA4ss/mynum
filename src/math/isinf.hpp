// Returns whether x is an infinity value (either positive infinity or negative infinity).
template <class T>
int isinf(const T& x) {
  return static_cast<int>(is_infinite(x));
}