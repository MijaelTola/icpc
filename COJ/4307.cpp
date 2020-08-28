#include <bits/stdc++.h>

using namespace std;

int c,v,l,k;
long long dp[510][3];
const int mod = 1e9 + 7;
long long f(int pos, bool flag) {
    if(pos == l) return flag;
    long long &ans = dp[pos][flag];
    if(ans != -1) return ans;
    ans = 0;
    if(flag) {
        for (int i = 0; i < c; ++i) 
            ans += f(pos + 1, !flag);
    } else {
        for (int i = 0; i < v; ++i) {
            ans += f(pos + 1, !flag);
            ans += f(pos + 1, flag);
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        memset(dp, -1, sizeof dp);
        cin >> c >> v >> l >> k;
        long long ans = f(0,0) + f(0,1);
        cout << ans << " ";
        if(c * v * l > 90 or ans >= k)  cout << "Accepted\n";
        else cout << "Rejected\n";
    }
    return 0;
}

