#include <bits/stdc++.h>

using namespace std;

int t,n,X,x,y;
int v[100010];
vector<int> G[100010];
long long dp[100010];
long long f(int u, int p) {
    long long &ans = dp[u];
    if(ans != -1) return ans;
    ans = v[u];
    for (int v: G[u]) {
        if(v == p) continue;
        ans += f(v, u);
    }
    return max(ans, (long long)-X);
}

int main() {
    scanf("%d", &t);
    while(t--) {
        vector<pair<int,int> > neg;
        for (int i = 0; i < 100010; ++i) {
            G[i].clear();
            dp[i] = -1;
        }
        scanf("%d %d", &n, &X);
        for (int i = 0; i < n; ++i)
            scanf("%d", v + i);

        for (int i = 0; i < n - 1; i++) {
            scanf("%d %d", &x, &y);
            x--,y--;
            G[x].push_back(y);
            G[y].push_back(x);
        }

        printf("%lld\n", f(0,0));
    }
    return 0;
}

