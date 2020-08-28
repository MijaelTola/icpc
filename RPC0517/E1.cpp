#include <bits/stdc++.h>

using namespace std;

int n,k;
int v[20010];
bool prime[1000010];
vector<int> primes;
void criba(){
    memset(prime,false,sizeof prime);
    for (int i = 2; i*i < 1000010; ++i){
        int c = i+i;
        while(c < 1000010){
            prime[c] = true;
            c += i;
        }
    }
    for (int i = 2; i < 1000010; ++i){
        if(!prime[i]) primes.push_back(i);
    }
}

int factors(int x){
    int idx = 0;
    int pf = primes[0];
    int ans = 0;
    while(pf*pf <= x){
        while(x%pf == 0){x/=pf;ans = max(ans,pf);}
        pf = primes[++idx];
    }
    if(x != 1) ans = max(ans,x);
    return ans;
}

bool ver(int u){
    int gcd = v[0];
    int p = 0;
    for (int i = 0; i < n; ++i){
        gcd = __gcd(gcd,v[i]);
        if(factors(gcd) < u){
            p++;
            gcd = v[i];
        }
    }
    if(v[n-1] != gcd and factors(gcd) < u) p++;
    return !(p >= k);

}
int main(){
    criba();
    scanf("%d %d",&n,&k);
    for (int i = 0; i < n; ++i)
        scanf("%d",v+i);
    
    int a = -1; int b = primes.size()-1;
    while(b - a > 1){
        int mid = (a+b)>>1;
        if(ver(primes[mid])) a = mid;
        else b = mid;
    }
    if(a == -1) puts("0");
    else printf("%d\n",primes[a]);
    return 0;
}

