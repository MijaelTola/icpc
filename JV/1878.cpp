#include <bits/stdc++.h>

using namespace std;

int n;
int v[10];
int dp[200][200][200];

int f(int pos, int k, int sum) {
    if(pos == n) {
        if(sum == 0) return 0;
        return 1e9;
    }
    int ans = 1e9;
    for (int i = k; i < 10; ++i) 
        for (int j = 1; j <= v[k]; ++j) 
            ans = min(ans, f(pos + j, i + 1, (sum + j * k) % 3) + j * k);
    return ans;
}

int main() {
    memset(dp, 30, sizeof dp);
    cin >> n;
    for (int i = 0; i < 10; ++i)
        cin >> v[i];

    for (int i = 0; i < 10; ++i)
        dp[n][i][0] = 0;


    for (int pos = n - 1; pos >= 0; pos--) {
        for (int k = 0; k < 10; ++k) {
            for (int sum = 0; sum < 200; ++sum) {
                for (int i = k; i < 10; ++i) {
                    for (int j = 1; j <= v[k]; ++j) {
    dp[pos][k][sum] = min(dp[pos][k][sum], dp[pos + j][i + 1][(sum + j * k) % 3] + j * k);
                    }
                }
            }
        }
    }

    cout << dp[0][0][0] << " lala\n";
    return 0;
}

