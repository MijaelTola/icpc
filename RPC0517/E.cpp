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
int main(){
    criba();

    scanf("%d %d",&n,&k);
    for (int i = 0; i < n; ++i)
        scanf("%d",v+i);
    int p = 0;
    int gcd = v[0];
    int ans = 1e9;
    int last = gcd;
    for (int i = 1; i < n; ++i){
        last = gcd;
        gcd = __gcd(gcd,v[i]);
        if(gcd == 1){ 
            ans = min(ans,factors(last));    
            gcd = v[i]; p++;
        }
    }
    ans = min(ans,factors(gcd));
    if(p >= k) printf("0\n");
    else printf("%d\n",ans);
    return 0;
}

