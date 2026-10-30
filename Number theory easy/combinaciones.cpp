ll c(int n, int k){
  if(k < 0 or k > n) return 0;
  return fact[n]*invfact[k]%MOD*invfact[n-k]%MOD;
} //para acordarte del caso
