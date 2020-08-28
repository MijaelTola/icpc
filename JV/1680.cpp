#include <bits/stdc++.h>

using namespace std;

int n,p;
int dp[10010];
const int mod = 1e9 + 7;

int f(int pos) {
    if(pos >= n) return 1;
    int &ans = dp[pos];
    if(ans != -1) return ans;
    ans = 0;
    for (int i = pos; i < pos + p - 1 and i < n; ++i) 
        ans = (ans + f(i + 2)) % mod;
    ans = (ans + f(pos + 1)) % mod;
    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t; 
    cin >> t;
    while(t--) {
        memset(dp, -1, sizeof dp);
        cin >> n >> p;
        cout << f(1) << "\n";
    }
    return 0;
}

