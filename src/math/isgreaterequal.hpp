/* Returns whether x is greater than or equal to y.
 *
 * If one or both arguments are NaN, the function returns false, 
 * but no FE_INVALID exception is raised 
 * (note that the expression x>=y may raise such an exception in this case).
 */
template <class T>
int isgreaterequal(const T& x, const T& y) {
  return static_cast<int>(ge(x, y));
}