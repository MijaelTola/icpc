#include <bits/stdc++.h>

using namespace std;

long long G[55][55];
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    for (int cases = 1; cases <= t; ++cases) {
        for (int i = 0; i < 55; ++i)
            for (int j = 0; j < 55; ++j)
                G[i][j] = 1e9;
        int n,m;
        cin >> n >> m;
        vector<pair<long long, pair<int,int> > > edges;
        for (int i = 0; i < m; ++i) {
            long long x,y,w;
            cin >> x >> y >> w;
            G[x][y] = w;
            G[y][x] = w;
            edges.push_back({w, {x,y}});
        }

        for (int k = 1; k <= n; ++k) 
            for (int i = 1; i <= n; ++i) 
                for (int j = 1; j <= n; ++j) 
                    G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
        
        bool flag = 1;
        for (int i = 0; i < m; ++i) {
            int x = edges[i].second.first;
            int y = edges[i].second.second;
            long long w = edges[i].first;
            flag &= (w == G[x][y]);
        }

        cout << "Case #" << cases << ": ";
        if(!flag) {
            cout << "Impossible\n";
            continue;
        }
        cout << m << "\n";
        for (int i = 0; i < m; ++i) {
            int x = edges[i].second.first;
            int y = edges[i].second.second;
            long long w = edges[i].first;
            cout << x << " " << y << " " << w << "\n";
        }
    }
 
    return 0;
}

