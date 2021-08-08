#include <bits/stdc++.h>

using namespace std;

int n,m;
int dp[200010][3];
vector<int> G[200010];
int a[200010];

int f(int u, int flag) {
    
    if(flag == 2) return 0;

    int &ans = dp[u][flag];
    if(ans != -1) return ans;
    ans = -1e9;

    if(flag == 1) ans = a[u];

    for (int v: G[u]) {
        if(flag == 0) {
            ans = max(ans, f(v, 0));
            ans = max(ans, f(v, 1) - a[u]);
        }

        if(flag == 1) {
            ans = max(ans, f(v, 1));
            ans = max(ans, f(v, 2) + a[u]);
        }
    }
    return ans;
}

int main() {

    memset(dp, -1, sizeof dp);

    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 0; i < m; ++i) {
        int x,y;
        cin >> x >> y;
        G[x].push_back(y);
    }

    
    //cout << f(1, 0) << "\n";
    //exit(0);
    int ans = -1e9;

    for (int i = 1; i <= n; ++i) {
        ans = max(ans, f(i, 0));
    }

    cout << ans << "\n";
    return 0;
}

