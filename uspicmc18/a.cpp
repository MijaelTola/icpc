#include <bits/stdc++.h>

using namespace std;

int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

int main() {
    long long n,k;
    scanf("%lld%lld",&n,&k);
    long long ans = 0;
    long long real = k;
    k = real;
    if(k > n / 2) k = n - k;
    if(__gcd(n,k) > 1) {
        long long lines = n / __gcd(n,k);
        long long total = lines * __gcd(n,k) - __gcd(n,k);
        ans = total * real + (__gcd(n,k) - 1) * (real - 1);
    } else ans = (n - 1) * real;
    printf("%lld\n",ans);
    return 0;
}
