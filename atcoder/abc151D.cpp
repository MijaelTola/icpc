#include <bits/stdc++.h>

using namespace std;

char m[22][22];
int d[22][22];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int h,w;

int main() {

    auto check = [] (int x, int y) {
        return x >= 0 and y >= 0 and x < h and y < w and m[x][y] == '.' and d[x][y] == -1;
    };
    auto bfs = [check](int x, int y) {

        queue<pair<int,int> > q;

        for (int i = 0; i < h; ++i)
            for (int j = 0; j < w; ++j)
                d[i][j] = -1;

        q.push({x,y});
        d[x][y] = 0;
        int mx = 0;
        while(!q.empty()) {
            x = q.front().first;
            y = q.front().second;
            q.pop();

            for (int i = 0; i < 4; ++i) {
                int u = dx[i] + x;
                int v = dy[i] + y;
                if(check(u, v)) {
                    d[u][v] = d[x][y] + 1;
                    mx = max(mx, d[u][v]);
                    q.push({u,v});
                }
            }
        }

       
        return mx;
    };
    cin >> h >> w;
    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j)
            cin >> m[i][j];

    int ans = 0;
    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j) {
            if(m[i][j] == '.') {
                ans = max(ans, bfs(i,j));
            }
        }

    cout << ans << "\n";
    return 0;
}

