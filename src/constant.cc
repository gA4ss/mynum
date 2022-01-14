#include <mynum/constant.h>

namespace mynum {

Float __pi = "3.141592653589793238462643383279502884197169399375105820974944";
Float __half_pi = "1.570796326794896619231321691639751442098584699687552910487472";
Float __e = "2.7182818284590452353602874713527";
Float __golden_ratio = "0.6180339887";

Float approximate_pi(const char* epsilon) {
  // 莱布尼兹公式
  // 这TMD的是最慢的近似方法了吧，极慢。
  Float res = "0", n = "3", o = "1", t = "2", item, p;
  my::uinteger_t i = 2;
  do {
    p = res;
    item = div(o, n);
    if (i % 2 == 0)
      item.set_sign(kNegative);
    std::cout << "n = " << n.str() << std::endl;
    std::cout << "item = " << item.str() << std::endl;
    res += item;
    std::cout << "res = " << res.str() << std::endl << std::endl;
    n += t;
    ++i;
  } while (abs(res - p) > epsilon);
  ++res;
  res *= "4";
  return res;
}

Float approximate_e(const char* epsilon) {
  return exp("1", epsilon);
}

Float approximate_golden_ratio(const char* epsilon) {
  return div(sub(sqrt("5", epsilon), "1"), "2");
}

} // namespace mynum