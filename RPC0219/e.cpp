#include <bits/stdc++.h>

using namespace std;

int r,c;
char m[410][410];
int d[410][410];

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

bool ver(int x,int y) {
    return x >= 0 and y >= 0 and x < r and y < c and m[x][y] != '#';
}

int main() {
    for (int i = 0; i < 410; ++i)
        for (int j = 0; j < 410; ++j)
            d[i][j] = 1e9;
    cin >> r >> c;
    int xx,yy;
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j) {
            cin >> m[i][j];
            if(m[i][j] == 'D') 
                xx = i, yy = j;
        }
        
    int x,y;
    cin >> x >> y;
    x--,y--;
    priority_queue<pair<int,pair<int,int> > > q;
    q.push({-1,{x,y}});
    d[x][y] = 1;

    while(!q.empty()) {
        x = q.top().second.first;
        y = q.top().second.second;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int u = dx[i] + x;
            int v = dy[i] + y;
            if(ver(u,v)) {
                if(d[x][y] + (m[u][v] == 'c') < d[u][v]) {
                    d[u][v] = d[x][y] + (m[u][v] == 'c');
                    q.push({-d[u][v],{u,v}});
                }
            }
        }
    }
    
    int ans = 1e9;
    for (int i = 0; i < r; ++i) {
        if(d[i][0] != 0) ans = min(ans, d[i][0]);
        if(d[i][c - 1] != 0) ans = min(ans, d[i][c - 1]);
    }

    for (int i = 0; i < c; ++i) {
        if(d[0][i] != 0) ans = min(ans, d[0][i]);
        if(d[r - 1][i] != 0) ans = min(ans, d[r - 1][i]);
    }
    cout << ans << "\n";

    return 0;
}

