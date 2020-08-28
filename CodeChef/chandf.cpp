#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    scanf("%d", &t);

    while(t--) {
        long long x,y,l,r;
        scanf("%lld %lld %lld %lld", &x, &y, &l, &r);
        
        
        long long p = 1;

        while(p <= r) p <<= 1;
        p>>=1;
        p--;
        printf("%lld\n", (p & (x | y)));
    }
            
    return 0;
}

