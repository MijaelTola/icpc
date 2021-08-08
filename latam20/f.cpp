#include <bits/stdc++.h>

using namespace std;

int dp[8010][8010];
int pre[8010][8010];
int v[8010];


void compute(int g, int i, int j, int l, int r) {
    if (i > j)
        return;
    int mid = (i + j) / 2;
    int bestIndex = l;
    for (int k = l; k <= min(r, mid); k++) {
        int val = dp[k - 1][g - 1] + pre[k][mid];
        if (val < dp[mid][g]) {
            dp[mid][g] = val;
            bestIndex = k;
        }
    }
    compute(g, i, mid - 1, l, bestIndex);
    compute(g, mid + 1, j, bestIndex, r);
}

int main() {


    for (int i = 0; i < 8010; ++i) 
        for (int j = 0; j < 8010; ++j)
            dp[i][j] = 1e9;

    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
    }

    for (int i = 1; i <= n; ++i) {
        int mx = 0;
        for (int j = i; j <= n; ++j) {
            mx = max(mx, v[j]);
            pre[i][j] = pre[j][i] = mx;
        }
    }

    dp[0][0] = 0;

    for (int i = 1; i <= n; ++i) {
        compute(i, 1, n, 1, n);
    }

    sort(v + 1, v + n + 1);
    reverse(v + 1, v + n + 1);

    for (int i = 1; i <= n; ++i) {
        v[i] += v[i - 1];
    }

    for (int i = 1; i <= n; ++i) {
        cout << dp[n][i] << " " << v[i] << "\n";
    }

    return 0;
}

