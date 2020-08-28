#include <bits/stdc++.h>

using namespace std;

int c[510][510];
int b[510][510];
bool vis[510][510];
int dx[] = {1,1,0,-1,-1,-1,0,1};
int dy[] = {0,-1,-1,-1,0,1,1,1};


int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    memset(vis,false,sizeof vis);
    int n,m; cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> c[i][j];
        }
    }
    int x,y; cin >> x >> y;
    x--,y--;
    int h = c[x][y];
    priority_queue<pair<int,pair<int,int> > > q;
    q.push({-h,{x,y}});
    long long ans = 0;
    while(!q.empty()) {
        int u = q.top().second.first;
        int v = q.top().second.second;
        int d = -q.top().first;
        q.pop();
        vis[u][v]= 1;
        int cur = min(abs(c[u][v]), abs(d));
        if(cur <= b[u][v]) continue;
        b[u][v] = max(b[u][v],cur);
        for (int i = 0; i < 8; ++i) {
            int xx = u + dx[i];
            int yy = v + dy[i];
            if(xx >= 0 and xx < n and yy >= 0 and yy < m 
                    and c[xx][yy] <= 0) {
                q.push({-max(d,c[xx][yy]),{xx,yy}});
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            ans += b[i][j];
    }
    cout << ans << "\n";
    return 0;
}

