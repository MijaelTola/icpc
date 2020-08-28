#include <bits/stdc++.h>

using namespace std;

int main() {

    int n,m;
    cin >> n >> m;
    vector<int> dx(n), dy(m);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int x;
            cin >> x;
            dx[i] += x;
            dy[j] += x;
        }
    }
    
    auto comb = [] (int x) {
        return x * (x - 1) / 2;
    };

    int ans = n * m;
    
    for (int i = 0; i < n; ++i) {
        ans += comb(dx[i]);
        ans += comb(m - dx[i]);
    }

    for (int i = 0; i < m; ++i) {
        ans += comb(dy[i]);
        ans += comb(n - dy[i]);
    }

    cout << ans << "\n";
    return 0;
}

