#include <bits/stdc++.h>

using namespace std;

class Solution {
    long long dp[3][3][1 << 10];
public:
    long long wonderfulSubstrings(string word) {
        
        int last = 1;
        for (int i = 0; i < (1 << 10); ++i) {
            if(__builtin_popcount(i) <= 1) {
                dp[last][2][i] = 1;
            }
        }

        for (int i = word.size() - 1; i >= 0; i--) {
            int cur = 1 - last;
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < (1 << 10); ++k) {
                    long long &ans = dp[cur][j][k] = 0;
                    int val = word[i] - 'a';
                    if(j == 0) {
                        ans += dp[last][0][k];
                        ans += dp[last][1][k ^ (1 << val)];
                        ans += dp[last][2][k ^ (1 << val)];
                    }
                    if(j == 1) {
                        ans += dp[last][1][k ^ (1 << val)];
                        ans += dp[last][2][k ^ (1 << val)];
                    }
                    if(j == 2) {
                        ans += dp[last][2][k];
                    }
                }
            }
            last = cur;
        }

        return dp[last][0][0];
    }
};


int main() {
    Solution sol;
    cout << sol.wonderfulSubstrings("aba") << "\n";
    return 0;
}

