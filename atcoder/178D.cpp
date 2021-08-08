#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int s;
int dp[2010];

int f(int sum) {
    if(sum == s) return 1;

    int &ans = dp[sum];
    if(ans != -1) return ans;
    ans = 0;

    for (int i = 3; i <= 2000; ++i) {
        if(sum + i <= s) {
            ans += f(sum + i);
            ans %= mod;
        }
    }
    return ans;
}

int main() {
    memset(dp, -1, sizeof dp);
    cin >> s;
    cout << f(0) << "\n";
    return 0;
}

