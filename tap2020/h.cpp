#include <bits/stdc++.h>

using namespace std;

int n,k;
long long dp[55][2][55];
string bin;
long long f(int pos, int flag, int dk) {
    if(pos == (int)bin.size())
        return dk == k;

    long long &ans = dp[pos][flag][dk];

    if(ans != -1) return ans;
    ans = 0;

    int lim = 1;
    if(flag) lim = bin[pos] - '0';

    for (int i = 0; i <= lim; ++i) 
        ans += f(pos + 1, flag and i == lim, dk + (i == 1));

    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    long long l,r;

    cin >> n >> k;

    vector<long long> v(n);

    for (auto &x: v)
        cin >> x;
    cin >> l >> r;


    sort(v.begin(), v.end());

    auto to_bin = [&] (long long x) {
        string ans = "";
        while(x > 0) {
            if(x & 1) ans += "1";
            else ans += "0";
            x >>= 1LL;  
        }
        reverse(ans.begin(), ans.end());
        return ans;
    };

    auto count = [&] (long long x) {
        long long a = 0, b = (1LL << n);

        auto check = [&] (long long y) {
            long long ans = 0;
            for (int i = 0; i < n; ++i) {
                if(y & (1LL << i)) {
                    ans += v[i];
                }
            }
            return ans;
        };

        while(b - a > 1) {
            long long mid = (a + b) / 2;
            if(check(mid) <= x) a = mid;
            else b = mid;
        }

        bin = to_bin(a);
        memset(dp, -1, sizeof dp);
        return f(0, 1, 0);
    };
    
    cout << count(r) - count(l - 1) << "\n";

    return 0;
}

