#include <bits/stdc++.h>

using namespace std;

long long  dp[5000][5000];
vector<pair<int,int> > v;

int main() {
    int n;
    cin >> n;


    for (int i = 0; i < n; ++i) {
        int x,y;
        cin >> x >> y;
        v.push_back({x, y});
    }

    for (int i = 0; i < 5000; ++i)
        for (int j = 0; j < 5000; ++j)
            dp[i][j] = 1e15;

    for (int i = 0; i < 5000; ++i)
        dp[n][0] = 0;

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= n; ++j) {
            dp[i][j] = 1e15;
            dp[i][j] = min(dp[i][j], dp[i + 1][j]);
            dp[i][j] = min(dp[i][j], dp[i + 1][max(0, j - v[i].first - 1)] + v[i].second);
        }
    }

    cout << dp[0][n] << "\n";
    return 0;
}

