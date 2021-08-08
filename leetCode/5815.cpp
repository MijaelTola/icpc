#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int m = points[0].size();
        long long dp[n + 1][m + 1];

        for (int i = 0; i < n + 1; ++i)
            for (int j = 0; j < m + 1; ++j)
                dp[i][j] = -1e15;

        for (int j = 0; j < m; ++j)
            dp[n][j] = 0;

        for (int i = n - 1; i >= 0; i--) {
            for (int k = 0; k < m; ++k) { 
                ans = max(ans, dp[i + 1][k] + points[i][k] - abs(j - k));
            }
        }

        long long res = -1e15;
        for (int i = 0; i < m; ++i) {
            res = max(res, dp[1][i] + points[0][i]);
        }


        return res;
    }
};
int main() {

    return 0;
}

