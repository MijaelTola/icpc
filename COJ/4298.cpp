#include <bits/stdc++.h>

using namespace std;

bool vis[1010];
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        memset(vis, 0, sizeof vis);
        int n,m;
        cin >> n >> m;
        for (int i = 0; i < m; ++i) {
            int x;
            cin >> x;
            vis[x] = 1;
        }
        for (int i = 1; i <= n; ++i)
            if(!vis[i]) cout << i << " ";
        cout << "\n";
    }
    return 0;
}

