#include <bits/stdc++.h>

using namespace std;


string s;
long long dp[35][3][3];

long long f(int pos, bool flag, bool flag2) {
    if(pos == (int)s.size()) {
        return 1;
    }

    long long &ans = dp[pos][flag][flag2];
    if(ans != -1) return ans;
    ans = 0;
    int lim = 1;
    if(flag) lim = s[pos] - '0';

    for (int i = 0; i <= lim; ++i) {
        if(i == 0) {
            if(flag2) {
                ans += f(pos + 1, flag and i == lim, flag2);
            } else {
                ans += 2 * f(pos + 1, flag and i == lim, 0);
            }
        }
        else ans += f(pos + 1, flag and i == lim, i < lim);
    }

    return ans;
}

int main() {

    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    while(cin >> n) {
        memset(dp, -1, sizeof dp);
        s = "";
        while (n > 0) { 
            if (n % 2 == 0) s += "0";
            else s += "1";
            n >>= 1;
        } 
        reverse(s.begin(), s.end());

        cout << f(0, 1, 1) << "\n";
    }
    return 0;
}

