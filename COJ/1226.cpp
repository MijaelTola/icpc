#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll factor[1000];
int fac_top = -1;
//GCD of bint
ll gcd(ll small,ll big) {
  while(small) {
    swap(small,big);
    small%=big;
  }
  return abs(big);
}
//ret = (a*b)%n (n<2^62)
ll muti_mod(ll a,ll b,ll n) {
  ll exp = a%n, res = 0;
  while(b) {
    if(b&1) {
      res += exp;
      if(res>n) res -= n;
    }
    exp <<= 1;
    if (exp>n) exp -= n;
    b>>=1;
  }
  return res;
}
// ret = (a^b)%n
ll mod_exp(ll a,ll p,ll m) {
  ll exp=a%m, res=1;
  while(p>1) {
    if(p&1)
      res=muti_mod(res,exp,m);
    exp = muti_mod(exp,exp,m);
    p>>=1;
  }
  return muti_mod(res,exp,m);
}
//miller-rabin
bool miller_rabin(ll n, int times) {
  if(n==2)return 1;
  if(n<2||!(n&1))return 0;
  ll a, u=n-1, x, y;
  int t=0;
  while(u%2==0) {
    t++;
    u/=2;
  }
  for(int i=0; i<times; i++) {
    a = rand() % (n-1) + 1;
    x = mod_exp(a, u, n);
    for(int j=0; j<t; j++) {
      y = muti_mod(x, x, n);
      if ( y == 1 && x != 1 && x != n-1 )
        return false; //must not
      x = y;
    }
    if( y!=1) return false;
  }
  return true;
}
ll pollard_rho(ll n,int c) {
  ll x,y,d,i = 1,k = 2;
  x = rand()%(n-1)+1;
  y = x;
  while(true) {
    i++;
    x = (muti_mod(x,x,n) + c) % n;
    d = gcd(y-x, n);
    if (1 < d && d < n) return d;
    if( y == x) return n;
    if(i == k) {
      y = x;
      k <<= 1;
    }
  }
}
void findFactor(ll n,int k) {
  if(n==1)return;
  if(miller_rabin(n, 8)) {
    factor[++fac_top] = n;
    return;
  }
  ll p = n;
  while(p >= n)
    p = pollard_rho(p,k--);
  findFactor(p,k);
  findFactor(n/p,k);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    ll x; 
    while(cin >> x and x != -1){
        fac_top = -1;
        findFactor(x,4);
        sort(factor,factor+fac_top+1);
        for (int i = 0; i < fac_top+1; ++i) cout<< "    " << factor[i] << "\n";
        cout << "\n";
    }
}
