template <class T>
T logb(const T& x) {
  return log(Float(FLT_RADIX), Float(x));
}