#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int n;
vector<int> G[100010];
long long dp[100010][2];

long long f(int u, int flag, int p) {
    auto &ans = dp[u][flag];
    if(ans != -1) return ans;
    ans = 1;
    for (int v: G[u]) {
        if(v == p) continue;
        if(flag) {
            ans *= (f(v, !flag, u));
            ans %= mod;
        } else {
            ans *= (f(v, flag, u) + f(v, !flag, u)) % mod;
            ans %= mod;
        }
    }
    return ans;
}

int main() {
    memset(dp, -1, sizeof dp);
    cin >> n;

    for (int i = 0; i < n - 1; ++i) {
        int x,y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    cout << (f(1,0,1) + f(1,1,1)) % mod<< "\n";
    return 0;
}

