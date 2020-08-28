#include <bits/stdc++.h>

using namespace std;

int c,v,l,k;
long long dp[510][3];
const int mod = 1e9 + 7;

long long add(long long a, long long b) {
    return (a + b) % mod;
}

long long f(int pos, bool flag) {
    if(pos == l) return flag;
    long long &ans = dp[pos][flag];
    if(ans != -1) return ans;
    ans = 0;
    if(flag) {
        for (int i = 0; i < c; ++i)
            ans = add(ans,f(pos + 1, !flag));
    } else {

        for (int i = 0; i < v; ++i) {
            ans = add(ans,f(pos + 1, flag));
            ans = add(ans,f(pos + 1, !flag));
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
        long long ans = f(0, 1) + f(0, 0);
        cout << ans % mod << " ";
        if(ans < k) cout << "Rejected\n";
        else cout << "Accepted\n";
    }
    return 0;
}

