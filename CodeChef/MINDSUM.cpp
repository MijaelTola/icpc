#include <bits/stdc++.h>

using namespace std;

int sum(long long x) {
    int ans = 0;
    while(x > 0) {
        ans += x % 10;
        x /= 10;
    }
    return ans;
}

bool vis[200];

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        memset(vis, 0, sizeof vis);
        long long n,d;
        scanf("%lld%lld",&n,&d);
        queue<pair<long long, int> > q;

        long long ans = 1e18;
        long long cnt = 1e9;
        q.push(make_pair(sum(n),0));
        for (int i = 0; i < 1000; ++i) {
            if(d + n < 1e17) {
                q.push(make_pair(sum(d + n), i + 1));
                n += d;
            } else break;
        }
        while(!q.empty()) {
            long long u = q.front().first;
            long long c = q.front().second;
            q.pop();
            if(vis[u]) continue;
            vis[u] = 1;
            if(u < ans) {
                ans = u;
                cnt = c;
            } 
            q.push(make_pair(sum(u), c + 1));
            for (int i = 0; i < 1000; ++i) 
                if(u + d < 1e17) {
                    q.push(make_pair(sum(u + d), c + (i + 1)));
                    u += d;
                } else break;
            
        }
        printf("%lld %lld\n",ans, cnt + 1);
    }
    return 0;
}

