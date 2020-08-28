#include <bits/stdc++.h>

using namespace std;

int dr;
long long v[20000];
long long dp[1 << 16][20];

long long f(int x, int lvl, int l = 0, int r = (1 << dr) - 1) {
    if(lvl == dr or l == r) return 0;

    int mid = (l + r) / 2;
    
    long long &ans = dp[x][lvl];

    if(ans != -1) return ans;
    ans = LLONG_MAX;

    auto check = [&] (int a, int b) -> long long{
        if(v[a] > v[b]) return 0;
        return (v[a] - v[b]) * (v[a] - v[b]);
    };
    
    if(x <= mid) {
        long long cur = f(x, lvl + 1, l, mid);
        for (int i = mid + 1; i <= r; ++i) 
            ans = min(ans, cur + f(i, lvl + 1, mid + 1, r) + check(x,i));

    } else {
        long long cur = f(x, lvl + 1, mid + 1, r);

        for (int i = l; i <= mid; ++i) 
            ans = min(ans, cur + f(i, lvl + 1, l, mid) + check(x,i));
    }
    
    return ans;
}

int main() {
    cin >> dr;

    memset(dp, -1, sizeof dp);
    for (int i = 0; i < (1 << dr); ++i)
        cin >> v[i];

    cout << f(0, 0) << "\n";

    return 0;
}
