#include <bits/stdc++.h>
using namespace std;

int dp[100010][2][2][11];

const int mod = 998244353;

string substract(string x) {
    string ans = "";
    bool flag = 0;
    for (int i = x.size() - 1; i >= 0; i--) {
        int val = ((int)x.size() - 1 == i) ? 1 : 0;
        val = (int)(x[i] - '0') - val - flag;
        if(val < 0) {
            val += 10;
            flag = 1;
        } else flag = 0;
        ans += (char)(val + '0');

    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {

    auto f = [&] (string s) {
        memset(dp, 0, sizeof dp);
        int n = s.size();

        for (int i = 0; i < 10; ++i) {
            dp[n][0][1][i] = dp[n][1][1][i] = 1;
        }

        for (int pos = n - 1; pos >= 0; pos--) 
            for (int flag = 0; flag < 2; ++flag) 
                for (int cero = 0; cero < 2; cero++) {
                    for (int last = 0; last < 10; ++last) {
                        int lim = flag ? s[pos] - '0' : 9;
                        for (int i = 0; i <= lim; ++i) {

                            if(cero) {
                                if(last != i) {
                                    dp[pos][flag][cero][last] += dp[pos + 1][i == lim and flag][1][i];
                                    dp[pos][flag][cero][last] %= mod;
                                }
                            } else {
                                dp[pos][flag][cero][last] += dp[pos + 1][i == lim and flag][i != 0][i];
                                dp[pos][flag][cero][last] %= mod;
                            }
                        }
                    }

                }


        return dp[0][1][0][0] % mod;
    };

       string a,b;
       cin >> a >> b;
       cout << (f(b) - f(substract(a)) + mod) % mod << "\n";
    return 0;
}
