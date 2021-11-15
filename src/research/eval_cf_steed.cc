#define MAXITER 10          /* limits the number of iterations */

float eval_cf_steed(float x) {
  float a1, ak, b0, b1, bk, Ck, Ckm1, Ckm2, Dk, Dkm1, Ek, Ekm1;
  int k;
  b0 = /* TO BE SUPPLIED */;
  b1 = /* TO BE SUPPLIED */;
  a1 = /* TO BE SUPPLIED */;
  Ckm2 = /* TO BE SUPPLIED */;
  Dkm1 = ONE / b1;
  Ekm1 = a1 * Dkm1;
  Ckm1 = Ckm2 + Ekm1;
  for (k = 2; k <= MAXITER; ++k) {
    ak = /* TO BE SUPPLIED */;
    bk = /* TO BE SUPPLIED */;
    Dk = ONE / (Dkm1 * ak + bk);
    Ek = (bk * Dk - ONE) * Ekm1;
    Ck = Ckm1 + Ek;
    if (Ck == Ckm1) /* converged */
      break;
    Ckm1 = Ck;
    Dkm1 = Dk;
    Ekm1 = Ek;
  }
  return (Ck);
}