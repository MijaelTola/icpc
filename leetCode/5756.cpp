#include <bits/stdc++.h>

using namespace std;

int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
    
    int n = nums1.size();
    vector<int> dp(n + 10, 1e9);
    dp[(1 << n) - 1] = 0;
    for (int i = (1 << n) - 2; i >= 0; --i) {
        int cnt = __builtin_popcount(i);
        for (int j = 0; j < n; ++j) {
            if(!(i & (1 << j))) {
                dp[i] = min(dp[i], dp[i | (1 << j)] + (nums1[cnt] ^ nums2[j]));
            }
        }
    }
    return dp[0];
}

int main() {

    vector<int> a = {1, 0, 3};
    vector<int> b = {5, 3, 4};
    cout << minimumXORSum(a,b) << "\n";

    return 0;
}

