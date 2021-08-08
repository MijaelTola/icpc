#include <bits/stdc++.h>

using namespace std;

long long dp[100010][2];

long long maxAlternatingSum(vector<int>& nums) {
 
    int n = nums.size();

    for (int i = 0; i < n + 10; ++i)
        for (int j = 0; j < 2; ++j)
            dp[i][j] = -1e15;

    dp[n][1] = dp[n][0] = 0;

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < 2; ++j) {
            dp[i][j] = max(dp[i][j], dp[i + 1][1 - j] + (j == 0 ? 1 : -1) * nums[i]);
            dp[i][j] = max(dp[i][j], dp[i + 1][j]);
        }
    }
    return dp[0][0];
}

int main() {

    return 0;
}

