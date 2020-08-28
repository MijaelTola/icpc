#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
int n;
string s;
long long e[100010];
pair<long long,long long> dp[100010][2][10];
pair<long long,long long> f(int pos, bool flag, int dig) {
    if(pos == n) return {0, 1};
    if(dp[pos][flag][dig].first != -1) return dp[pos][flag][dig];
    long long ans = 0;
    long long cnt = 0;
    int lim = flag ? s[pos] - '0' : 9;
    for (int i = 0; i <= lim; ++i) {
        long long curP = n - pos - 1; 
        if(i == lim and flag) {
            auto p = f(pos + 1, 1, i);
            ans = (ans + (p.first + i * (((e[curP] * (dig != i)) % mod) * p.second) % mod) % mod) % mod;
            cnt = (cnt + p.second) % mod;
        } else {
            auto p = f(pos + 1, 0, i);
            ans = (ans + (p.first + i * (((e[curP] * (dig != i)) % mod) * p.second) % mod) % mod) % mod;
            cnt = (cnt + p.second) % mod;
        }
    }
    return dp[pos][flag][dig] = {ans, cnt};
}

long long solve(int cn, string cs) {
    for (int i = 0; i < 100010; ++i)
            for (int j = 0; j < 2; ++j)
                for (int k = 0; k < 10; ++k)
                    dp[i][j][k].first = dp[i][j][k].second = -1;

    n = cn; s = cs;
    return f(0,1,0).first;
}

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
    ios::sync_with_stdio(false); cin.tie(0);
    e[0] = 1;
    for (int i = 1; i < 100010; ++i) 
        e[i] = (e[i - 1] * 10) % mod;
    int t;
    cin >> t;
    while(t--) {
        int nl,nr;
        string l,r;
        cin >> nl >> l >> nr >> r;
        l = substract(l);
        cout <<  ((solve(nr, r) -   solve(nl, l)) + mod) % mod << "\n";
    }
    return 0;
}

