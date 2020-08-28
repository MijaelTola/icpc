#include <bits/stdc++.h>

using namespace std;

long long f[2000010];
const int mod = 1e9 + 7;

int main() {
    
    f[0] = 1;

    for (int i = 1; i < 2000010; ++i) 
        f[i] = (i * f[i - 1]) % mod;

    int x,y;
    scanf("%d %d", &x, &y);
    
    if((x + y) % 3 != 0) return puts("0"),0;

    auto modpow = [] (long long x, long long y) {
        long long ans = 1;
        x = x % mod;
        while(y) {
            if(y & 1) ans = (ans * x) % mod;
            y >>= 1;
            x = (x * x) % mod;
        }
        return ans;
    };

    auto C = [&modpow](int n, int k) {
        long long x = f[n - k] * f[k];
        return (f[n] * modpow(x, mod - 2)) % mod;
    };


    for (long long i = 0; i <= (x + y) / 3; ++i) {
        long long j = (x + y) / 3 - i;
        if(x == 2 * j + i and y == 2 * i + j) {
            printf("%lld\n", C((x + y) / 3, i));
            return 0;
        }
    }

    puts("0");
   
    return 0;
}

