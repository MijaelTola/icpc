#include <bits/stdc++.h>

using namespace std;

int n,m;
int v[300010];
int dp[300010];
int f(int pos) {
    if(pos >= n) return 0;
    int &ans = dp[pos];
    if(ans != -1) return ans;
    ans = 0;
    ans = max(ans, f(pos + m) + v[pos]);
    ans = max(ans, f(pos + 1));
    return ans;
}
int main() {
    memset(dp, -1, sizeof dp);
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
        cin >> v[i];
    cout << f(m) << "\n";
    return 0;
}

