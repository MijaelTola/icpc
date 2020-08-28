#include <bits/stdc++.h>

using namespace std;

int t,n;
long long a,b,c,d,ans;

int main() {
    
    auto print = [](long long x) {
        printf("%lld\n", x);
        fflush(stdout);
    };

    scanf("%d", &t);

    while(t--) {
        scanf("%d %lld", &n, &a);
        
        long long p = 1;

        for (int i = 0; i < n; ++i) 
            p *= 10;
        
        p--;
        
        long long s = a + p + p + 2;
        print(s);
        s -= a;
        scanf("%lld", &b);
        s -= b;
        print(s - p - 1);
        s = s - (s - p - 1);
        scanf("%lld", &d);
        s -= d;
        print(s);
        scanf("%lld", &ans);
        assert(ans != -1);

    }
    return 0;
}

