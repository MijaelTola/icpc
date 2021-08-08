#include <bits/stdc++.h>

using namespace std;

int dp[1510][1510][3];

int findLength(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();
    
    for (int i = n; i >= 0; i--) {
        for (int j = m; j >= 0; j--) {
            for (int k = 2; k >= 0; k--) {
                int &ans = dp[i][j][k] = -1e9;
                if(k == 2) {
                    ans = 0;
                    continue;
                }
                if(i == n or j == m) {
                    ans = -1e9;
                    continue;
                }

                if(k == 0) {
                    if(nums1[i] == nums2[j]) {
                        ans = max(ans, dp[i + 1][j + 1][1] + 1);
                        ans = max(ans, dp[i + 1][j + 1][2] + 1);
                    }
                    ans = max(ans, dp[i + 1][j][0]);
                    ans = max(ans, dp[i][j + 1][0]);
                }
                if(k == 1) {
                    if(nums1[i] == nums2[j]) {
                        ans = max(ans, dp[i + 1][j + 1][1] + 1);
                        ans = max(ans, dp[i + 1][j + 1][2] + 1);
                    }
                }
            }
        }
    }
    return max(0, dp[0][0][0]);
}

int main() {
    
    vector<int> a = {1,2,3,2,1};
    vector<int> b = {3,2,1,4,7};

    cout << findLength(a,b) << "\n";
    return 0;
}

