// #define FP_T_MAX   32             
float eval_cf_lentz(float x) {
  float ak, b0, bk, Ck, Ckm1, Dk, Dkm1, Ek, Ekm1, eps, Hk;
  int k;
  b0 = /* TO BE SUPPLIED */;
  eps = FP(1.0e10) / FP_T_MAX; /* may need to fudge the numerator */
  Ckm1 = b0;
  if (b0 == ZERO)
    Ckm1 = eps;
  Ekm1 = Ckm1;
  Dkm1 = ZERO;
  for (k = 1; k <= MAXITER; ++k) {
    ak = /* TO BE SUPPLIED */;
    bk = /* TO BE SUPPLIED */;
    Dk = bk + ak * Dkm1;

    if (Dk == ZERO)
      Dk = eps;
    Ek = bk + ak / Ekm1;

    if (Ek == ZERO)
      Ek = eps;

    Dk = ONE / Dk;
    Hk = Ek * Dk;
    Ck = Ckm1 * Hk;

    if ((ONE + (Hk - ONE)) == ONE) /* converged */
      break;

    Ckm1 = Ck;
    Dkm1 = Dk;
    Ekm1 = Ek;
  }
  return (Ck);
}