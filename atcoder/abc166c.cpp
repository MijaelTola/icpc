#include <bits/stdc++.h>

using namespace std;

int a[200010];
vector<int> G[200010];

int main() {
    
    int n,m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 0; i < m; ++i) {
        int x,y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        bool flag = 1;
        for (int j: G[i]) {
            flag &= a[i] > a[j];
        }
        ans += flag;
    }
    cout << ans << "\n";
    return 0;
}

