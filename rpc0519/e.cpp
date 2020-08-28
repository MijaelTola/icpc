#include <bits/stdc++.h>

using namespace std;

int n,m,x,y;
int a[500010];
vector<int> G[500010];
double dp[500010][67];
double get(int p, int pos) {
    return 1.0 / (1LL << p) * (double)a[pos];
}

double f(int u, int k, int parent) {
    if(k > 32) return 0;
    double &ans = dp[u][k];
    if(ans != -1) return ans;
    ans = 0;
    for (int v: G[u]) {
        if(parent == v) continue;
        ans = max(ans, f(v, k, u));
        ans = max(ans, f(v, k + 1, u) + get(k, v));
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    for (int i = 0; i < 500010; ++i)
        for (int j = 0; j < 35; ++j)
            dp[i][j] = -1;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        G[x].push_back(y);
    }
    G[500002].push_back(0);
    cout.precision(10);
    cout << fixed << f(500002, 0, 500002) << "\n";
    return 0;
}

