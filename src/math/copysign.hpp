template <class T>
T copysign(const T& v) {
  T ret;
  __is_invalid_type<T>();
  ret.set_sign(v.sign());
  return ret;
}