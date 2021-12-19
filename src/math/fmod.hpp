/* Returns the floating-point remainder of numer/denom (rounded towards zero):
 * fmod = numer - tquot * denom
 * Where tquot is the truncated (i.e., rounded towards zero) result of: numer/denom.
 * A similar function, remainder, returns the same but with the quotient rounded to 
 * the nearest integer (instead of truncated).
 */
template <class T>
Float fmod(const T& numer, const T& denom) {
  __is_invalid_type<T>();
  return (x > y) ? (Float(x) - Float(y)) : Float(0.0);
}