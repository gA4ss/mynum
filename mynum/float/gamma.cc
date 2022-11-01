/* 伽玛函数（Gamma函数），也叫欧拉第二积分，是阶乘函数在实数与复数上扩展的一类函数。
 * 该函数在分析学、概率论、偏微分方程和组合数学中有重要的应用。
 * 与之有密切联系的函数是贝塔函数，也叫第一类欧拉积分，
 * 可以用来快速计算同伽马函数形式相类似的积分。
 */
#include <cmath>
#include <mynum/float.h>
#include <mynum/constant.h>

namespace mynum {

Float gamma(const Float& x, const char* epsilon) {
  operation_is_not_implement_exception("%s", "gamma function");
  return x;
}

} // namespace mynum