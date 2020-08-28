#include <bits/stdc++.h>

using namespace std;

int v[100010];
long long cnt[1000010];

int main(){
    
    int t; 
    scanf("%d", &t);
    while(t--) {
        memset(v, 0, sizeof v);
        memset(cnt, 0, sizeof cnt);
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d", v + i);

        long long e = 0, o = 0;
        int ones = 0;
        int tr = 0;
        for (int i = 0; i < n; ++i) {
            if(v[i] & 1) o++;
            else e++; 
            cnt[v[i]]++;
        }
        
        long long cp = e * (e - 1) / 2;
        long long ci = o * (o - 1) / 2;
        long long rp = 0;
        long long ri = 0;
        for (int i = 1; i <= 1000000; ++i) {
            long long c = cnt[i] * (cnt[i] - 1) / 2;
            if(i & 1) ri += c;
            else rp += c;
        }
        for (int i = 1; i <= 1000000; i += 4) 
            if(cnt[i] and cnt[i + 2]) ri += cnt[i] * cnt[i + 2];
        
        for (int i = 4; i <= 1000000; i += 4) 
            if(cnt[i] and cnt[i + 2]) 
                rp += cnt[i] * cnt[i + 2];

        cp -= rp, ci -= ri;
        printf("%lld\n",cp + ci);

    }
    return 0;
}
