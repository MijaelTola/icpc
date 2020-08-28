#include <bits/stdc++.h>

using namespace std;

int n,m,l;

long long G[310][310];
long long p[310][310];

vector<int> path;
void f(int i, int j) {
    if(i != j) f(i, p[i][j]);
    path.push_back(j);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> n >> m >> l;

    for (int i = 0; i < 310; ++i)
        for (int j = 0; j < 310; ++j)
            G[i][j] = 1e18, p[i][j] = i;

    for (int i = 0; i < m; ++i) {
        int x,y,z;
        cin >> x >> y >> z;
        if(z > l) continue;
        x--,y--;
        G[x][y] = z;
        G[y][x] = z;
    }
    for (int k = 0; k < n; ++k) 
        for (int i = 0; i < n; ++i) 
            for (int j = 0; j < n; ++j) 
                if(G[i][k] + G[k][j] < G[i][j]) {
                    G[i][j] = G[i][k] + G[k][j];
                    p[i][j] = p[k][j];
                }
    int q;
    cin >> q;
    while(q--) {
        path.clear();
        int x,y;
        cin >> x >> y;
        x--,y--;
        f(x,y);
        long long ans = 0;
        long long cur = l;
        bool flag = 1;
        for (int i = 1; i < (int)path.size(); ++i) {
            long long cost = G[path[i - 1]][path[i]];
            if(cost == 1e18) {
                flag = 0;
                break;
            }
            if(cur - cost >= 0) cur -= cost;
            else {
                ans++;
                cur = l;
                if(cur - cost >= 0) cur -= cost;
                else {
                    flag = 0;
                    break;
                }
            }
        }
        if(!flag) cout << "-1\n";
        else cout << ans << "\n"; 
    }
    return 0;
}

