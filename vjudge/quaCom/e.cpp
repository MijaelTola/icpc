#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
int main() {

    int n,m;
    cin >> n >> m;
    
    set<int> s[110];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char x;
            cin >> x;
            s[j].insert(x);
        }
    }

    long long ans = 1;

    for (int i = 0; i < m; ++i) {
        ans *= s[i].size();
        ans %= mod;
    }
    cout << ans << "\n";
    return 0;
}
