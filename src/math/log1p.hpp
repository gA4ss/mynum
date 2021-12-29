template <class T>
T log1p(const T& x) {
  return ln(Float(x)+1);
}