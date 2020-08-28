#include <bits/stdc++.h>

using namespace std;

int c[1000][1000];
int dp[1000][1000];
int dis[1000][1000];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int main() {

    int t;
    cin >> t;

    while(t--) {
        int n,m;
        cin >> n >> m;

        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= m; ++j)
                dis[i][j] = 1e9;

        for (int i = 0; i < n; ++i) 
            for (int j = 0; j < m; ++j) 
                cin >> c[i][j];
        
        priority_queue<tuple<int,int,int> > q;

        q.push({0, 0, 0});
        dis[0][0] = 0;
        
        auto ver = [&] (int x, int y) {
            return x >= 0 and x < n and y >= 0 and y < m;
        };

        while(!q.empty()) {
            int d,x,y;
            tie(d,x,y) = q.top();
            q.pop();
            //cout << x << " " << y << ": " << dis[x][y] << "\n";
            for (int i = 0; i < 4; ++i) {
                int u = dx[i] + x;
                int v = y + dy[i];
                if(ver(u,v) and dis[x][y] + c[x][y] < dis[u][v]) {
                    dis[u][v] = dis[x][y] + c[x][y];
                    q.push({-dis[u][v], u ,v});
                }
            }
        }
        cout << dis[n - 1][m - 1] + c[n - 1][m - 1] << "\n";
        
    }
    return 0;
}

