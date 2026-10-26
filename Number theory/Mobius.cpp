/*
    1 si n = 1
    (-1)^k si n es producto de k diferentes primos
    0 si n es divisible por un cuadrado
*/
 
vector<int>u(maxn,1);
 
void mobius(){
  u[0] = 0;
 
  for(int p = 2; p < maxn; p++){
    bool primo = true;
    for(int j=2;1ll*j*j <= p; j++){
      if(p%j == 0){
        primo = false;
        break;
      }
    }
    if(!primo) continue;
 
    for(int j=p;j<maxn;j+= p) u[j]*=-1;
    for(ll j =1ll*p*p; j < maxn; j+= 1ll*p*p) u[j] =0;
  }
}
