#include <bits/stdc++.h>

using namespace std;

int n;
bool vis[20][20];
int dx[] = {0,0,-1,1,1,-1,-1,1};
int dy[] = {1,-1,0,0,1,-1,1,-1};

bool ver(int x, int y) {
    return x >= 0 and y >= 0 and x < n + 1  and y < n + 1 and !vis[x][y];
}

int dfs(int x, int y, int k) {
    if(k == 0) return 1;
    int ans = 0;
    for (int i = 0; i < 8; ++i) {
        int u = dx[i] + x;
        int v = dy[i] + y;
        if(ver(u, v)) {
            vis[u][v] = 1;
            ans += dfs(u, v, k - 1);
            vis[u][v] = 0;
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        cin >> n;
        cout << dfs(0,0, n) << "\n";
    }
    return 0;
}

