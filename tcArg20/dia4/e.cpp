#include <bits/stdc++.h>

using namespace std;

int n,m;
int dp[1000010];

int f(int x) {
    if(x <= 0) return 1e9;
    if(x == m) return 0;
    if(x > 1000000) return 1e9;
    int &ans = dp[x];
    if(ans != -1) return ans;
    ans = 1e9;
    ans = min(ans, f(2 * x) + 1);
    ans = min(ans, f(x - 1) + 1);
    return ans;
}

int main() {
    memset(dp, -1, sizeof dp);
    cin >> n >> m;
    cout << f(n) << "\n";
    return 0;
}

