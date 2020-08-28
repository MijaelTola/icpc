#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<pair<int,int> > G[1010];
int dp[1010];
int f(int u) {
    int &ans = dp[u];
    if(ans != -1) return ans;
    ans = 0;
    for (auto p: G[u]) {
        int v = p.first;
        int w = p.second;
        ans = max(ans, f(v) + w);
    }
    return ans;
}
int main() {
    memset(dp, -1, sizeof dp);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x,y,z;
        cin >> x >> y >> z;
        G[x].push_back({y,z});
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) 
        ans = max(ans, f(i));
    
    cout << ans << "\n";
    return 0;
}

