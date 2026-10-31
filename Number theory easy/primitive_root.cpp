int totient(int n) {
  int ans = n;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      while (n % i == 0) n /= i;
      ans = ans / i * (i - 1);
    }
  }
  if (n > 1) ans = ans / n * (n - 1);
  return ans;
}
int power(int a, int b, int m) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = 1LL * res * a % m;
    a = 1LL * a * a % m;
    b >>= 1;
  }
  return res;
}

int primitive_root(int p){
  vector<int>fact;
  int phi = totient(p), n = phi;
  for(int i=2;i*i<=n;i++)
    if(n%i == 0){
      fact.push_back(i);
      while(n%i == 0) n /= i;
    }
  if(n > 1) fact.push_back(n);
  
  for (int res = 2; res <= p; ++res) { // this loop will run at most (logp ^ 6) times i.e. until a root is found
    bool ok = true;
    // check if this is a primitive root modulo p
    for (size_t i = 0; i < fact.size() && ok; ++i)
      ok &= power(res, phi / fact[i], p) != 1;
    if (ok)  return res;
  }
  return -1;
}
