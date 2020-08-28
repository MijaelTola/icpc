#include <bits/stdc++.h>

using namespace std;

int t,n;
int dp[100010];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    auto check = [] (string a, string b) {
        int da = 0, db = 0, c = 0;
        while(a[da] == b[db] and da < (int)a.size() and db < (int)b.size()) da++, db++, c++;

        int dx = a.size() - 1, dy = b.size() - 1, cc = 0;
        while(a[dx] == b[dy] and dx >= 0 and dy >= 0) dx--, dy--, cc++;
        
        return min(cc,c) * min(cc, c);
    };

    cin >> t;
    auto f = [check] (auto &v) {
        for (int i = 0; i <= n; ++i)
            dp[i] = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; ++j) {
                dp[i] = max(dp[i], dp[j + 1] + check(v[i], v[j]));
            }
            dp[i] = max(dp[i], dp[i + 1]);
        }
        return dp[0];
    };   

    while(t--) {
        cin >> n;
        vector<string> s(n);

        for (auto &x: s)
            cin >> x;

        sort(s.rbegin(), s.rend());
        int a = f(s);
        reverse(s.begin(), s.end());
        a = max(f(s), a);
        
        cout << a << "\n";
    }
    return 0;
}

