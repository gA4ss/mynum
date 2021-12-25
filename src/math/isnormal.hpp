// Returns whether x is a normal value: i.e., whether it is neither infinity, NaN, zero or subnormal.
template <class T>
int isnormal(const T& x) {
  return static_cast<int>(fpclassify(x) == FP_NORMAL);
}