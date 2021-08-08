#include <bits/stdc++.h>

using namespace std;

int dp[110][10010];
int pre[110][110];

vector<int> v[110];

int main() {

    for (int i = 0; i < 110; ++i)
        for (int j = 0; j < 110; ++j)
            pre[i][j] = -1e9;

    int n,m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int x;
            cin >> x;
            v[i].push_back(x);
        }
    }

    for (int i = 0; i < n; ++i) {
        int left = 0;
        for (int j = 0, cnt = 1; j < (int)v[i].size(); ++j, cnt++) {
            left += v[i][j];
            int right = 0;
            for (int k = v[i].size() - 1, cnt2 = 1; k > j; k--, cnt2++) {
                right += v[i][k];
                pre[i][cnt + cnt2] = max(pre[i][cnt + cnt2], left + right);
            }
        }
        int sum = 0;
        for (int j = 0; j < (int)v[i].size(); ++j) {
            sum += v[i][j];
            pre[i][j + 1] = max(pre[i][j + 1], sum);
        }
        sum = 0;
        for (int j = v[i].size() - 1, cnt = 1; j >= 0; j--, cnt++) {
            sum += v[i][j];
            pre[i][cnt] = max(pre[i][cnt], sum);
        }
    }

    for (int i = 0; i < 110; ++i) 
        for (int j = 0; j < 10010; ++j)
            dp[i][j] = -1e9;

    dp[n][0] = 0;
    

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= m; ++j) {
            for (int k = 0, cnt = 1; k < (int)v[i].size(); ++k, cnt++) {
                if(j - cnt >= 0) 
                    dp[i][j] = max(dp[i][j], dp[i + 1][j - cnt] + pre[i][cnt]);
            }
            dp[i][j] = max(dp[i][j], dp[i + 1][j]);
        }
    }

    cout << dp[0][m] << "\n";
    return 0;
}

