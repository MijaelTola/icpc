#include <bits/stdc++.h>

using namespace std;

int n,m;
int dp[1010][1 << 12];
int v[1010];
int val[1010];

int f(int pos, int mask) {
    if(pos == m) {
        if(mask == (1 << n) - 1) return 0;
        return 1e9;
    }
    int &ans = dp[pos][mask];
    if(ans != -1) return ans;
    ans = 1e9;
    ans = min(ans, f(pos + 1, mask | v[pos]) + val[pos]);
    ans = min(ans, f(pos + 1, mask));
    return ans;
}

int main() {
    memset(dp, -1, sizeof dp);
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int a,b;
        scanf("%d %d", &a, &b);
        val[i] = a;
        for (int j = 0; j < b; ++j) {
            int x;
            scanf("%d", &x);
            x--;
            v[i] |= (1 << x);
        }
    }
    int ans = f(0,0);
    if(ans == 1e9) puts("-1");
    else printf("%d\n", ans);
    return 0;
}

