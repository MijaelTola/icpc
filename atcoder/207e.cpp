#include <bits/stdc++.h>

using namespace std;

int n;
long long v[3010];
int dp[3010][3010];
const int mod = 1e9 + 7;

int f(int pos, int cur) {
    if(pos == n) return 1;
    int &ans = dp[pos][cur];
    if(ans != -1) return ans;
    ans = 0;
    long long sum = 0;
    for (int i = pos; i < n; ++i) {
        sum += v[i];
        if(sum % cur == 0) {
            ans += f(i + 1, cur + 1);
            ans %= mod;
        }
    }

    return ans;
}


int main() {
    memset(dp, -1, sizeof dp);
    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> v[i];

    cout << f(0, 1) << "\n";
    return 0;
}

