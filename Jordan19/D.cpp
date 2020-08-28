#include <bits/stdc++.h>

using namespace std;

int m[12][12];
char val[] = {'U', 'D','L','R'};
char mv[12][12];
bool vis[12][12];

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int main() {
    
    m[8][1] = m[8][2] = m[9][1] = -1;
    m[5][5] = m[6][6] = m[5][6] = m[6][5] = -1;
    m[8][9] = m[8][10] = m[9][10] = -1;

    m[2][2] = 1;
    m[2][9] = 1;
    m[9][2] = 1;
    m[9][9] = 1;
    
    int t;
    cin >> t;

    auto ver = [] (int x,int y) {
        return x >= 0 and x < 12 and y >= 0 and y < 12 and !vis[x][y] and m[x][y] != -1;
    };

    while(t--) {
        pair<int,int> way[12][12];
        memset(vis, 0, sizeof vis);
        int x,y;
        cin >> x >> y;
        x--,y--;
        queue<pair<int,int> > q;
        q.push({x,y});
        way[x][y] = {-1, -1};
        pair<int,int> path = {-1, -1};

        while(!q.empty()) {
            x = q.front().first;
            y = q.front().second;
            q.pop();
            if(m[x][y] == 1) {
                path = {x,y};
                break;
            }   

            if(vis[x][y]) continue;
            vis[x][y] = 1;
            for (int i = 0; i < 4; ++i) {
                int u = dx[i] + x;
                int v = dy[i] + y;
                if(ver(u, v)) {
                    way[u][v] = {x,y};
                    mv[u][v] = val[i];
                    q.push({u,v});
                }
            }
        }

        string ans = "";
        while(path != make_pair(-1, -1)) {
            ans += mv[path.first][path.second];
            path = way[path.first][path.second];
        }
        ans.pop_back();
        reverse(ans.begin(), ans.end());
        cout << ans.size() << "\n";
        cout << ans << "\n";
    }
    return 0;
}

