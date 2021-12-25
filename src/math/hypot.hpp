/* Returns the hypotenuse of a right-angled triangle whose legs are x and y.
 * 
 * The function returns what would be the square root of the sum of the squares 
 * of x and y (as per the Pythagorean theorem), but without incurring in undue 
 * overflow or underflow of intermediate values.
 */
template <class T>
T hypot(const T& x, const T& y) {
  __is_invalid_type<T>();
  return add((x * x), (y * y));
}