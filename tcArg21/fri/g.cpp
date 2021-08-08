#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

//piso, cuantos rojos use
int dp[3][100010];

int main() {

    auto modpow = [] (int a, int b) {
        long long x = 1, y = a;
        while(b) {
            if(b & 1) x = (x * y) % mod;
            y = (y * y) % mod;
            b >>= 1;
        }
        return x % mod;
    };

    int a,b;
    cin >> a >> b;

    int l = 0, r = 1010;

    auto check = [&] (int k) {
        int da = a, db = b;
        while(k >= 1) {
            if(da > db) {
                if(da >= k) da -= k;
                else return 0;
            } else {
                if(db >= k) db -= k;
                else return 0;
            }
            k--;
        }
        return 1;
    };

    while(r - l > 1) {
        int mid = (l + r) / 2;
        if(check(mid)) l = mid;
        else r = mid;
    }


    int n = r;

    auto get = [&] (int k) {
        return k * (k + 1) / 2;
    };

    int last = 0;
    for (int i = 0; i <= a; ++i)
        dp[last][i] = 1;


    for (int i = n - 1; i >= 0; i--) {
        int cur = 1 - last;
        for (int j = 0; j <= a; ++j) {
            int &ans = dp[cur][j];
            if(i == n) {
                ans = 1;
                continue;
            }
            ans = 0;

            int total = get(i - 1);
            int verdesUsados = total - j;
            int rojosLeft = a - j;
            int verdesLeft = b - verdesUsados;

            if(rojosLeft >= i) {
                ans += dp[last][i + j];
                ans %= mod;
            }

            if(verdesLeft >= i) {
                ans += dp[last][j];
                ans %= mod;
            }
        }
        last = cur;
    }

    cout << (1LL * dp[last][0] * modpow(2, mod - 2)) % mod << "\n";

    return 0;
}

