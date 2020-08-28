#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
int t,n,x;
int v[200010];

int main() {
    scanf("%d", &t);
    while(t--) {

        scanf("%d", &n);
        map<int,int> mp;
        for (int i = 0; i < 2 * n; ++i) {
            scanf("%d", &x);
            mp[x]++;
        }
        
        if(mp.size() == 1) {
            auto val = *mp.begin();
            if(val.second == 2) puts("1");
            else puts("0");
            continue;
        }
        long long ans = 1;
        
        bool flag = 0;

        for (auto p: mp) {
            ans *= p.second;
            ans %= mod;
            flag |= p.second > 1;
        }

        printf("%lld\n", flag ? ans : 0);
        
    }
    return 0;
}

