#include <bits/stdc++.h>

using namespace std;

int dp[100010];
vector<int> G[100010];

int f(int u) {
    int &ans = dp[u];
    if(ans != -1) return ans;
    ans = 0;
    for (int v: G[u]) ans = max(ans, f(v) + 1);
    return ans;
}

int main() {
    memset(dp, -1, sizeof dp);
    int n,m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int x,y;
        cin >> x >> y;
        G[x].push_back(y);
    }
 
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        if(dp[i] == -1) ans = max(ans, f(i));
    cout << ans << "\n";
    return 0;
}

