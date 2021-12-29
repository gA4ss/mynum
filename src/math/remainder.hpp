/* Compute remainder (IEC 60559)
 * Returns the floating-point remainder of numer/denom (rounded to nearest):
 *
 * remainder = numer - rquot * denom
 *
 * Where rquot is the result of: numer/denom, rounded toward the nearest integral value (with halfway cases rounded toward the even number).
 *
 * A similar function, fmod, returns the same but with the quotient truncated (rounded towards zero) instead.
 * The function remquo has a behavior identical to this function, but it additionally provides access to the intermediate quotient value used.
 */
template <class T>
T remainder(const T& numer, const T& denom) {
  return numer;
}