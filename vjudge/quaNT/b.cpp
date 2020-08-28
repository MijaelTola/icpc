#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    scanf("%d", &t);

    while (t--) {
        long long a,b;
        scanf("%lld %lld", &a, &b);

        long long da = a * a;
        long long db = b * b;
        da -= db;
        bool flag = 1;
        
        for (long long i = 2; i * i <= da; ++i) 
            flag &= da % i != 0;
        

        puts( flag ? "YES" : "NO");
        
    }
    return 0;
}

