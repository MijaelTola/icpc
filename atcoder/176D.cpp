#include <bits/stdc++.h>

using namespace std;

char c[1010][1010];
int d[1010][1010];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int main() {

    ios::sync_with_stdio(false); cin.tie(0);
    for (int i = 0; i < 1010; ++i)
        for (int j = 0; j < 1010; ++j) 
            d[i][j] = 1e9;

    int n,m;
    cin >> n >> m;

    int a,b,s,t;
    cin >> a >> b >> s >> t;
    a--,b--,s--,t--;


    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < m; ++j)
            cin >> c[i][j];

    deque<pair<int,int> > q;
    
    q.push_front({a,b});
    d[a][b] = 0;
    while(!q.empty()) {
        auto [x,y] = q.front();
        q.pop_front();

        if(x == s and y == t) break;

        for (int i = 0; i < 4; ++i) {
            int u = dx[i] + x;
            int v = dy[i] + y;
            if(u >= 0 and u < n and v >= 0 and v < m and c[u][v] == '.') {
                if(d[x][y] < d[u][v]) {
                    d[u][v] = d[x][y];
                    q.push_front({u,v});
                }
            }
        }

        for (int i = x - 2; i <= x + 2; ++i) {
            for (int j = y - 2; j <= y + 2; ++j) {
                int u = i, v = j;
                if(u >= 0 and u < n and v >= 0 and v < m and c[u][v] == '.') {
                    if(d[x][y] + 1 < d[u][v]) {
                        d[u][v] = d[x][y] + 1;
                        q.push_back({u,v});
                    }
                }
            }
        }

    }
    if(d[s][t] == 1e9) cout << "-1\n";
    else cout << d[s][t] << "\n";
    return 0;
}

